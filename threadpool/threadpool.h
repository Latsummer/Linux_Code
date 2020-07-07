#ifndef  __THREADPOOL_H__
#define  __THREADPOOL_H__
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

typedef struct task{
  void* (*run)(void* arg);//任务的回调函数
  void* arg;//回调参数的参数
  struct task* _next;
}task_t;

typedef struct threadpool{
  pthread_cond_t cond;
  pthread_mutex_t mutex;
  task_t* first;//任务队列对头
  task_t* last;//队尾
  int counter;//线程池中还有多少线程
  int idle;//空闲线程个数
  int max_thread;//线程池中线程的阈值
  int quit;//线程的销毁标志，默认0

}threadpool_t;

//初始化线程池
void threadpool_init(threadpool_t* pool, int max_thread);

//向线程池中添加任务
void threadpool_add_task(threadpool_t* pool, void* (*run)(void*), void* arg);

//销毁线程池
void threadpool_destroy(threadpool_t* pool);

#endif //__THREADPOOL_H__
