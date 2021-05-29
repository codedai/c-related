#include <stdio.h>
#include "my_sort.h"

int cmp_int (void * a, void * b) {
    int __a = *(int*)a, __b = *(int*)b;
    return __a - __b;
}

int main(void) {
    int list[7] = {
        3, 5, 1, 4, 2, 7, 0
    };
    for (int i=0; i < 7; i++) {
        printf("%d ", list[i]);
    }
    putchar('\n');
    my_insertion_sort((void *) list, 7,  cmp_int, sizeof(int));
    for (int i=0; i < 7; i++) {
        printf("%d ", list[i]);
    }
    putchar('\n');
    int aim = 7;
    printf("%d\n ", my_binary_search((void*) list, (void *)&aim, 7, cmp_int, sizeof(int)));

    return 0;
}