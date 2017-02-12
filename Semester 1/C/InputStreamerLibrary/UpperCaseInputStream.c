//
// Created by Daniel on 30.01.17.
//

#include <ctype.h>
#include <stdlib.h>
#include "UpperCaseInputStream.h"
#include "InputStream.h"

static InputStream *sourceInputStream;
static InputStream upperCaseInputStream;

char nextUpperCaseImpl(void){
    return toupper(sourceInputStream->next());
}

InputStream* getUpperCaseInputStream(InputStream *inputStream) {
    sourceInputStream = inputStream;

    upperCaseInputStream.next = nextUpperCaseImpl;
    upperCaseInputStream.hasNext = sourceInputStream->hasNext;
    upperCaseInputStream.deleteAll = sourceInputStream->deleteAll;

    return &upperCaseInputStream;
}