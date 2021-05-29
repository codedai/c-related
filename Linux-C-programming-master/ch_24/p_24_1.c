#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t c = 0;
    while(1) {
        malloc(1);
        printf("%d-th byte\n", c++);
    }
    return 0;
}