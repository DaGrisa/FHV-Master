//
// Created by Daniel on 28.01.17.
//

#include <stdlib.h>
#include "ByteArrayInputStream.h"
#include "InputStream.h"

static InputStream stream;
static char* pData;

static int hasNextImpl(void) {
    if(*pData == '\0'){
        return 0;
    } else {
        return 1;
    }
}

static char nextImpl(void){
    return *(pData++);
}

static void deleteAllImpl(void){
    *pData = '\0';
}

InputStream* getByteArrayInputStream(char* streamSource){
    pData = streamSource;
    stream.hasNext = hasNextImpl;
    stream.next = nextImpl;
    stream.deleteAll = deleteAllImpl;
    return &stream;
}