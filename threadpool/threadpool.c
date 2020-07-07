#include "threadpool.h"
#include <errno.h>

//初始化线程池
void threadpool_init(threadpool_t* pool, int max_thread)
{
  pthread_cond_init(&pool->cond, NULL);
  pthread_mutex_init(&pool->mutex, NULL);
  pool->first = NULL;
  pool->last = NULL;
  pool->counter = 0;
  pool->idle = 0;
  pool->max_thread = max_thread;
  pool->quit = 0;
}

void* routine(void* arg)
{
  threadpool_t* pool = (threadpool_t* )arg;
  int timeout = 0;
  printf("%p thread creat\n", pthread_self());
  while( 1 )
  {
    timeout = 0;
    pthread_mutex_lock(&pool->mutex);
    pool->idle++;//刚开始是一个空闲线程
    while( pool->first == NULL && pool->quit == 0 )
    {
      struct timespec abstime;
      clock_gettime(CLOCK_REALTIME, &abstime);
      abstime.tv_sec += 5;
      int ret = pthread_cond_timedwait(&pool->cond, &pool->mutex, &abstime);
      if(ret == ETIMEDOUT)
      {
        timeout = 1;
        printf("%p thread timeout\n", pthread_self());
        break;
      }
    }
    pool->idle--;//得到任务就不是一个空闲线程

    if( pool->first != NULL ){//有任务，执行任务回调函数
      task_t* tmp = pool->first;
      pool->first = tmp->_next;
      pthread_mutex_unlock(&pool->mutex);
      tmp->run(tmp->arg);
      free(tmp);
      pthread_mutex_lock(&pool->mutex);
    }
    if(pool->first == NULL && timeout == 1){
      pool->counter--;
      pthread_mutex_unlock(&pool->mutex);
      break;
    }

    if( pool->first == NULL && pool->quit == 1 ){
      pool->counter--;
      if( pool->counter == 0 ){
        //此时为最后一个退出的线程
        //通知threadpool_destroy中的pthread_cond_wait
        pthread_cond_signal(&pool->cond);
      }
      pthread_mutex_unlock(&pool->mutex);
      break;
    }

    pthread_mutex_unlock(&pool->mutex);
  }
  printf("%p thread exit\n", pthread_self());

}

//向线程池中添加任务
void threadpool_add_task(threadpool_t* pool, void* (*run)(void*), void* arg)
{
  task_t* new_task = (task_t*)malloc(sizeof(task_t));
  new_task->run = run;
  new_task->arg = arg;

  //任务队列中添加任务
  pthread_mutex_lock(&pool->mutex);
  if( pool->first == NULL ){
    pool->first = new_task;
  }else{
    pool->last->_next = new_task;
  }
  pool->last = new_task;

  if( pool->idle > 0 ){
  //如果有空闲线程，则直接唤醒空闲进程执行当前任务
    pthread_cond_signal(&pool->cond);

  }else if( pool->counter < pool->max_thread ){
  //如果没有空闲线程可以执行当前任务，并且没有达到上限，则创建新线程
    pthread_t tid;
    pthread_create(&tid, NULL, routine, pool);
    pool->counter++;
  }
  pthread_mutex_unlock(&pool->mutex);
}

//销毁线程池
void threadpool_destroy(threadpool_t* pool)
{
  if( pool->quit == 1 )//判断是否有其他进程写入退出码
    return;

  pthread_mutex_lock(&pool->mutex);
  printf("我要杀了线程池\n");
  pool->quit = 1;
  if( pool->counter > 0 ){
    //当线程池中空闲线程大于0时，
    //pthread_cond_broadcast唤醒所有阻塞在pthread_cond_timewait上的线程
    if( pool->idle > 0 )
      //如果销毁线程池时，线程池中的线程正在执行任务
      //不会收到broadcast的通知
      pthread_cond_broadcast(&pool->cond);
    while( pool->counter > 0 )
      pthread_cond_wait(&pool->cond, &pool->mutex);
  }
  pthread_mutex_unlock(&pool->mutex);
}

