#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* square(void* arg)
{
    int *p=(int*)arg;
    int num=*p;
    printf("%d\n",num);
    int *res = malloc(sizeof(int));
    *res = num * num;

    pthread_exit(res);
}

int main()
{
    pthread_t t;

    int num=5;
    void* res;

    pthread_create(&t,NULL,square,&num);
    pthread_join(t,&res);

    printf("Square of %d is %d\n", num, *(int*)res);
    free(res);
}
//gcc 3_thread_with_return_value.c -o a.exe