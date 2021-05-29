#include "generics.h"

void * max(void * data[], int num, cmp_t cmp) {
    int i;
    void * tmp = data[0];
    for (i=1; i < num; i++) {
        if (cmp(tmp, data[i]))
            tmp = data[i];
    }
    return tmp;
}