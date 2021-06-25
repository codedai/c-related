#include "MergeSqList.h"

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int cmp (ElemType e1, ElemType e2) {
    return e1 - e2;
}

int main (int argc, char *args[]) {
    ElemType a[4] = {1, 2, 3, 4};
    ElemType b[7] = {0, 1, 5, 3, 9, -1, 0};

    SqList La, Lb, Lc;
    int i;

    InitList(&La);
    for (i = 0; i < 4; ++i) {
        ListInsertU(&La, a[i], cmp);
    }
    ListTraverse(La, PrintElem);

    InitList(&Lb);
    for (i = 0; i < 7; ++i) {
        ListInsertU(&Lb, b[i], cmp);
    }
    ListTraverse(Lb, PrintElem);

    MergeSqList(La, Lb, &Lc);
    ListTraverse(Lc, PrintElem);

    DestoryList(&La);
    DestoryList(&Lb);
    DestoryList(&Lc);

    return 0;
}
