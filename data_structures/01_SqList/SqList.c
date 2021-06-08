#include "SqList.h"

/*
 * Create a sequence
 *
 * if success return OK, either return ERROR
 */
Status InitList(SqList * L) {
    L->elem = calloc(LIST_INIT_SIZE, sizeof(ElemType));
    if (L->elem == NULL) return ERROR;

    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}


/*
 * Destory the SqList
 *
 * Release the memory
 */
Status DestoryList(SqList * L) {
    if (L == NULL) return ERROR;

    free(L->elem);
    L->elem = NULL;

    return OK;
}


/*
 * Set the memory to empty
 *
 * Does not free the memory
 */
Status ClearList(SqList * L) {
    if (L == NULL) return ERROR;

    L->length = 0;
    
    return OK;
}

/*
 * check wether the list contains valid element
 *
 * Return:
 * TRUE: There is no valid
 * FALSE: There is
 */
Status ListEmpty(SqList L) {
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}


/*
 * Return the number of valid elements in the list
 */
int ListLength(SqList L) {
    return L.length;
}

/*
 * Get the i-th, and save to e.
 * 
 * If we can get the i-th element, return OK
 * eitherwise, return ERROR
 */
Status GetElem(SqList L, int i, ElemType * e) {
    if (i < 0 || i >= L.length) return ERROR;

    *e = ((L.elem)[i]);
    return OK;
}

/*
 * Return the first position where e occur
 *
 * if there is no such element, return -1
 */
int LocateElem(SqList L, ElemType e, int(compare)(ElemType, ElemType)) {
    ElemType * temp_e = L.elem;
    int i, cmp_r;

    for (i = 0; i < L.length; ++i) {
        if (compare(temp_e[i], e) >= 0)
            return i;
    }

    return i;
}

/*
 * Return the Prior element of cur_e
 * If exist, save it to pre_e, and return OK,
 * If not, return ERROR
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType * pre_e, int(cmp)(ElemType, ElemType)) {
    int search_r;

    search_r = LocateElem(L, cur_e, cmp);

    if (search_r == -1 || search_r == 0) return ERROR;

    *pre_e = (L.elem)[search_r - 1];

    return OK;
}

/*
 * Return the next element of cur_e
 * If exist, save it to next_e, and return OK,
 * If not, return ERROR
 */
Status NextElem(SqList L, ElemType cur_e, ElemType * next_e, int(cmp)(ElemType, ElemType)) {
    int search_r;

    search_r = LocateElem(L, cur_e, cmp);

    if (search_r == -1 || search_r == L.length - 2) return ERROR;

    *next_e = (L.elem)[search_r + 1];

    return OK;
}

/*
 * Delete the element on i-th position, and save the deleted element into e
 * If success, return OK, eitherwise, return ERROR
 */
Status ListDelete(SqList * L, int i, ElemType * e) {
    if (L == NULL || i < 0 || i >= L->length) {
        return ERROR;
    }

    *e = (L->elem)[i];

    int id;

    for (id = i; id < L->length - 1; ++id) {
        (L->elem)[id] = (L->elem)[id + 1];
    }
    (L->length)--;

    return OK;
}

/*
 * Insert element e on position i,
 * If the size of the list is not enough,
 * assign new store space to the list.
 */
Status ListInsert(SqList * L, int i, ElemType e) {
    if (L == NULL || i < 0 || i > L->length)
        return ERROR;
    
    if (L->length ==  L->listSize) {
       L->elem = realloc(L->elem, (L->listSize + LISTINCREMENT) * sizeof(ElemType)); 
       L->listSize = L->listSize + LISTINCREMENT;
    }

    int j;
    for (j = L->length - 1; j >= i; j--)
        (L->elem)[j+1] = (L->elem)[j];
    
    (L->elem)[i] = e;
    (L->length)++;
    printf("L->length is : %d\n", L->length);
    return OK;
}

/*
 * Traverse the list use visit list L
 */
void ListTraverse(SqList L, void (Visit)(ElemType)) {
    ElemType * e_list = L.elem;
    int i;

    for (i = 0; i < L.length; ++i)
        Visit(e_list[i]);
}
