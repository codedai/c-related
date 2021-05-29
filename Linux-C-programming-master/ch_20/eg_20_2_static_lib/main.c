#include <stdio.h>
#include "stack.h"

int main (void) {
    push('a');
    push('b');
    push('c');
    while (!is_empty()) {
        putchar(pop());
        printf("Hello world");
    }
    putchar('\n');
    return 0;
}