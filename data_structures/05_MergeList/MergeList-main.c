#include "MergeList.h"

void PrintElem(ElemType e) {
    printf("%d, ", e);
}

int cmp(ElemType e1, ElemType e2) {
    return e1 - e2;
}

int main (int argc, char ** argv) {
    LinkedList La, Lb, Lc;

    CreateList_Tail(&La, 8, "la_list.txt");
    ListTraverse(La, PrintElem);
    CreateList_Tail(&Lb, 8, "lb_list.txt");
    ListTraverse(Lb, PrintElem);

    MergeList(&La, &Lb, &Lc);

    ListTraverse(Lc, PrintElem);

    DestoryList(&La);
    DestoryList(&Lb);
    DestoryList(&Lc);

    return 0;
}
