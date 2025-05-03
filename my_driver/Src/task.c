/*
 * task.c
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */

#include "task.h"
#include "my_rtos.h"

void MyRTOSCreate(My_RTOS_Control *mRTOS, char *Task_Name, uint8_t Task_Priority) {
	My_RTOS_Task task = malloc(sizeof(My_RTOS_Task));
	if (task) {
		task->Task_Name = Task_Name;
		task->Task_ID = mRTOS->RTOS_AvailableID++;
		task->Task_Priority = Task_Priority;
		task->Task_State = READY;
		task->Task_Function = (void *)Task_Name;
		task->Task_DelayTisks = 0;
	} else {
		error(0);
	}
}
