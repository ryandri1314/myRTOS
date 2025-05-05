/*
 * my_rtos.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */

#ifndef INC_MY_RTOS_H_
#define INC_MY_RTOS_H_

#include <my_struct.h>
#include <task.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct My_RTOS_Control {
	uint8_t RTOS_AvailableID;
	My_List RTOS_Tasks;
	My_List RTOS_BlockedTasks;
	My_Queue RTOS_ReadyTasks;
	My_RTOS_Task *RTOS_RunningTask;
} My_RTOS_Control;

/* Function */
void MyROTSInit(My_RTOS_Control *myControl);
void MyDelay(My_RTOS_Control *myControl, uint32_t timeDelay);
void MyTickHandler(My_RTOS_Control *mControl);

#endif /* INC_MY_RTOS_H_ */
