//
// Created by Daniel on 29.01.17.
//

#ifndef GENERICLINKEDLIST_LIST_H
#define GENERICLINKEDLIST_LIST_H

typedef struct Node_t {
    struct Node_t *pNext;
} Node_t;

extern Node_t list_sentinelNodeLast;

struct Node_t * getLastNode(Node_t*);

void insertLastNode(Node_t*, Node_t*);

Node_t* insertFirstNode(Node_t*, Node_t*);

#endif //GENERICLINKEDLIST_LIST_H
