#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node;
typedef int ElementType;
typedef struct Node * PtrToNode;
typedef PtrToNode LinkedList;
typedef PtrToNode Position;

LinkedList makeEmpty(LinkedList );
int isEmpty(LinkedList );
int isLast(Position, LinkedList );
Position find(ElementType , LinkedList );
void delete(ElementType , LinkedList );
Position findPrevious(ElementType , LinkedList , Position );
void insert(ElementType , LinkedList , Position );
void deleteList(LinkedList );
Position header(LinkedList );
Position first(LinkedList );
Position advance(Position );
ElementType retrieve(Position );

#endif /* LINKED_LIST_H */

struct Node {
    ElementType element;
    Position next;
};
