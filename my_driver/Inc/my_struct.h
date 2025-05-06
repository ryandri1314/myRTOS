/*
 * my_struct.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */
 
#ifndef INC_MY_STRUCT_H_
#define INC_MY_STRUCT_H_

#include <task.h>

struct My_RTOS_Control;
typedef struct My_RTOS_Control My_RTOS_Control;

typedef struct Node {
	struct Node* next;
	My_RTOS_Task* task;
} Node;

typedef struct My_Queue {
	Node *front;
	Node *rear;
} My_Queue;

typedef struct My_List {
	Node *head;
	Node *tail;
} My_List;

typedef struct My_Semaphore {
	uint8_t Se_Count;
	My_RTOS_Task *Se_RunningTask;
	My_Queue Se_WaitingTasks;
} My_Semaphore;

/* Node Function */
Node* CreateNode(My_RTOS_Task *task);

/* Queue Function */
My_Queue* CreateQueue();
void PushQueue(My_Queue *mQueue, My_RTOS_Task *task);
Node* PopQueue(My_Queue *mQueue);

/* List Function */
My_List* CreateList();
void EnList(My_List *mList, My_RTOS_Task *task);
void DeList(My_List *mList, My_RTOS_Task *task);

/* Semaphore Function */
My_Semaphore* CreateSemaphore();
void TakeSemaphore(My_Semaphore *mSe, My_RTOS_Task *task);
void ReleaseSemaphore(My_RTOS_Control *mControl, My_Semaphore *mSe);
 
#endif /* INC_MY_STRUCT_H_ */
