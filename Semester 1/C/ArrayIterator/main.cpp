#include <iostream>
#include "ArrayIterator.h"

int main() {
    int values[] = {1, 2, 3, 4};
    ArrayIterator<int> iterator(values, 4);

    while(iterator.hasNext()){
        std::cout << *iterator.next() << std::endl;
    }

    char valuesChar[] = {'a','b','c','d','e'};
    ArrayIterator<char> iteratorCh(valuesChar, 5);

    while(iteratorCh.hasNext()){
        std::cout << *iteratorCh.next() << std::endl;
    }

    return 0;
}