#include "SqList.c"

/*
 * Create a sequence
 *
 * if success return OK, either return ERROR
 */
Status InitList(SqList * L) {
    L = calloc(1, SqList);
    if (L == NULL) return ERROR;

    L->elem = calloc(LIST_INIT_SIZE, sizeof(ElemType));
    if (L->elem == NULL) return ERROR;

    L->length = 0;
    L->listSize = (L->length) * sizeof(ElemType));

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

    free(L);
    L = NULL;
    
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
    L->listSize = 0;

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
    if (L->length == 0)
        return TRUE;
    else
        return False;
}


/*
 * Return the number of valid elements in the list
 */
int ListLength(SqList L) {
    return L->length;
}

/*
 * Get the i-th, and save to e.
 * 
 * If we can get the i-th element, return OK
 * eitherwise, return ERROR
 */
Status GetElem(SqList L, int i, ElemType * e) {
    if (L == NULL || i >= L->length) return ERROR;

    *e = (L->elem)[i];
    return OK;
}

/*
 * Return the first position where e occur
 *
 * if there is no such element, return -1
 */
int LocateElem(SqList L, ElemType e, int(compare)(ElemType, ElemType)) {
    if (L == NULL)
        return -1;
    
    ElemType * temp_e = L->elem;
    int l, r, mid, cmp_r;
    l = 0;
    r = L->length - 1;

    while (r >= l) {
        mid = (l + (r-l) / 2);
        cmp_r = compare(temp_e[mid], e);
        if (cmp_r == 0) return mid;
        else if (cmp_r > 0) r = mid + 1;
        else l = mid - 1;
    }

    return -1;
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

    *pre_e = (L->elem)[search_r - 1];

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

    if (search_r == -1 || search_r == L->length - 2) return ERROR;

    *next_e = (L->elem)[search_r + 1];

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

    return OK;
}

/*
 * Traverse the list use visit list L
 */
void ListTraverse(SqList L, void (Visit)(ElemType)) {
    if (L == NULL) return;
    
    ElemType * e_list = L->elem;
    int i;

    for (i = 0; i < L->length; ++i)
        Visit(e_list[i]);
}
