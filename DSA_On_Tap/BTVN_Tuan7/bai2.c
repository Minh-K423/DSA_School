#include "stdio.h"

#define MAX_SIZE 100

//1.
void print_array(int arr[], int index, int n) {
    if (index == n-1) {
        printf("%d ", arr[index]);
        return;
    }
    printf("%d ", arr[index]);
    print_array(arr, index + 1, n);
}

//2.
int linear_search(int arr[], int index, int n, int value) {
    if (index == n) {
        return -1;
    }
    if (arr[index] == value) {
        return index;
    }
    return linear_search(arr, index + 1, n, value);
}

//3.
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (!is_full(s)) {
        s->arr[++s->top] = value;
    } else {
        printf("Stack is full\n");
    }
}

int pop(Stack *s) {
    if (!is_empty(s)) {
        return s->arr[s->top--];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int recursive_pop(Stack *s) {
    if (!is_empty(s)) {
        int value = pop(s);
        printf("%d ", value);
        return recursive_pop(s);
    }
    return 0;
}

//4.
int recursive_binary_search(int arr[], int left, int right, int value) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == value) {
        return mid;
    }
    if (arr[mid] > value) {
        return recursive_binary_search(arr, left, mid - 1, value);
    }
    return recursive_binary_search(arr, mid + 1, right, value);
}

int main() {
    //1.
    int arr[] = {1,2,3,4,5,6,7};
    print_array(arr, 0, 7);
    printf("\n");

    //2.
    int index = linear_search(arr, 0, 7, 5);
    printf("Index 1: %d\n", index);

    //3.
    Stack s;
    init_stack(&s);

    for (int i = 0; i < 10; i++) {
        push(&s, i);
    }

    recursive_pop(&s);
    printf("\n");
    //4.
    int index2 = recursive_binary_search(arr, 0, 7, 5);
    printf("Index 2: %d\n", index2);
}
