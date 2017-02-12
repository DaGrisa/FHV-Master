//
// Created by Daniel on 30.01.17.
//

#ifndef VORLESUNG_STUDENT_H
#define VORLESUNG_STUDENT_H

#include "Person.h"

class Student : public Person {
    int studentNumber;
public:
    Student(const char*, int);
    int getValue();
};

#endif //VORLESUNG_STUDENT_H
