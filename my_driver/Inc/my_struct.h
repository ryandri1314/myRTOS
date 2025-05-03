/*
 * MY_STRUCT.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */
 
#ifndef INC_MY_STRUCT_H_
#define INC_MY_STRUCT_H_

#include "my_rtos.h"
#include "task.h"

typedef struct {
	struct Node* next;
	My_RTOS_Task task;
} Node;

typedef struct {
	Node *front;
	Node *rear;
} My_Queue;

typedef struct {
	Node *head;
	Node *tail;
} My_List;

/* Queue Function */
My_Queue* CreateQueue();
void PushQueue(My_RTOS_Control *myControl, My_RTOS_Task *task);
My_Queue* PopQueue(My_Queue *queue);

/* List Function */
My_List* CreateList();
void EnList(My_RTOS_Control *myControl, My_RTOS_Task *task);
void DeList(My_RTOS_Control *myControl, My_RTOS_Task *task);
 
#endif /* INC_MY_STRUCT_H_ */
