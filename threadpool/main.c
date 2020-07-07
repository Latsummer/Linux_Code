#include "threadpool.h"

void* myFun(void* arg){
  int id = *(int*)arg;
  free(arg);
  printf("id = %d, thread_id = %p, working!\n", id, pthread_self());
  sleep(5);
  printf("id = %d, thread_id = %p, DONE!\n", id, pthread_self());
}

int main()
{
  threadpool_t pool;
  threadpool_init(&pool, 3);
  int i = 0;
  for( i = 0; i < 5; i++ ){
    int* p = (int*)malloc(sizeof(int));
    *p = i;
    threadpool_add_task(&pool, myFun, (void*)p);
  }
  threadpool_destroy(&pool);
}
