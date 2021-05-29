#include <stdlib.h>
#include <stdio.h>
#include "my_sort.h"

/* Byte-wise swap two items of size SIZE. */
#define SWAP(a, b, size)\
    do {\
        size_t __size = (size);\
        char * __a = (a), *__b = (b);\
        do {\
            char __tmp = *__a;\
            *__a++ = *__b;\
            *__b++ = __tmp;\
        } while (--__size > 0);\
    } while (0)

void my_insertion_sort(void * const data, int num, cmp_t cmp, size_t size) {
    int i, j;
    char * base_ptr = (char *) data;
    for (j = 1; j < num; j++) {
        i = j - 1;
        while (i >= 0 && cmp((void *)&(base_ptr[(i+1)*size]), (void *)&base_ptr[i*size]) < 0) {
            SWAP((&base_ptr[i*size]), (&(base_ptr[(i+1)*size])), size);
            i--;
        }
    }
}

int __binary_search(char * const data, void * targ, int start, int end, cmp_t cmp, size_t size) {
    if (start > end) return -1;
    int mid = (start + end) / 2, res;
    res = cmp((void*)&data[mid*size], targ);
    if (res == 0) return mid;
    else if(res > 0) return __binary_search(data, targ, start, mid-1, cmp, size);
    else return __binary_search(data, targ, mid+1, end, cmp, size);
}

int my_binary_search(void * const data, void * targ, int num, cmp_t cmp, size_t size) {
    if (targ == NULL) return -1;
    else {
        char * base_ptr = (char *) data;
        return __binary_search(base_ptr, targ, 0, num, cmp, size);
    } 
}