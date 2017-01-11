//
// Created by Daniel on 11.01.17.
//

#ifndef STACKTEMPLATE_STACK_H
#define STACKTEMPLATE_STACK_H

template <typename T>

class Stack {
    T *pValues;
    int actualIndex;
    int size;

public:
    Stack(int size);
    T* pop();
    bool push(T value);
};

template <typename T>

Stack<T>::Stack(int size) {
    pValues = new T[size];
    actualIndex = 0;
    this->size = size;
}

template <typename T>

T* Stack<T>::pop() {
    if(actualIndex > 0){
        return &pValues[--actualIndex];
    }
    return nullptr;
}

template <typename T>

bool Stack<T>::push(T value) {
    if(actualIndex<size){
        pValues[actualIndex++] = value;
        return true;
    } else {
        return false;
    }
}


#endif //STACKTEMPLATE_STACK_H
