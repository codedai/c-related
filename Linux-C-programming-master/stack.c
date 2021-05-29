#include "stack.h"

char stack[512];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int is_empty() {
    return top == -1;
}