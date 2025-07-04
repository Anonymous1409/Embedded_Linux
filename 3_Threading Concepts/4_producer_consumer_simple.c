#include<stdio.h>

#define SIZE 5  // Buffer size

int buffer[SIZE];
int in = 0;     // Write index
int out = 0;    // Read index
int count = 0;  // Items in buffer

// Producer adds an item to the buffer
void produce(int item) {
    if (count == SIZE) {
        printf("Buffer full. Cannot produce %d\n", item);
        return;
    }

    buffer[in] = item;
    in = (in + 1) % SIZE;
    count++;
    printf("Produced: %d\n", item);
}

// Consumer removes an item from the buffer
int consume() {
    if (count == 0) {
        printf("Buffer empty. Nothing to consume.\n");
        return -1;
    }

    int item = buffer[out];
    out = (out + 1) % SIZE;
    count--;
    printf("Consumed: %d\n", item);
    return item;
}

int main() {
    // Produce some items
    for (int i = 0; i < 10; i++) {
        produce(i);
    }

    // Consume all items
    for (int i = 0; i < 10; i++) {
        consume();
    }

    return 0;
}
//gcc 4_producer_consumer_simple.c -o a.exe