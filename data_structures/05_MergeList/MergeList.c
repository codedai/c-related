#include "MergeList.h"

void MergeList(LinkedList * La, LinkedList * Lb, LinkedList * Lc) {
    LinkedList p, a_head, b_head;

    a_head = (*La)->next;
    b_head = (*Lb)->next;

    p = *Lc = *La;

    while (a_head != NULL && b_head != NULL) {
        if (a_head->data > b_head->data) {
            p->next = b_head;
            b_head = b_head->next;
        } else {
            p->next = a_head;
            a_head = a_head->next;
        }
        p = p->next;
    }

    p->next = a_head == NULL? b_head : b_head;

    free(*Lb);
    *Lb = NULL;
    *La = NULL;
}
