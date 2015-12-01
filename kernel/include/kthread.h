/*
 * kthread.h
 *
 *  Created on: Apr 23, 2015
 *      Author: mwkurian
 */

#ifndef KERNEL_INCLUDE_KTHREAD_H_
#define KERNEL_INCLUDE_KTHREAD_H_

#include <stdint.h>
#include "process.h"

typedef void (*kthread_callback_handler)();

typedef struct kthread_handle {
    uint32_t parent_pid;
    int niceness;
    int state;
    kthread_callback_handler cb_handler;
} kthread_handle;


typedef struct {
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;

	//banked registers
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;
	uint32_t R12;
	uint32_t R13; //corresponds to the SP; do we need both?
	uint32_t R14;
	uint32_t R15; //corresponds to the PC; do we need both?

	//Control data
	//int priority_value;
	//uint32_t elapsed_time;
	//uint32_t EFLAG;
	//uint32_t* process_relations
	//uint32_t total_cpu_time;

	//CPU state data
	uint32_t SPSR;
	uint32_t PC;
	pcb* pcb_pointer;
} thread_t;

//(void (*)(void *))
int kthread_create(thread_t* ptr, void *(*func)(void*), void *arg);

#endif /* KERNEL_INCLUDE_KTHREAD_H_ */
