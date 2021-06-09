#include "Union.h"

void Union(SqList * La, SqList Lb) {
    int b_len;
    int i;
    ElemType e;
    b_len = Lb.length;

    for(i = 0; i < b_len; ++i) {
        GetElem(Lb, i, &e);
        int tmp = LocateElem(*La, e, cmp);
        if (tmp == La->length || cmp((La->elem)[tmp], e) != 0) {
            ListInsert(La, tmp, e);
        }
    }
}

int cmp(ElemType e1, ElemType e2) {
    if (e1 < e2)
        return -1;
    else if (e1 == e2)
        return 0;
    else
        return 1;
}
