/*
 * my_rtos.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */
#include <my_rtos.h>

void MyROTSInit(My_RTOS_Control *myControl) {
	myControl->RTOS_AvailableID = 0;
	myControl->RTOS_Tasks = *CreateList();
	myControl->RTOS_ReadyTasks = *CreateQueue();
	myControl->RTOS_BlockedTasks = *CreateList();
	myControl->RTOS_RunningTask = NULL;
}

void MyDelay(My_RTOS_Control *myControl, uint32_t timeDelay) {
	myControl->RTOS_RunningTask->Task_DelayTicks = timeDelay;
	myControl->RTOS_RunningTask->Task_State = BLOCKED;
	EnList(&myControl->RTOS_BlockedTasks, myControl->RTOS_RunningTask);
}

void MyTickHandler(My_RTOS_Control *mControl) {
	Node *curr = mControl->RTOS_BlockedTasks.head;
	Node *prev = NULL;
	while (curr) {
		Node *next = curr->next;
		if (curr->task->Task_DelayTicks > 0) {
			curr->task->Task_DelayTicks--;
		} else if (curr->task->Task_DelayTicks == 0) {
			curr->task->Task_State = READY;
			if (prev == NULL) {
				mControl->RTOS_BlockedTasks.head = next;
			} else {
				prev->next = next;
			}
			if (curr == mControl->RTOS_BlockedTasks.tail) {
				mControl->RTOS_BlockedTasks.tail = prev;
			}
			free(curr);
			curr = NULL;
		}
		if (curr) {
			prev = curr;
		}
		curr = next;
	}
}
