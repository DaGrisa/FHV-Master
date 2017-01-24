//
// Created by Daniel on 18.01.17.
//

#ifndef ARRAYITERATOR_ARRAYITERATOR_H
#define ARRAYITERATOR_ARRAYITERATOR_H

template <class T>
class ArrayIterator {
    T *actual, *values, *last;

public:
    ArrayIterator(T *valuesIn, int size);
    T* next();
    bool hasNext();
};

template <class T>
T* ArrayIterator<T>::next() {
    if(actual<=last) {
        return actual++;
    } else {
        return last;
    }
}

template <class T>
ArrayIterator<T>::ArrayIterator(T *valuesIn, int size) {
    values = valuesIn;
    actual = values;
    last = values+(size-1);
}

template <class T>
bool ArrayIterator<T>::hasNext() {
    if(actual<=last){
        return true;
    } else {
        return false;
    }
}

#endif //ARRAYITERATOR_ARRAYITERATOR_H
