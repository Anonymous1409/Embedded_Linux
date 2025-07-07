#include<stdio.h>
#include<pthread.h>

void* add(void*arg)
{
    int*a = (int*)arg;
    printf("Addition: %d\n", a[0] + a[1]);
    return NULL;
}

void* sub(void*arg)
{
    int*a = (int*)arg;
    printf("Subtraction: %d\n", a[0] - a[1]);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int numbers[2] = {10, 5};

    // Create threads for addition and subtraction
    pthread_create(&thread1, NULL, add, (void*)numbers);
    pthread_create(&thread2, NULL, sub, (void*)numbers);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
//gcc 2_calculator.c -o a.exe

/*
Synchronization problem

#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < 100000000; i++) {
        counter++;  // Not thread-safe
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter: %d\n", counter);
    return 0;
}

*/
