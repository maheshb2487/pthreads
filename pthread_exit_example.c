#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void* thread_func(void *arg)
{
 int *ret = malloc(sizeof(int));
 *ret = 300;
 printf("Hi From thread func\n");
 printf("Address of ret : %p\n",ret);
 pthread_exit(ret);
}

void main()
{
 pthread_t p_thread_id_1;
 int ret;
 ret = pthread_create(&p_thread_id_1,
                      NULL,
                      thread_func,
                      NULL);
 if(ret == 0){
   printf("pthread_create success\n");
 }else{
   printf("pthread create failed\n");
 }
 int *thread_ret = NULL;
 pthread_join(p_thread_id_1,(void **)&thread_ret);
 printf("child thread returned : %d\n",*thread_ret);
 printf("Address of thread_ret : %p\n",thread_ret);
}
