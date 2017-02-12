//
// Created by Daniel on 30.01.17.
//

#include <iostream>

#include "Person.h"

Person::Person(const char *pName) {
    this->pName = pName;
}

Person* Person::operator=(const Person &person) {
    return new Person(this->pName);
}

const char *Person::getName() {
    return this->pName;
}

int Person::getValue() {
    return 4211;
}

bool Person::operator ==(const Person& person){
    for(int i = 0; this->pName[i] == person.pName[i]; i++){
        if(this->pName[i] == '\0' and person.pName[i] == '\0'){
            return true;
        }
    }
    return false;
}

// free function
std::ostream& operator<<(std::ostream &os, const Person& person) {
    for(int i = 0; person.pName[i]!='\0'; i++){
        os << person.pName[i];
    }

    return os;
}
