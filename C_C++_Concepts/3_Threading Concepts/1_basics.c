#include<stdio.h>
#include<pthread.h>

void *fun(void* arg)
{
    printf("%s\n", (char*)arg);
}

int main()
{
    pthread_t thread;
    char msg[256];
    scanf("%s",&msg);

    pthread_create(&thread,NULL,fun,msg);
    pthread_join(thread, NULL);

    return 0;
}