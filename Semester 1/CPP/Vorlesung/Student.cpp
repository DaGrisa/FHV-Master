//
// Created by Daniel on 30.01.17.
//

#include "Student.h"

Student::Student(const char * pName, int studentNumber):Person(pName) {
    this->studentNumber = studentNumber;
}

int Student::getValue() {
    return this->studentNumber;
}
