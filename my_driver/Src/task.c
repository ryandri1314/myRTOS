/*
 * task.c
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */

#include <my_rtos.h>

void MyRTOSTaskCreate(My_RTOS_Control *mRTOS, char *Task_Name, uint8_t Task_Priority, void (*mFunc)(void)) {
	My_RTOS_Task* task = (My_RTOS_Task *)malloc(sizeof(My_RTOS_Task));
	if (task) {
		task->Task_Name = Task_Name;
		task->Task_ID = mRTOS->RTOS_AvailableID++;
		task->Task_Priority = Task_Priority;
		task->Task_State = READY;
		task->Task_Func = mFunc;
		task->Task_DelayTicks = 0;

		EnList(&mRTOS->RTOS_Tasks, task);
		PushQueue(&mRTOS->RTOS_ReadyTasks, task);
	} else {
		perror("Over memory!");
	}
}
