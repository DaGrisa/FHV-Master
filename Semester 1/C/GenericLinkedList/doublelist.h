//
// Created by Daniel on 29.01.17.
//

#ifndef GENERICLINKEDLIST_DOUBLELIST_H
#define GENERICLINKEDLIST_DOUBLELIST_H

typedef struct {
    struct Node_t *pNext;
    double value;
} DNode_t;

DNode_t* doublelist_createList(double);
DNode_t* doublelist_addValueFirst(DNode_t*, double);
void doublelist_addValueLast(DNode_t*, double);

#endif //GENERICLINKEDLIST_DOUBLELIST_H
