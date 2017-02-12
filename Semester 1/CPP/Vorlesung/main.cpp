#include <iostream>
#include <vector>
#include "Person.h"
#include "Stack.h"
#include "Student.h"
#include "TypedStack.h"

void pushTen(Stack&); // & denotes a reference instead of a pointer
// references doesn't allow pointer arithmetic, nut they also cannot be NULL
int getPersonValue(Person&);

int main() {
    Person personStack("Stack");
    Person* personHeap = new Person("Heap");
    delete personHeap;
    Person copyOperator = personStack;
    Person equalsOperator("Stack");
    if(copyOperator == equalsOperator){
        std::cout << "Person compare and copy operator works!" << std::endl;
    }
    std::cout << "Person Name: " << personStack << std::endl;

    Stack intStack;
    pushTen(intStack);
    intStack.push(3);
    intStack.push(2);
    intStack.push(1);
    for(int i = 0; i < 4; i++) {
        std::cout << intStack.pop() << std::endl;
    }

    Student newStudent("Daniel", 1234567890);
    const char* name = newStudent.getName();
    for(int i = 0; i < 6; i++) {
        std::cout << name[i];
    }
    std::cout << std::endl << getPersonValue(newStudent) << std::endl;
    Person newPerson = newStudent;
    std::cout << getPersonValue(newPerson) << std::endl;

    TypedStack<int> intTypedStack(5);
    intTypedStack.push(3);
    intTypedStack.push(2);
    intTypedStack.push(1);
    for(int i = 0; i < 3; i++) {
        std::cout << intTypedStack.pop() << std::endl;
    }

    std::vector<int> values = {1,2,3,4,5};
    std::vector<int>::iterator iterator = values.begin();
    while(iterator != values.end()){
        printf("%d",*iterator);
        iterator++;
    }

    return 0;
}

void pushTen(Stack& s){
    s.push(10);
}

// use virtual to enable dynamic binding
int getPersonValue(Person& person){
    return person.getValue();
}