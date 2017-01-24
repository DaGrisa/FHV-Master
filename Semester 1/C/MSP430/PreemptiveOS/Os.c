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

#define THREAD_MAIN_PRIORITY    10

typedef enum {OS_THREAD_STATUS_READY, OS_THREAD_STATUS_RUN} os_ThreadStatus;

typedef int (*threadFunction)();

struct os_ProcessTableEntry {
    int threadId;
    os_ThreadStatus status;
    jmp_buf context;
    os_ThreadPriority priority;
    threadFunction function;
};

void os_registerNewProcess(struct os_ProcessTableEntry entry);

// initialize process table with fixed size = 5
int gNumberOfProcesses = 0;
struct os_ProcessTableEntry gProcessTable[5];
int gRunningThread = THREAD_ID_INVALID;

void os_boot(void *pMainProcess) {
    // keep main process in process table with low priority
    os_addProcess(pMainProcess, OS_THREAD_PRIORITY_LOW);
}

void os_addProcess(void *pProcessFunction, os_ThreadPriority priority) {
    struct ProcessTableEntry processTableEntry;
    processTableEntry.status = OS_THREAD_STATUS_READY;
    processTableEntry.priority = priority;
    processTableEntry.function = pProcessFunction;

    processTableEntry.threadId = os_registerNewProcess(processTableEntry);
    os_startThread(processTableEntry);
}

int os_registerNewProcess(struct os_ProcessTableEntry entry) {
    // check process table size
    if(gNumberOfProcesses == sizeof(gProcessTable)){
        os_extendProcessTable();
    }
    gProcessTable[gNumberOfProcesses] = entry;
    gNumberOfProcesses++;
    return gNumberOfProcesses-1;
}

int os_startThread(struct os_ProcessTableEntry processTableEntry) {
    ATOMIC_ON();
    if (setjmp(gProcessTable[processTableEntry.threadId].context) == 0) {
        // current context saved
     	ATOMIC_OFF();
    } else {
        // running here as active Thread
        SP = allocate Stack (Pointer)
        ATOMIC_OFF();
        gProcessTable[gRunningThread].function();
        killThread();
    }
}
