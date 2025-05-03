/*
 * MY_STRUCT.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */

/* Queue Function */
My_Queue* CreateQueue() {
	My_Queue queue = malloc(sizeof(My_Queue));
	return queue;
}

void AddQueue(My_RTOS_Control *myControl, My_RTOS_Task *task);

/* List Function */
My_List* CreateList() {
	My_List list = malloc(sizeof(My_List));
	return list;
}
