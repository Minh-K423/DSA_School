#include "stdio.h"
#include "string.h"

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
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

void push(stack *s, char value) {
    if (is_full(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

char pop(stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return '\0';
    }
    char value = s->data[s->top];
    s->top--;
    return value;
}

//Brute force approach
//
//
void reverse_polish_notation(char expression[], stack *s, int length, char posfix[]) {
    int posfix_index = 0;
    for (int i = 0; i < length; i++) {
        if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/') {
            posfix[posfix_index] = expression[i];
            posfix_index++;
        } else {
            if (is_empty(s)) {
                push(s, expression[i]);
            } else if (
                (expression[i] == '*' || expression[i] == '/') && (s->data[s->top] == '+' || s->data[s->top] == '-')) {
                push(s, expression[i]);
            } else {
                while (((s->data[s->top] == '*' || s->data[s->top] == '/') && (expression[i] == '+' || expression[i] == '-')) ||

                    ((s->data[s->top] == '*' || s->data[s->top] == '/') && (expression[i] == '*' || expression[i] == '/')) ||

                    ((s->data[s->top] == '+' || s->data[s->top] == '-') && (expression[i] == '+' || expression[i] == '-'))) {
                    //Because the problem specify that there will be no brackets, we can safely pop all elements in the stack without using while loop
                    char c = pop(s);
                    posfix[posfix_index] = c;
                    posfix_index++;
                }
                push(s, expression[i]);
            }
        }
    }
    //If there's anything left, insert them to the array
    while (!is_empty(s)) {
        char c = pop(s);
        posfix[posfix_index] = c;
        posfix_index++;
    }
}

int set_priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void reverse_polish_notation_optimized(char expression[], stack *s, int length, char posfix[]) {
    int posfix_index = 0;
    for (int i=0; i <= length; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') { //You can specify it by using ASCII
            posfix[posfix_index] = expression[i];
            posfix_index++;
        } else {
            while (!is_empty(s) && set_priority(s->data[s->top]) >= set_priority(expression[i])) {
                char c = pop(s);
                posfix[posfix_index] = c;
                posfix_index++;
            }
            push(s, expression[i]);
        }
    }
}

int calculate_operator(char operator, int num1, int num2) {
    if (operator == '+') {
        return num1 + num2;
    } else if (operator == '-') {
        return num1 - num2;
    } else if (operator == '*') {
        return num1 * num2;
    } else if (operator == '/') {
        return num1 / num2;
    }
    return 0;
}

int calculate_posfix(char posfix[]) {
    int total = 0;
    stack s;
    init_stack(&s);
    for (int i = 0; i < strlen(posfix); i++) {
        if (posfix[i] >= '0' && posfix[i] <= '9') {
            push(&s, posfix[i]);
        } else {
            int num1 = pop(&s) - '0';
            int num2 = pop(&s) - '0';
            int result = calculate_operator(posfix[i], num1, num2);
            push(&s, result + '0');
        }
    }
    total = (int) pop(&s) - '0';
    return total;
}

int main() {
    char expression[MAX_SIZE] = "2+3*4-5";
    char posfix[MAX_SIZE];

    printf("Expression: %s\n", expression);
    int expresion_length = strlen(expression);

    stack s;
    init_stack(&s);
    reverse_polish_notation_optimized(expression, &s, expresion_length, posfix);
    printf("Postfix: %s\n", posfix);
    printf("Result: %d\n", calculate_posfix(posfix));

    return 0;
}

/*
 * Test case 1:
 * Expression: 2+3*4-5
 * Postfix: 234*+5-
 *
 * Test case 2:
 * Expression: 9+8-7*6/2
 * Postfix: 98+76*2/-
 *
 * Test case 3:
 * Expression: 1*2+3*4-5*6/5*3/9+6/3*5
 * Postfix: 12*34*+56*-53*./+63/5*
 */
