#include "MergeSqList.h"

void MergeSqList(SqList La, SqList Lb, SqList * Lc) {
    int a_len, b_len;
    ElemType * a_elem, *b_elem, *c_elem;
    int i, j;
    if(InitListWithSpace(Lc, a_len + b_len) == ERROR)
        return;
    
    i = 0, j = 0;
    a_elem = La.elem, b_elem = Lb.elem;
    a_len = La.length, b_len = Lb.length;
    c_elem = Lc->elem;

    while (i < a_len && j < b_len) {
        if (a_elem[i] < b_elem[j])
            *c_elem++ = a_elem[i++];
        else
            *c_elem++ = b_elem[j++];
    }

    while (i < a_len) *c_elem++ = a_elem[i++];
    while (j < b_len) *c_elem++ = b_elem[j++];

    Lc->length = a_len + b_len;
}


void MergeSqList_2(SqList La, SqList Lb, SqList * Lc) {
    ;
}
