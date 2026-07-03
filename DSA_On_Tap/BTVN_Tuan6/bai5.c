#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    q->data[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

void sort_descending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int cross_bridge(Queue *q, int k) {
    int total = 0;
    while (!is_empty(q)) {
        int group_max = dequeue(q);
        for (int i = 1; i < k; i++) {
            if (!is_empty(q)) dequeue(q);
        }
        total += group_max;
    }
    return total;
}

int main() {
    int k, n;
    scanf("%d", &k);
    scanf("%d", &n);

    int times[MAX_SIZE];
    for (int i = 0; i < n; i++)
        scanf("%d", &times[i]);

    sort_descending(times, n);

    Queue q;
    init_queue(&q);
    for (int i = 0; i < n; i++)
        enqueue(&q, times[i]);

    printf("Tong: %d\n", cross_bridge(&q, k));
    return 0;
}

/*
 * 2
 4
 1 2 5 4
 Tong: 7
 */
