/*
 * my_struct.h
 *
 *  Created on: May 3, 2025
 *      Author: mary_uri
 */

#include <my_rtos.h>

/* Node Function */
Node* CreateNode(My_RTOS_Task *task) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (newNode) {
		newNode->next = NULL;
		newNode->task = task;
		return newNode;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

NodeData* CreateNodeData_U8(uint8_t data, uint8_t taskIDSend, uint8_t taskIDReceive) {
	NodeData* newNode = (NodeData *)malloc(sizeof(NodeData));
	if (newNode) {
		newNode->next = NULL;
		newNode->ReceiveID = taskIDReceive;
		newNode->SendID = taskIDSend;
		newNode->type = TYPE_UINT8;
		newNode->data.u8 = data;
		return newNode;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

NodeData* CreateNodeData_U16(uint16_t data, uint8_t taskIDSend, uint8_t taskIDReceive) {
	NodeData* newNode = (NodeData *)malloc(sizeof(NodeData));
	if (newNode) {
		newNode->next = NULL;
		newNode->ReceiveID = taskIDReceive;
		newNode->SendID = taskIDSend;
		newNode->type = TYPE_UINT8;
		newNode->data.u16 = data;
		return newNode;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

NodeData* CreateNodeData_U32(uint32_t data, uint8_t taskIDSend, uint8_t taskIDReceive) {
	NodeData* newNode = (NodeData *)malloc(sizeof(NodeData));
	if (newNode) {
		newNode->next = NULL;
		newNode->ReceiveID = taskIDReceive;
		newNode->SendID = taskIDSend;
		newNode->type = TYPE_UINT8;
		newNode->data.u32 = data;
		return newNode;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

NodeData* CreateNodeData_F32(float data, uint8_t taskIDSend, uint8_t taskIDReceive) {
	NodeData* newNode = (NodeData *)malloc(sizeof(NodeData));
	if (newNode) {
		newNode->next = NULL;
		newNode->ReceiveID = taskIDReceive;
		newNode->SendID = taskIDSend;
		newNode->type = TYPE_UINT8;
		newNode->data.f32 = data;
		return newNode;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

NodeData* CreateNodeData_DB(double data, uint8_t taskIDSend, uint8_t taskIDReceive) {
	NodeData* newNode = (NodeData *)malloc(sizeof(NodeData));
	if (newNode) {
		newNode->next = NULL;
		newNode->ReceiveID = taskIDReceive;
		newNode->SendID = taskIDSend;
		newNode->type = TYPE_UINT8;
		newNode->data.db = data;
		return newNode;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

NodeData* CreateNodeData_PC(char *data, uint8_t taskIDSend, uint8_t taskIDReceive) {
	NodeData* newNode = (NodeData *)malloc(sizeof(NodeData));
	if (newNode) {
		newNode->next = NULL;
		newNode->ReceiveID = taskIDReceive;
		newNode->SendID = taskIDSend;
		newNode->type = TYPE_UINT8;
		newNode->data.pc = data;
		return newNode;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

/* Queue Function */
My_Queue* CreateQueue() {
	My_Queue* queue = (My_Queue *)malloc(sizeof(My_Queue));
	if (queue) {
		queue->front = NULL;
		queue->rear = NULL;
		return queue;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

void PushQueue(My_Queue *mQueue, My_RTOS_Task *task) {
	if (mQueue->front == NULL) {
	    mQueue->front = CreateNode(task);
	    mQueue->rear = mQueue->front;
	    return;
	}

	Node *tempNode = mQueue->front;
	Node *pushNode = CreateNode(task);
	if (task->Task_Priority > tempNode->task->Task_Priority) {
		pushNode->next = tempNode;
		mQueue->front = pushNode;
		return;
	}
	while (tempNode->next != NULL && tempNode->next->task->Task_Priority < task->Task_Priority) {
		tempNode = tempNode->next;
	}
	pushNode->next = tempNode->next;
	if (pushNode->next == NULL) {
		mQueue->rear = pushNode;
	} else {
		tempNode->next = pushNode;
	}
}

Node* PopQueue(My_Queue *mQueue) {
	if (!mQueue->front) {
		return NULL;
	}
	Node* tempNode = mQueue->front;
	if (mQueue->front == mQueue->rear) {
		mQueue->front = NULL;
		mQueue->rear = mQueue->front;
	}
	mQueue->front = mQueue->front->next;
	tempNode->next = NULL;
	return tempNode;
}

/* List Function */
My_List* CreateList() {
	My_List* list = (My_List *)malloc(sizeof(My_List));
	if (list) {
		list->head = NULL;
		list->tail = NULL;
		return list;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

void EnList(My_List *mList, My_RTOS_Task *task) {
	Node* newNode = CreateNode(task);
	if (newNode) {
		if (mList->head == NULL) {
			mList->head = newNode;
			mList->tail = mList->head;
		} else {
			mList->tail->next = newNode;
			mList->tail = newNode;
		}
	} else {
		 perror("Over memory!");
	}
}

void DeList(My_List *mList, My_RTOS_Task *task) {
	Node* temp = mList->head;
	if (!temp) {
		return;
	}
	if (temp->task->Task_ID == task->Task_ID) {
		mList->head = temp->next;
		free(temp);
		return;
	}
	while (temp) {
		if (temp->next->task->Task_ID == task->Task_ID) {
			Node* deTemp = temp->next;
			temp->next = deTemp->next;
			if (deTemp == mList->tail) {
				mList->tail = temp;
			}
			free(deTemp);
			break;
		}
		temp = temp->next;
	}
}

/* Semaphore Function */
My_Semaphore* CreateSemaphore() {
	My_Semaphore *newSe = (My_Semaphore *)malloc(sizeof(My_Semaphore));
	if (newSe) {
		newSe->Se_Count = 1;
		newSe->Se_RunningTask = NULL;
		newSe->Se_WaitingTasks = *CreateQueue();
		return newSe;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

void TakeSemaphore(My_Semaphore *mSe, My_RTOS_Task *task) {
	if (mSe->Se_Count) {
		mSe->Se_Count = 0;
		mSe->Se_RunningTask = task;
	} else {
		PushQueue(&mSe->Se_WaitingTasks, task);
	}
}

void ReleaseSemaphore(My_RTOS_Control *mControl, My_Semaphore *mSe) {
	mSe->Se_Count = 1;
	mSe->Se_RunningTask = NULL;
	Node *tempNode = PopQueue(&mSe->Se_WaitingTasks);
	if (tempNode) {
		PushQueue(&mControl->RTOS_ReadyTasks, tempNode->task);
	}
	free(tempNode);
}

/* MessQueue Function */
My_MessQueue* CreateMessQueue() {
	My_MessQueue *mQueue = (My_MessQueue *)malloc(sizeof(My_MessQueue));
	if (mQueue) {
		mQueue->front = NULL;
		mQueue->rear = NULL;
		mQueue->WaitingTasks = *CreateQueue();
		return mQueue;
	} else {
		 perror("Over memory!");
	}
	return NULL;
}

void MessQueueSend_U8(My_MessQueue *mDataQueue, uint8_t data, uint8_t taskIDSend, uint8_t taskIDReceive) {

}

void MessQueueSend_U16(My_MessQueue *mDataQueue, uint16_t data, uint8_t taskIDSend, uint8_t taskIDReceive) {

}

void MessQueueSend_U32(My_MessQueue *mDataQueue, uint32_t data, uint8_t taskIDSend, uint8_t taskIDReceive) {

}

void MessQueueSend_F32(My_MessQueue *mDataQueue, float data, uint8_t taskIDSend, uint8_t taskIDReceive) {

}

void MessQueueSend_DB(My_MessQueue *mDataQueue, double data, uint8_t taskIDSend, uint8_t taskIDReceive) {

}

void MessQueueSend_PC(My_MessQueue *mDataQueue, char* data, uint8_t taskIDSend, uint8_t taskIDReceive) {

}

NodeData* MessQueueReceive(My_MessQueue *mDataQueue, uint8_t taskIDSend, uint8_t taskIDReceive) {

}
