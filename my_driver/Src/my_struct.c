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
	while (tempNode->next != NULL && tempNode->next->task->Task_Priority < task->Task_Priority) {
		tempNode = tempNode->next;
	}
	Node *pushNode = CreateNode(task);
	pushNode->next = tempNode->next;
	if (pushNode->next == NULL) {
		mQueue->rear = pushNode;
	} else {
		tempNode->next = pushNode;
	}
}

Node* PopQueue(My_Queue *mQueue) {
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
