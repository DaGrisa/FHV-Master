#include <inttypes.h>

#define HEAPSIZE (64)
#define BLOCKSIZE (4)
#define IS_ALLOCATED_BIT (1)

typedef struct {
    uint8_t size;
    uint8_t flags;
    uint16_t rfu;
} Header_t;

uint8_t gHeap[HEAPSIZE];

// todo setup - initialize header

static int isFreeAndBigEnough(Header_t* header, uint8_t size){
    uint8_t isFree = header->flags & IS_ALLOCATED_BIT;
    uint8_t isBigEnough = header->size >= size;
    return isFree && isBigEnough;
}

static uint8_t getDataSize(uint8_t minSize){
    return ((minSize + BLOCKSIZE - 1) / BLOCKSIZE) * BLOCKSIZE;
}

void* dgfh_memory_allocation(uint8_t size){
    Header_t* pHeader = (Header_t*) gHeap; // starting pointer in heap (first header)
    
    //(*header).flags
    const uint8_t data_size = getDataSize(size);
    while(isFreeAndBigEnough(pHeader, data_size)) {
        uint8_t dataSize = pHeader->size;
        //header += 1; statt + sizeof(Header_t)
        pHeader = (Header_t)(sizeof(Header_t) + (uint8_t) pHeader + dataSize);
    }

    pHeader->flags |= IS_ALLOCATED_BIT;
    pHeader->size = size;
    return pHeader + 1;
}