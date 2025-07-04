#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>

#define SIZE 10

int p_ctr, c_ctr, count;
int buffer[SIZE];
pthread_mutex_t lock;  // 🔐 Mutex for synchronizing access to shared resources

void* produce(void* arg)
{
    int val = 1;
    while (1)
    {
        sleep(1);  // simulate delay

        pthread_mutex_lock(&lock);  // 🔒 Lock before accessing shared state

        if (count == SIZE)
            printf("Can't produce (buffer full)\n");
        else
        {
            buffer[p_ctr % SIZE] = val;
            printf("%d produced\n", val);
            p_ctr = (p_ctr + 1) % SIZE;
            count++;
            val++;
        }

        pthread_mutex_unlock(&lock);  // 🔓 Unlock after done

    }
    return NULL;
}

void* consume(void* arg)
{
    while (1)
    {
        sleep(1);  // simulate delay

        pthread_mutex_lock(&lock);  // 🔒 Lock before accessing shared state

        if (count == 0)
            printf("Can't consume (buffer empty)\n");
        else
        {
            int item = buffer[c_ctr % SIZE];
            printf("%d consumed\n", item);
            c_ctr = (c_ctr + 1) % SIZE;
            count--;
        }

        pthread_mutex_unlock(&lock);  // 🔓 Unlock after done
    }
    return NULL;
}

int main()
{
    pthread_t p, c;

    // 🧰 Initialize state
    count = 0;
    p_ctr = c_ctr = 0;
    pthread_mutex_init(&lock, NULL);  // 🛠 Initialize mutex

    // 🚀 Create threads
    pthread_create(&p, NULL, produce, NULL);
    pthread_create(&c, NULL, consume, NULL);

    // ⏳ Wait for threads
    pthread_join(p, NULL);
    pthread_join(c, NULL);

    // 🧹 Clean up
    pthread_mutex_destroy(&lock);
    return 0;
}


// gcc 5_pc_threading.c -o a.exe