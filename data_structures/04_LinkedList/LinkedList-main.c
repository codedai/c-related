#include <stdio.h>
#include "Status.h"
#include "LinkedList.h"

int cmp(ElemType e1, ElemType e2) {
    return (int)e1 - e2;
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main (int argc, char ** argv) {
    LinkedList L;
    int i;
    ElemType e;


    printf("InitList \n");
    {
        InitList(&L);
    }
    PressEnterToContinue(debug);

    printf("List Empty \n");
    {
        ListEmpty(L) ? printf("List is empty.\n") : printf("List is not empty.\n");
        printf("The length of the list is %d. \n", ListLength(L));
    }
    PressEnterToContinue(debug);

    printf("Insert new element\n");
    {
        for (i = 0; i < 10; ++i) {
            ListInsert(L, i*i + 1, cmp);
        }
        ListTraverse(L, PrintElem);
        ListInsert(L, 5, cmp);
        ListInsert(L, -1, cmp);
        ListInsert(L, -1, cmp);
        ListInsert(L, 83, cmp);
        ListInsert(L, 80, cmp);
        ListTraverse(L, PrintElem);
        printf("The length of the list is %d. \n", ListLength(L));
    }
    PressEnterToContinue(debug);

    printf("GetElem \n");
    {
        for (i = 0; i < 10; ++i) {
            GetElem(L, i, &e);
            printf("%d, ", e);
        }
        printf("\n");
    }
    PressEnterToContinue(debug);

    printf("ListDelete\n");
    {
        ListDelete(L, 0, &e);
        printf("%d is the deleted element.\n", e);
        ListTraverse(L, PrintElem);
        ListDelete(L, 0, &e);
        printf("%d is the deleted element.\n", e);
        ListTraverse(L, PrintElem);

        ListDelete(L, 5, &e);
        printf("%d is the deleted element.\n", e);
        ListTraverse(L, PrintElem);
        ListDelete(L, ListLength(L)-1, &e);
        printf("%d is the deleted element.\n", e);
        ListTraverse(L, PrintElem);
    }    
    PressEnterToContinue(debug);

    printf("LocateElem\n");
    {
        for (i = 0; i < 10; ++i) {
            printf("The location of %d is %d. \n", i*i+1, LocateElem(L, i*i+1, cmp));
        }
    }
    PressEnterToContinue(debug);

    printf("ClearList\n");
    {
        ListTraverse(L, PrintElem);

        ClearList(L);

        ListEmpty(L) ? printf("The list is now empty.\n") : printf("The list is not empty.\n");
    }
    PressEnterToContinue(debug);

    printf("DestoryList");
    {
        DestoryList(&L);

        L == NULL ? printf("List is destoried.") : printf("List is not destoried.");
    }
    PressEnterToContinue(debug);

    printf("CreateList_Head\n");
    {
        CreateList_Head(&L, 6, NULL);
        ListTraverse(L, PrintElem);
        DestoryList(&L);

        CreateList_Tail(&L, 6, NULL);
        ListTraverse(L, PrintElem);
        DestoryList(&L);

        CreateList_Head(&L, 6, "insert_list.txt");
        ListTraverse(L, PrintElem);
        DestoryList(&L);

        CreateList_Tail(&L, 6, "insert_list.txt");
        ListTraverse(L, PrintElem);
        DestoryList(&L);
    }
    return 0;
}
