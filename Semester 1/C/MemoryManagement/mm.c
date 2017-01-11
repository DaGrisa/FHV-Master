//
// Created by Daniel on 26.12.16.
//

#include <stdint.h>
#include <stdio.h>

#define FALSE 0
#define TRUE !(FALSE)

#define MEMORY_SIZE 64

typedef char byte; // char is exactly 1 byte

typedef struct {
    uint8_t size;
    uint8_t isFree;
} Header_t;

static byte mm_memory[MEMORY_SIZE];

static int mm_initialize = TRUE;

static void mm_initHeader(void* pHeaderAddress, uint8_t size) {
    Header_t* pNewHeader;
    pNewHeader = (Header_t*) pHeaderAddress;
    pNewHeader->isFree = TRUE;
    pNewHeader->size = size - sizeof(Header_t);
};

static int mm_isFreeAndBigEnough(Header_t* pHeader, uint8_t size){
    if(pHeader->isFree && pHeader->size >= size){
        return TRUE;
    } else {
        return FALSE;
    }
}

void* mm_malloc(uint8_t size) {
    // initialize first header on first use
    if(mm_initialize){
        mm_initHeader(&mm_memory, MEMORY_SIZE);
        mm_initialize = FALSE;
    }

    // start at first header
    void* position = &mm_memory;
    uint8_t lastSize = ((Header_t*) position)->size;
    while(!mm_isFreeAndBigEnough((Header_t*) position, size)){
        lastSize = ((Header_t*) position)->size;
        position = position + lastSize + sizeof(Header_t);
    }

    Header_t *newHeader;
    newHeader = (Header_t*) position;
    newHeader->size = size;
    newHeader->isFree = FALSE;

    void* newPosition = newHeader + sizeof(Header_t);

    void* nextHeaderAddress = newPosition + newHeader->size;
    uint8_t newSize = lastSize - size - sizeof(Header_t);
    mm_initHeader(nextHeaderAddress, newSize);

    return newPosition;
};

void mm_free(void *mem) {
    Header_t *header = mem;
    header->isFree = TRUE;
};
