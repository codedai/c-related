#include "LinkedList.h"


/*
 * Initiate the list
 */
Status InitList(LinkedList * L){
    *L = (LinkedList) calloc(1, sizeof(LNode));
    if (*L == NULL) exit(OVERFLOW);

    (*L)->next = NULL;
    
    return OK;
}

/*
 * Destory the list
 */
Status DestoryList(LinkedList * L) {
    if (L == NULL || *L == NULL)
        return ERROR;

    LinkedList p = *L;

    while( p != NULL ) {
        p = (*L)->next;
        free(*L);
        *L = p;
    }

    *L = NULL;

    return OK;
}

/*
 * Clear all occupied spaces in the list,
 * except the head node;
 */
Status ClearList(LinkedList L) {
    LinkedList pre, p;
    
    if (L == NULL)
        return ERROR;

    p = L->next;
    
    while (p != NULL) {
        pre = p;
        p = p -> next;
        free(pre);
    }

    L -> next = NULL;

    return OK;
}

/*
 * Weather the list is empty
 *
 * Return:
 * TRUE: is empty
 * FALSE: is not empty
 */
Status ListEmpty(LinkedList L) {
    if (L != NULL && L -> next == NULL) 
        return TRUE;
    else
        return FALSE;
}

/*
 * Count the number of elements in the list
 */
int ListLength(LinkedList L) {
    int count;

    if (L == NULL) 
        return 0;

    count = 0;

    while (L->next != NULL){
        ++count;
        L = L ->next;
    }
    return count;
}

/*
 * Get the i-th element in the list,
 * if there is an i-th element, save the element into e and return OK.
 * else return error.
 */
Status GetElem(LinkedList L, int i, ElemType* e) {
    LinkedList p;

    if (L == NULL)
        return ERROR;

    p = L->next;

    while (i-- > 0) {
        if (p == NULL)
            return ERROR;
        p = p->next;
    }

    *e = p->data;
    return OK;
}

/*
 * Insert a new element e in the list
 * Return:
 * OK: if sucess
 * ERROR: not sucess
 */
Status ListInsert(LinkedList L, ElemType e, int(cmp)(ElemType, ElemType)) {
    if (L == NULL)
        return ERROR;

    LinkedList pre_node;

    if (PriorElem(L, e, &pre_node, cmp) != ERROR) {
        LNode * new_node = calloc(1, sizeof(LNode));

        new_node->data = e;
        new_node->next = pre_node->next;

        pre_node->next = new_node;
    }

    return OK;

}

/* 
 * Find the first element's position which is not smaller than element e
 * return the position
 */
int LocateElem(LinkedList L, ElemType e, int(cmp)(ElemType, ElemType)) {
    if (L == NULL || L->next == NULL)
        return 0;
    L = L->next;
    int res = 0;
    while (L != NULL && cmp(L->data, e) < 0) {
        res++;
        L = L->next;
    }

    return res;
}

Status PriorElem(LinkedList L, ElemType cur_e, LinkedList * pre_node, int (cmp)(ElemType, ElemType)) {
    if (L == NULL) 
        return ERROR;
    if (L->next != NULL)
    while (L->next != NULL && cmp((L->next)->data, cur_e) < 0) {
        L = L -> next;
    }

    *pre_node = L;

    return OK;

}

/*
 * Delete the element i on the i-th position, and save the element to e.
 * Return:
 * OK: if sucess
 * ERROR: if nor
 */
Status ListDelete(LinkedList L, int i, ElemType * e) {
    if (L == NULL)
        return ERROR;
    LinkedList head = L->next;
    
    while (head != NULL) {
        if (i == 0) {
            *e = head->data;
            L->next = head->next;
            free(head);
            head = NULL;
            return OK;
        } else {
            L = head;
            head = head->next;
            i--;
        }
    }
    return ERROR;
}

/*
 * Traverse the list using vist
 */
void ListTraverse(LinkedList L, void(vist)(ElemType)) {
    if (L == NULL)
        return;

    LinkedList p = L->next;

    while (p != NULL) {
        vist(p->data);
        p = p -> next;
    }
    printf("\n");
}

/*
 *
 */
Status CreateList_Head(LinkedList *L, int n, char * path) {
    int i;
    LinkedList p;
    FILE * fp;

    int readFromConsole;

    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if (readFromConsole) {
        *L = malloc(sizeof(LNode));
        if (*L == NULL)
            return ERROR;

        (*L)->next = NULL;

        printf("Input %d numbers: ", n);

        for (i = 0; i < n; ++i) {
            p = calloc(1, sizeof(LNode));

            scanf("%d", &(p->data));
            p -> next = (*L) -> next;
            (*L) -> next = p;
        }
    } else {
        fp = fopen(path, "r");
        if (fp == NULL)
            return ERROR;

        *L = malloc(sizeof(LNode));

        (*L)->next = NULL;

        for (i = 0; i < n; ++i) {
            p = malloc(sizeof(LNode));

            ReadData(fp, "%d", &(p->data));

            p -> next = (*L) -> next;
            (*L) -> next = p;
        }
        fclose(fp);
    }

    return OK;
}

/*
 *
 */
Status CreateList_Tail(LinkedList * L, int n, char * path){
    int i;
    LinkedList p, q;
    FILE * fp;

    int readFromConsole;

    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if (readFromConsole) {
        *L = malloc(sizeof(LNode));
        if (*L == NULL)
            return ERROR;

        (*L)->next = NULL;

        printf("Input %d numbers: ", n);

        for (i = 0, q = *L; i < n; ++i) {
            p = calloc(1, sizeof(LNode));

            scanf("%d", &(p->data));
            q->next = p;
            q = p;
        }
    } else {
        fp = fopen(path, "r");
        if (fp == NULL)
            return ERROR;

        *L = malloc(sizeof(LNode));

        (*L)->next = NULL;

        for (i = 0, q = *L; i < n; ++i) {
            p = malloc(sizeof(LNode));

            ReadData(fp, "%d", &(p->data));

            q -> next = p;
            q = p;
        }

        q -> next = NULL;
        fclose(fp);
    }

    return OK;
}
