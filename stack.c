#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int *data;
    int top;
    int size;
} Stack;

void init(Stack *s, int size) {
    s->data = (int *)malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
}

void push(Stack *s, int value) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->size - 1;
}

int main() {
    Stack s;
    init(&s, 10);
    push(&s, 1);
    push(&s, 2);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    return 0;
}
