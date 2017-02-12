//
// Created by Daniel on 29.01.17.
//

#include <stdlib.h>
#include "list.h"
#include "intlist.h"

INode_t* intlist_createList(int firstValue){
    INode_t *firstNode = malloc(sizeof(INode_t));
    firstNode->pNext = &list_sentinelNodeLast;
    firstNode->value = firstValue;

    return firstNode;
}

INode_t* intlist_addValueFirst(INode_t* pFirstNode, int value){
    INode_t *newNode = malloc(sizeof(INode_t));
    newNode->value = value;
    return (INode_t*)insertFirstNode((Node_t*)pFirstNode, (Node_t*)newNode);
}

void intlist_addValueLast(INode_t* pFirstNode, int value){
    INode_t *newNode = malloc(sizeof(INode_t));
    newNode->value = value;
    insertLastNode((Node_t*)pFirstNode, (Node_t*)newNode);
}