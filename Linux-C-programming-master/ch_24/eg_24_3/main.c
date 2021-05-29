#include <stdio.h>
#include <stdlib.h>
#include "para_allocator.h"

int main(void) {
    unit_t *p = NULL;
    alloc_unit(&p);
    printf("test!\n");
    printf("number: %d\nmsg: %s\n", p->number, p->msg);
    // free_unit(p);
    // printf("Hello");
    // free(p->msg);
    free(p);
    p = NULL;
    return 0;
}
