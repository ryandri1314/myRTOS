/*
 * task.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_

#include <stdint.h>
#include "my_rtos.h"

/* Task's state */
#define RUNNING		1
#define READY		2
#define BLOCKED		3
#define SUSPEND		0

typedef struct {
	char*		Task_Name;
	uint8_t 	Task_ID;
	uint8_t 	Task_Priority;
	uint8_t 	Task_State;
	void 		(*Task_Func)(void);
	uint32_t 	Task_DelayTicks;
} My_RTOS_Task;

/* Initial Function */
void MyRTOSCreate(My_RTOS_Control *mRTOS, char *Task_Name, uint8_t Task_Priority);

#endif /* INC_TASK_H_ */
