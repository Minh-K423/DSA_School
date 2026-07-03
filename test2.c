#include "stdio.h"
#include "stdlib.h"
#include <time.h>

#define MAX_SIZE 999

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

int is_empty(stack *s) {
    return s->top == -1;
}

int is_full(stack *s) {
    return s->top == MAX_SIZE - 1;
}

void init_stack(stack *s) {
    s->top = -1;
}

void push(stack *s, int value) {
    if (is_full(s)) {
        return;
    }
    s->data[++s->top] = value;
}

void pop(stack *s) {
    if (is_empty(s)) {
        return;
    }
    s->top--;
}

void insertStack(stack *s, int length, int * recursion_count) {

    if (length < 0) return;

    int k = 1 + rand()%(10 - 1 + 1);

    if (k != 1 && k % 2 != 0) {
        pop(s);
    } else if (k % 2 == 0  && k != 10) {
        push(s, k);
    } else if (k == 10 || k == 1) {
        length = length / 2;
        for (int i = 0; i < length; i++) {
            pop(s);
        }
    }
    (*recursion_count)++;
    insertStack(s, length - 1, recursion_count);
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int k = 1 + rand()%(10 - 1 + 1);

    int arr[MAX_SIZE];
    int n;
    printf("Hay nhap chieu dai cua mang: "); scanf("%d", &n);
    if (n<2) {
        printf("Mang phai co chieu dai lon hon hoac bang 2.\n");
        while (n<2) {
            printf("Hay nhap lai chieu dai cua mang: ");
            scanf("%d", &n);
        }
    }
    for (int i=0; i<n; i++) {
        printf("Hay nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

    stack s;
    init_stack(&s);
    for (int i = 0; i < 3; i++) {
        push(&s, arr[i]);
    }
    int recursion_count = 0;
    insertStack(&s, 3, &recursion_count);
    printf("So lan goi ham de quy la: %d\n", recursion_count);
}

/*Hay nhap chieu dai cua mang: 3
Hay nhap phan tu thu 0: 2
Hay nhap phan tu thu 1: 5
Hay nhap phan tu thu 2: 7
So lan goi ham de quy la: 3 */
