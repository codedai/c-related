#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode LinkedList;
typedef PtrToNode Position;

LinkedList MakeEmpty(LinkedList L);
int IsEmpty(LinkedList L);
int IsLast(Postition P, LinkedList L);
Position Find(ElementType X, LinkedList L);
void Delete(ElementType X, LinkedList L);
Position FindPrevious(ElementType X, LinkedList L, Position P);
void Insert(ElementType X, LinkedList L, Position P);
void DeleteList(LinkedList L);
Position Header(LinkedList L);
Position First(LinkedList L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif /* LINKED_LIST_H */

struct Node {
    ElementType Element;
    Position Next;
};
