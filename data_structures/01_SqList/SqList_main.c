#include <stdio.h>
#include "SqList.h"

int Cmp(ElemType data, ElemType e) {
    if (data == e)
        return 0;
    return data > e ? 1 : -1;
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(int argc, char args[]) {
    SqList L;

    int i;
    ElemType e;

    printf("InitList ....\n");
    if(InitList(&L) == ERROR){
        printf("Initiate faild...\n");
        return 1;
    }
    PressEnterToContinue(debug);

    printf("ListEmpty ....\n");
    if (ListEmpty(L) == TRUE)
        printf("L is empty...\n");
    else
        printf("L is not empty...\n");
    PressEnterToContinue(debug);

    printf("ListInsert ...\n");
    for (i = 0; i < 8; i++) {
        printf("Insert %d-th postion L the number %d...\n", i, i * i);
        ListInsert(&L, i, i * i);
    }
    PressEnterToContinue(debug);

    printf("ListTraverse ....\n");
    ListTraverse(L, PrintElem);
    PressEnterToContinue(debug);

    printf("ListLength...\n");
    printf("The length of L is %d...\n", ListLength(L));
    PressEnterToContinue(debug);

    printf("ListDelete...\n");
    {
        printf("Before delete...\n");
        ListTraverse(L, PrintElem);
        printf("We delete the 6-th element...\n");

        if (ListDelete(&L, 6, &e) == OK) {
            printf("Success, the deleted element is: %d\n", e);
        } else {
            printf("Failed, the 6-th element does not exist!\n");
        }

        printf("After delete...\n");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);

    printf("GetElem ... \n");
    GetElem(L, 4, &e);
    printf("The 4-th element in L is %d\n", e);
    PressEnterToContinue(debug);

    printf("LocateElem ...\n");
    i = LocateElem(L, 7, Cmp);
    printf("The first element bigger than 7 is %d\n", L.elem[i]);
    PressEnterToContinue(debug);
    printf("PriorElem ....\n");
    {
        ElemType cur_e = 9;

        if (PriorElem(L, cur_e, &e, Cmp) == OK)
            printf("The element that behind %d is %d.\n", cur_e, e);
        else
            printf("Not found.\n");
    }
    PressEnterToContinue(debug);
    
    printf("NextElem ....\n");
    {
        ElemType next_e = 9;
    
        if (NextElem(L, next_e, &e, Cmp) == OK)
            printf("The element that Prior %d is %d.\n", next_e, e);
        else
            printf("Not found.\n");
    }
    PressEnterToContinue(debug);

    printf("ClearList....\n");
    {
        printf("Before clear...");
        if(ListEmpty(L) == TRUE)
            printf("L is empty..\n");
        else
            printf("L is not empty...\n");

        ClearList(&L);

        printf("After clear...");
        if(ListEmpty(L) == TRUE)
            printf("L is empty..\n");
        else
            printf("L is not empty...\n");
    }
    PressEnterToContinue(debug);


    printf("DestroyList....\n");
    {
        printf("Before clear...");
        if(L.elem != NULL)
            printf("L is empty!\n");
        else
            printf("L is not empty!\n");

        DestoryList(&L);

        printf("After clear...");
        if(L.elem != NULL)
            printf("L is empty...\n");
        else
            printf("L is not empty...\n");
    }
    PressEnterToContinue(debug);
}
