/*
 * my_struct.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */
 
#ifndef INC_MY_STRUCT_H_
#define INC_MY_STRUCT_H_

#include <task.h>

typedef enum {
	TYPE_UINT8,
	TYPE_UINT16,
	TYPE_UINT32,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PCHAR,
} DataType;

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

typedef struct NodeData {
	struct NodeData *next;
	uint8_t SendID;
	uint8_t ReceiveID;
	DataType type;
	union {
		uint8_t		u8;
		uint16_t	u16;
		uint32_t	u32;
		double		db;
		float		f32;
		char*		pc;
	} data;
} NodeData;

typedef struct My_MessQueue {
	NodeData *front;
	NodeData *rear;
	My_Queue WaitingTasks;
} My_MessQueue;

/* Node & NodeData Function */
Node* CreateNode(My_RTOS_Task *task);
NodeData* CreateNodeData_U8(uint8_t data, uint8_t taskIDSend, uint8_t taskIDReceive);
NodeData* CreateNodeData_U16(uint16_t data, uint8_t taskIDSend, uint8_t taskIDReceive);
NodeData* CreateNodeData_U32(uint32_t data, uint8_t taskIDSend, uint8_t taskIDReceive);
NodeData* CreateNodeData_F32(float data, uint8_t taskIDSend, uint8_t taskIDReceive);
NodeData* CreateNodeData_DB(double data, uint8_t taskIDSend, uint8_t taskIDReceive);
NodeData* CreateNodeData_PC(char *data, uint8_t taskIDSend, uint8_t taskIDReceive);

/* Queue Function */
My_Queue* CreateQueue();
void PushQueue(My_Queue *mQueue, My_RTOS_Task *task);
Node* PopQueue(My_Queue *mQueue);
void PushMessQueue(My_MessQueue *mMessQueue, NodeData *mNode);
NodeData* PopMessQueue(My_MessQueue *mMessQueue);

/* List Function */
My_List* CreateList();
void EnList(My_List *mList, My_RTOS_Task *task);
void DeList(My_List *mList, My_RTOS_Task *task);

/* Semaphore Function */
My_Semaphore* CreateSemaphore();
void TakeSemaphore(My_Semaphore *mSe, My_RTOS_Task *task);
void ReleaseSemaphore(My_RTOS_Control *mControl, My_Semaphore *mSe);

/* MessQueue Function */
My_MessQueue* CreateMessQueue();
void MessQueueSend_U8(My_MessQueue *mDataQueue, uint8_t data, uint8_t taskIDSend, uint8_t taskIDReceive);
void MessQueueSend_U16(My_MessQueue *mDataQueue, uint16_t data, uint8_t taskIDSend, uint8_t taskIDReceive);
void MessQueueSend_U32(My_MessQueue *mDataQueue, uint32_t data, uint8_t taskIDSend, uint8_t taskIDReceive);
void MessQueueSend_F32(My_MessQueue *mDataQueue, float data, uint8_t taskIDSend, uint8_t taskIDReceive);
void MessQueueSend_DB(My_MessQueue *mDataQueue, double data, uint8_t taskIDSend, uint8_t taskIDReceive);
void MessQueueSend_PC(My_MessQueue *mDataQueue, char* data, uint8_t taskIDSend, uint8_t taskIDReceive);
NodeData* MessQueueReceive(My_MessQueue *mDataQueue, My_RTOS_Task *task, uint8_t taskIDSend);
 
#endif /* INC_MY_STRUCT_H_ */
