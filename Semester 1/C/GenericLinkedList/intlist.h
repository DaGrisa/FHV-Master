//
// Created by Daniel on 29.01.17.
//

#ifndef GENERICLINKEDLIST_INTLIST_H
#define GENERICLINKEDLIST_INTLIST_H

typedef struct {
    struct Node_t *pNext;
    int value;
} INode_t;

INode_t* intlist_createList(int);
INode_t* intlist_addValueFirst(INode_t*, int);
void intlist_addValueLast(INode_t*, int);

#endif //GENERICLINKEDLIST_INTLIST_H
