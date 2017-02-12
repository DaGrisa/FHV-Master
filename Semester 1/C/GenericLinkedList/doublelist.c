//
// Created by Daniel on 29.01.17.
//

#include <MacTypes.h>
#include <stdlib.h>
#include "doublelist.h"
#include "list.h"

DNode_t *doublelist_createList(double firstValue) {
    DNode_t *firstNode = malloc(sizeof(DNode_t));
    firstNode->pNext = &list_sentinelNodeLast;
    firstNode->value = firstValue;

    return firstNode;
}

DNode_t *doublelist_addValueFirst(DNode_t *pFirstNode, double value) {
    DNode_t *newNode = malloc(sizeof(DNode_t));
    newNode->value = value;
    return (DNode_t*)insertFirstNode((Node_t*)pFirstNode, (Node_t*)newNode);
}

void doublelist_addValueLast(DNode_t *pFirstNode, double value) {
    DNode_t *newNode = malloc(sizeof(DNode_t));
    newNode->value = value;
    insertLastNode((Node_t*)pFirstNode, (Node_t*)newNode);
}
