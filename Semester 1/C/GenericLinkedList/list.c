//
// Created by Daniel on 29.01.17.
//
#include <stddef.h>
#include "list.h"

Node_t list_sentinelNodeLast;

struct Node_t * getLastNode(Node_t *node){
    if(node->pNext == &list_sentinelNodeLast){
        return node;
    } else {
        return getLastNode(node->pNext);
    }
}

void insertLastNode(Node_t *firstNode, Node_t *pInsertNode) {
    Node_t *lastNode = getLastNode(firstNode);
    lastNode->pNext = pInsertNode;
    pInsertNode->pNext = &list_sentinelNodeLast;
}

Node_t* insertFirstNode(Node_t *firstNode, Node_t *pInsertNode) {
    pInsertNode->pNext = firstNode;
    return pInsertNode;
}