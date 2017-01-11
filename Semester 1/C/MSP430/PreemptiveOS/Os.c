/*
 * Os.c
 *
 *  Created on: 16. Dez. 2016
 *      Author: daniel
 */

#include <setjmp.h>
#include <msp430.h>

#define ATOMIC_ON()	__disable_interrupts()
#define ATOMIC_OFF()	__enable_interrupts()

#define THREAD_ID_INVALID   -1

#define THREAD_STATUS_READY  0
#define THREAD_STATUS_RUN   1

#define THREAD_MAIN_PRIORITY    10

typedef int (*threadFunction)(int, int);

struct ProcessTableEntry {
    int threadId;
    // status of the process
    // 0 = sleep
    // 1 = run
    int status;
    // jump type?
    // 0 = set jump
    // 1 = long jump
    jmp_buf context;
    // process priority
    int priority;
    // process function pointer
    threadFunction function;
};

void registerNewProcess(struct ProcessTableEntry entry);

void extendProcessTable();

// initialize process table with fixed size = 5
int gNumberOfProcesses = 0;
struct ProcessTableEntry gProcessTable[5];
int gRunningThread = THREAD_ID_INVALID;

void boot(void *pMainProcess) {
    // keep main process in process table with low priority
    addProcess(pMainProcess, THREAD_MAIN_PRIORITY);
}

void addProcess(void *pProcessFunction, int priority) {
    struct ProcessTableEntry processTableEntry;
    processTableEntry.status = THREAD_STATUS_READY;
    processTableEntry.priority = priority;
    processTableEntry.function = pProcessFunction;

    processTableEntry.threadId = registerNewProcess(processTableEntry);
    startThread(processTableEntry);
}

int registerNewProcess(struct ProcessTableEntry entry) {
    // check process table size
    if(gNumberOfProcesses == sizeof(gProcessTable)){
        extendProcessTable();
    }
    gProcessTable[gNumberOfProcesses] = entry;
    gNumberOfProcesses++;
    return gNumberOfProcesses-1;
}

int startThread(struct ProcessTableEntry processTableEntry) {
    ATOMIC_ON();
    if (setjmp(gProcessTable[processTableEntry.threadId].context) == 0) {
        // current context saved
     	ATOMIC_OFF();
    } else {
        // running here as active Thread
        SP = allocate Stack (Pointer)
        ATOMIC_END();
        gProcessTable[gRunningThread].function();
        killThread();
    }
}