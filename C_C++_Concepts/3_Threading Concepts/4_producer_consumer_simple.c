#include<stdio.h>

#define SIZE 5          // Buffer size

int buffer[SIZE];
int write_idx = 0;      // Write index
int read_idx = 0;       // Read index
int count = 0;          // Items in buffer


void produce(int item) 
{
    if (count == SIZE) 
    {
        printf("Buffer full. Cannot produce %d\n", item);
        return;
    }

    buffer[write_idx] = item;
    write_idx = (write_idx + 1) % SIZE;
    count++;
    printf("Produced: %d\n", item);
}

int consume() 
{
    if (count == 0) 
    {
        printf("Buffer empty. Nothing to consume.\n");
        return -1;
    }

    int item = buffer[read_idx];
    read_idx = (read_idx + 1) % SIZE;
    count--;
    printf("Consumed: %d\n", item);
    return item;
}

int main() {
    for (int i = 0; i < 10; i++)
        produce(i);

    for (int i = 0; i < 10; i++)
        consume();

    return 0;
}
//gcc 4_producer_consumer_simple.c -o a.exe