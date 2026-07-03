#include <stdio.h>
#include "stdlib.h"
#include <time.h>


#define MAX_SIZE 100

void initializeArray (int arr[], int length, int min, int max) {
    for (int i = 0; i<length; i++)
        arr[i] = min + rand()%(max - min + 1);

    if (length > 0 && min <= 1 && max >= 1) {
            int random_index = rand() % length;
            arr[random_index] = 1;
    }
}

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void init_stack(stack *s) {
    s->top = -1;
}

int is_full(stack *s) {
    return s->top == MAX_SIZE - 1;
}

int is_empty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int value) {
    if (is_full(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

void recursive_push(stack *s, int arr[], int length) {
    if (arr[length] == 1) return; //Base case: stop recursion when value is 1
    push(s, arr[length]);
    recursive_push(s, arr, length - 1);
}

void recursive_pop(stack *s, int *total) {
    if (!is_empty(s)) {
        int value = pop(s);
        *total += value;
        printf("%d ", value);
        recursive_pop(s, total);
    }
}

int main() {
    srand(time(NULL));
    int arr[MAX_SIZE];
    int length = 20;

    initializeArray(arr, MAX_SIZE, 0, 10);

    printf("Array: ");
    for (int i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    stack s;
    init_stack(&s);
    int total = 0;

    printf("Pushing array elements onto stack...\n");
    recursive_push(&s, arr, length - 1);
    printf("Popping stack elements...\n");
    recursive_pop(&s, &total);
    printf("\nTotal: %d\n", total);

    return 0;
}
