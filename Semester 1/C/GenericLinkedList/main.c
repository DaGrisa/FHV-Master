#include "intlist.h"
#include "list.h"
#include "doublelist.h"

#include <stdio.h>

int main() {
    INode_t *pIntList = intlist_createList(1);
    pIntList = intlist_addValueFirst(pIntList, 2);
    printf("Last value of LinkedList is %d\n", ((INode_t*)getLastNode((Node_t*)pIntList))->value);
    intlist_addValueLast(pIntList, 3);
    printf("Last value of LinkedList is %d\n", ((INode_t*)getLastNode((Node_t*)pIntList))->value);

    DNode_t *pDoubleList = doublelist_createList(1.234);
    pDoubleList = doublelist_addValueFirst(pDoubleList, 2.345);
    printf("Last value of LinkedList is %f\n", ((DNode_t*)getLastNode((Node_t*)pDoubleList))->value);
    doublelist_addValueLast(pDoubleList, 3.456);
    printf("Last value of LinkedList is %f\n", ((DNode_t*)getLastNode((Node_t*)pDoubleList))->value);

    return 0;
}