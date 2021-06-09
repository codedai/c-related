#include <stdio.h>
#include "Union.h"
#include "SqList.h"

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main (int argc, char * argv[]) {
    ElemType a[5] = {1, 2, 3, 5, 9};
    ElemType b[7] = {-1, 0, 4, 6, 7, 9, 10};
    int i;

    SqList la, lb;
    InitList(&la);
    for(i = 0; i < 5; ++i) 
        ListInsert(&la, i, a[i]);

    InitList(&lb);
    for(i = 0; i < 7; ++i)
        ListInsert(&lb, i, b[i]);

    printf("la = ");
    ListTraverse(la, PrintElem);

    printf("lb = ");
    ListTraverse(lb, PrintElem);

    printf("la = la U lb = ");
    Union(&la, lb);
    ListTraverse(la, PrintElem);

    DestoryList(&la);
    DestoryList(&lb);

    return 0;
}
