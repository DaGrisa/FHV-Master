//
// Created by Daniel on 30.01.17.
//

#ifndef VORLESUNG_STACK_H
#define VORLESUNG_STACK_H

#include <cstring>

class Stack {
    int* pValue;
    int size;
    int position;
public:
    Stack(int size = 32){
        this->pValue = new int[size];
        this->size = size;
        this->position = 0;
    }

    Stack(const Stack& s){
        this->size = s.size;
        this->position = s.position;
        this->pValue = new int[size];
        std::memcpy(s.pValue,this->pValue,size);
    }

    ~Stack() {
        delete[] pValue;
    }

    void push(int value){
        pValue[position++] = value;
    }

    int pop(){
        return pValue[--position];
    }

};

#endif //VORLESUNG_STACK_H
