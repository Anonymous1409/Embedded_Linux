#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 10

int buffer[SIZE];
int p_ctr = 0, c_ctr = 0, count = 0;

pthread_mutex_t lock;
pthread_cond_t not_full;
pthread_cond_t not_empty;

void* produce(void* arg)
{
    int val = 1;
    while (1)
    {
        pthread_mutex_lock(&lock);

        while (count == SIZE) 
        {
            printf("Buffer full, producer waiting...\n");
            pthread_cond_wait(&not_full, &lock);
        }

        buffer[p_ctr] = val;
        printf("%d produced\n", val);
        p_ctr = (p_ctr + 1) % SIZE;
        count++;
        val++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&lock);

        sleep(1);
    }
    return NULL;
}

void* consume(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        while (count == 0) 
        {
            printf("Buffer empty, consumer waiting...\n");
            pthread_cond_wait(&not_empty, &lock);
        }

        int item = buffer[c_ctr];
        printf("%d consumed\n", item);
        c_ctr = (c_ctr + 1) % SIZE;
        count--;

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&lock);

        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&producer_thread, NULL, produce, NULL);
    pthread_create(&consumer_thread, NULL, consume, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}

// gcc 6_pc_threading_conditional.c -o a.exe