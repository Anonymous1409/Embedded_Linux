#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define THREAD_COUNT 10

int shared_counter = 0;
int fast_counter = 0;

pthread_mutex_t mutex;
sem_t semaphore;
pthread_spinlock_t spinlock;

// Thread function
void* worker(void* arg) 
{
    int id = *(int*)arg;

    sem_wait(&semaphore);
    printf("Thread %d entered (semaphore)\n", id);
    sleep(1);

    pthread_mutex_lock(&mutex);
    shared_counter++;
    printf("Thread %d incremented shared_counter to %d (mutex)\n", id, shared_counter);
    pthread_mutex_unlock(&mutex);

    pthread_spin_lock(&spinlock);
    fast_counter++;
    pthread_spin_unlock(&spinlock);

    printf("Thread %d finished (spinlock fast_counter = %d)\n", id, fast_counter);

    sem_post(&semaphore);

    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&semaphore, 0, 5);
    pthread_spin_init(&spinlock, 0);

    for (int i = 0; i < THREAD_COUNT; ++i) 
    {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&threads[i], NULL, worker, id);
    }

    for (int i = 0; i < THREAD_COUNT; ++i) 
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nFinal shared_counter = %d\n", shared_counter);
    printf("Final fast_counter = %d\n", fast_counter);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&semaphore);
    pthread_spin_destroy(&spinlock);

    return 0;
}

//gcc 7_synchronization.c  -o a.exe