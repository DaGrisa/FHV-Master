/*
 * Os.h
 *
 *  Created on: 16. Dez. 2016
 *      Author: daniel
 */

#ifndef OS_H_
#define OS_H_

void boot(void* pMainProcess);
void addProcess(void* pProcessFunction, int priority);

#endif /* OS_H_ */