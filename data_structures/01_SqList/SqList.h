/*******************************
 *      Squence List
 *
 ******************************
 */

#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define LIST_INIT_SIZE 100  // The init size of the sequence
#define LISTINCREMENT   10  // The increasing size


typedef int ElemType;

typedef struct {
    ElemType * elem;
    int length;
    int listSize;
} SqList;

/*
 * Create a sequence
 *
 * if success return OK, either return ERROR
 */
Status InitList(SqList * L);


/*
 * Destory the SqList
 *
 * Release the memory
 */
Status DestoryList(SqList * L);


/*
 * Set the memory to empty
 *
 * Does not free the memory
 */
Status ClearList(SqList * L);

/*
 * check wether the list contains valid element
 *
 * Return:
 * TRUE: There is valid
 * FALSE: There is not
 */
Status ListEmpty(SqList L);


/*
 * Return the number of valid elements in the list
 */
int ListLength(SqList L);

/*
 * Get the i-th, and save to e.
 * 
 * If we can get the i-th element, return OK
 * eitherwise, return ERROR
 */
Status GetElem(SqList L, int i, ElemType * e);

/*
 * Return the first position where e occur
 *
 * if there is no such element, return -1
 */
int LocateElem(SqList L, ElemType e, Status(compare)(ElemType, ElemType));

/*
 * Return the Prior element of cur_e
 * If exist, save it to pre_e, and return OK,
 * If not, return ERROR
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType * pre_e);

/*
 * Return the next element of cur_e
 * If exist, save it to next_e, and return OK,
 * If not, return ERROR
 */
Status NextElem(SqList L, ElemType cur_e, ElemType * next_e);

/*
 * Delete the element on i-th position, and save the deleted element into e
 * If success, return OK, eitherwise, return ERROR
 */
Status ListDelete(SqList * L, int i, ElemType * e);

/*
 * Traverse the list use visit list L
 */
void ListTraverse(SqList L, void (Visit)(ElemType));
