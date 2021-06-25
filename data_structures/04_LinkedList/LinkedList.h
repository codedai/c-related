#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"

typedef int ElemType;

/* 
 * Structure of single linked list
 *
 * (with empty head node)
 */
typedef struct LNode {
    ElemType data;
    struct LNode * next;
} LNode;

typedef LNode * LinkedList;

/*
 * Initiate the list
 */
Status InitList(LinkedList * L);

/*
 * Destory the list
 */
Status DestoryList(LinkedList * L);

/*
 * Clear all occupied spaces in the list,
 * except the head node;
 */
Status ClearList(LinkedList L);

/*
 * Weather the list is empty
 *
 * Return:
 * TRUE: is empty
 * FALSE: is not empty
 */
Status ListEmpty(LinkedList L);

/*
 * Count the number of elements in the list
 */
int ListLength(LinkedList L);

/*
 * Get the i-th element in the list,
 * if there is an i-th element, save the element into e and return OK.
 * else return error.
 */
Status GetElem(LinkedList L, int i, ElemType* e);

/*
 * Insert a new element e in the list
 * Return:
 * OK: if sucess
 * ERROR: not sucess
 */
Status ListInsert(LinkedList L, ElemType e, int(cmp)(ElemType, ElemType));

/* 
 * Find the first element's position which is not smaller than element e
 * return the position
 */
int LocateElem(LinkedList L, ElemType e, int(cmp)(ElemType, ElemType));

Status PriorElem(LinkedList L, ElemType cur_e, LinkedList * pre_node, int (cmp)(ElemType, ElemType));

/*
 * Delete the element i on the i-th position, and save the element to e.
 * Return:
 * OK: if sucess
 * ERROR: if nor
 */
Status ListDelete(LinkedList L, int i, ElemType * e);

/*
 * Traverse the list using vist
 */
void ListTraverse(LinkedList L, void(vist)(ElemType));

/*
 *
 */
Status CreateList_Head(LinkedList *L, int n, char * path);

/*
 *
 */
Status CreateList_Tail(LinkedList * L, int n, char * path);

#endif
