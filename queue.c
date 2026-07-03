#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

void init(Queue *q, int size) {
    q->data = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->size = size;
}

void push(Queue *q, int value) {
    if (q->rear == q->size) {
        return;
    }
    q->data[q->rear++] = value;
}

int pop(Queue *q) {
    if (q->front == q->rear) {
        return -1;
    }
    return q->data[q->front++];
}

int main() {
    Queue q;
    init(&q, 10);
    push(&q, 1);
    push(&q, 2);
    printf("%d\n", pop(&q));
    printf("%d\n", pop(&q));
    printf("%d\n", pop(&q));
    return 0;
}
