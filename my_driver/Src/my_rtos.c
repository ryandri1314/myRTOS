/*
 * MY_STRUCT.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */
#include "my_rtos.h"

void MyROTSInit(My_RTOS_Control *myControl) {
	myControl->RTOS_AvailableID = 0;
	myControl->RTOS_Tasks = CreateList();
	myControl->RTOS_ReadyTasks = CreateQueue();
	myControl->RTOS_RunningTask = NULL;
}

void MyDelay(My_RTOS_Control *myControl, uint32_t timeDelay) {
	myControl->RTOS_RunningTask->Task_DelayTicks = timeDelay;
	myControl->RTOS_RunningTask->Task_State = BLOCKED;
}
