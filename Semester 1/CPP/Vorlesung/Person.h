//
// Created by Daniel on 30.01.17.
//

#ifndef VORLESUNG_PERSON_H
#define VORLESUNG_PERSON_H

#include <iosfwd>

class Person {
    friend std::ostream& operator<<(std::ostream&, const Person&);
    const char *pName;
public:
    Person(const char*);
    Person* operator=(const Person&);
    bool operator ==(const Person&);
    const char* getName();
    virtual int getValue();
};

#endif //VORLESUNG_PERSON_H
