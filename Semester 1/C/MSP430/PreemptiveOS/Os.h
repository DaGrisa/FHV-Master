/*
 * Os.h
 *
 *  Created on: 16. Dez. 2016
 *      Author: daniel
 */

#ifndef OS_H_
#define OS_H_

typedef enum {OS_THREAD_PRIORITY_LOW, OS_THREAD_PRIORITY_MEDIUM, OS_THREAD_PRIORITY_HIGH} os_ThreadPriority;

void os_boot(void* pMainProcess);
void os_addProcess(void* pProcessFunction, os_ThreadPriority priority);

#endif /* OS_H_ */
