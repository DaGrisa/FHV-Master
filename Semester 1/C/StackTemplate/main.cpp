#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> intStack(2);
    intStack.push(1);
    intStack.push(2);

    if(!intStack.push(3)){
        std::cout << "upper boundary works" << std::endl;
    }

    std::cout << *intStack.pop() << std::endl;
    std::cout << *intStack.pop() << std::endl;

    if(nullptr == intStack.pop()){
        std::cout << "lower boundary works" << std::endl;
    }

    return EXIT_SUCCESS;
}