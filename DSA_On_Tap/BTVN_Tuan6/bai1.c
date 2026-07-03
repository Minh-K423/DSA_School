#include "stdio.h"
#include "string.h"
#define MAX_SIZE 100

// Reverse a string using array
void array_reverse(char string[], int n) {
    for (int i = 0; i < n / 2; i++) {
        char temp = string[i];
        string[i] = string[n - i - 1];
        string[n - i - 1] = temp;
    }
}

// Reverse a string using stack
typedef struct {
    char *str;
    int top;
} string;

void init_string(string *s, char str[]) {
    s->top = -1;
    s->str = str;
}

int stack_is_full(string *s) { //Check if the stack is full
    return s->top == MAX_SIZE - 1;
}

int stack_is_empty(string *s) { //Check if the stack is empty
    return s->top == -1;
}

void string_push(string *s, char value) {
    if (stack_is_full(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->str[s->top] = value;
}

char string_pop(string *s) {
    if (stack_is_empty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    char value = s->str[s->top];
    s->top--;
    return value;
}

void stack_reverse(string *s, char string[], int size) {
    for (int i=0; i<size; i++) {
        string_push(s, string[i]);
    }
}

int main() {
    char str1[] = "gnuhnoomalhpoahtvh";
    char str2[] = "gnuhnoomalhpoahtvh";
    int n = strlen(str1);

    array_reverse(str1, n);
    printf("%s\n", str1);

    string s;
    init_string(&s, str2);
    stack_reverse(&s, str2, n);
    for (int i=0; i<n; i++) {
        printf("%c", string_pop(&s));
    }
    printf("\n");

    return 0;
}

/*
 Test case 1:
 fedcba
 fedcba

 Test case 2:
 654321
 654321

 Test case 3:
 hvthaophlamoonhung
 hvthaophlamoonhung
 */
