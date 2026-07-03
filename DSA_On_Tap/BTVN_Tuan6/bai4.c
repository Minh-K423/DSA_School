#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int head;
    int tail;
    int data[MAX_SIZE];
} queue;

void initializequeue(queue *q) {
    q->head = -1;
    q->tail = 0;
}

int isEmpty(queue *q) {
    return (q->head == q->tail - 1);
}

int isFull(queue *q) {
    return (q->tail == MAX_SIZE);
}

void put(queue *q, int value) {
    if (isFull(q)) {
        printf("queue is full\n");
        return;
    }
    q->data[q->tail] = value;
    q->tail++;
}

void cancelRegistration(queue *q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }
    q->head++;
}

int peek(queue *q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    return q->data[q->head + 1];
}

void displayQueue(queue *q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }

    printf("Current queue: ");
    for (int i = q->head + 1; i < q->tail; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    queue q;
    initializequeue(&q);
    put(&q, 10);
    put(&q, 20);
    put(&q, 30);
    displayQueue(&q);
    cancelRegistration(&q);
    displayQueue(&q);
    return 0;
}
