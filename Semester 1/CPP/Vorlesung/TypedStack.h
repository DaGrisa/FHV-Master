//
// Created by Daniel on 30.01.17.
//

#ifndef VORLESUNG_TYPEDSTACK_H
#define VORLESUNG_TYPEDSTACK_H

template <typename T>
class TypedStack {
    T *pValues;
    int size;
    int position;
public:
    TypedStack(int size) {
        this->size = size;
        this->position = 0;
        this->pValues = new T[size];
    }
    void push(T value) {
        pValues[position++] = value;
    }
    T pop() {
        return pValues[--position];
    }
};

#endif //VORLESUNG_TYPEDSTACK_H
