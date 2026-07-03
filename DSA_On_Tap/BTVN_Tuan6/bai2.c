#include "stdio.h"
#include "string.h"

#define MAX_SIZE 100

typedef struct {
    char formula[MAX_SIZE];
    int top;
} stack;

void init_stack(stack *s, char formula[]) {
    s->top = -1;
}

int is_full(stack *s) {
    return s->top == MAX_SIZE - 1;
}

int is_empty(stack *s) {
    return s->top == -1;
}

void push(stack *s, char c) {
    if (is_full(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->formula[s->top] = c;
}

char pop(stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    char value = s->formula[s->top];
    s->top--;
    return value;
}

void check_syntax(char formula[], stack *s, int index[], int *count) {
    int len = strlen(formula);
    *count = 0;
    for (int i=0; i<len; i++) {

        if (formula[i] == '{' || formula[i] == '[' || formula[i] == '(') {
            push(s, formula[i]);

        } else if (formula[i] == '}' || formula[i] == ']' || formula[i] == ')') {
            char open_parenthesis = pop(s);

            if (open_parenthesis == '{' && formula[i] == '}' || open_parenthesis == '[' && formula[i] == ']' || open_parenthesis == '(' && formula[i] == ')') {
                continue;

            } else {
                index[*count] = i;
                (*count)++;
                if (open_parenthesis == '{') {
                    formula[i] = '}';
                } else if (open_parenthesis == '[') {
                    formula[i] = ']';
                } else if (open_parenthesis == '(') {
                    formula[i] = ')';
                }
            }
        }
    }
}

int main() {
    char formula[] = "(1+2)*3+(4*5)";
    stack s;
    int index[100];
    int count = 0;

    init_stack(&s, formula);
    check_syntax(formula, &s, index, &count);

    if (count == 0) {
        printf("No errors\n");
    } else {
        printf("Wrong at: ");
        for (int i=0; i<count; i++) {
            printf("%d ", index[i]);
        }
        printf("\n");
        printf("%s\n", formula);
    }
}

/*
 * Test cases 1:
 *  Wrong at: 8
    [(2+3)*4]+3
 * Test cases 2:
 *  Wrong at: 15 18 21
    {-1+2*[3+5*(1-3):2]-2}
 Test cases 3:
    No errors
 */
