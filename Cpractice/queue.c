#include"stack.h"
#include<stdlib.h>
#include<stdbool.h>
#include "queue.h"

QUEUE* createQueue(void)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue) {
		queue->front = NULL;
		queue->rear = NULL;
		queue->size = 0;
	}
	return queue;
}

void destroyQueue(QUEUE** queuePtr)
{
	if (queuePtr&& *queuePtr) {
		while (!isEmptyQueue(*queuePtr))
		{
			void* item;
			dequeue(*queuePtr, &item);
		}
		free(*queuePtr);
		*queuePtr = NULL;
	}
	return;
}

bool enQueue(QUEUE* queue, void* itemPtr)
{
	QUEUE_NODE* newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

	if (!queue || !newPtr) {
		return false;
	}
	newPtr->dataPtr = itemPtr;
	newPtr->next = NULL;
	
	if (queue->size == 0) {
		queue->front = newPtr;
	}
	else {
		queue->rear->next = newPtr;
	}
	queue->rear = newPtr;
	(queue->size)++;
	return true;
}

bool dequeue(QUEUE* queue, void** itemPtr)
{
	QUEUE_NODE* deleteLoc;
	if (isEmptyQueue(queue)) {
		return false;
	}
	*itemPtr = queue->front->dataPtr;
	deleteLoc = queue->front;

	if (sizeOfQueue(queue) == 1) {
		queue->front = queue->rear = NULL;
	}
	else {
		queue->front = queue->front->next;
	}
	(queue->size)--;
	free(deleteLoc);
	return true;
}

bool queueFront(QUEUE* queue, void** itemPtr)
{
	if (isEmptyQueue(queue)) {
		return false;
	}
	*itemPtr = queue->front->dataPtr;
	return true;
}

bool queueRear(QUEUE* queue, void** itemPtr)
{
	if (isEmptyQueue(queue)) {
		return false;
	}
	*itemPtr = queue->rear->dataPtr;
	return true;
}

bool fullQueue(QUEUE* queue)
{
	QUEUE_NODE* temp = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	if (temp) {
		free(temp);
		return true;
	}
	return false;
}

bool isEmptyQueue(QUEUE* queue)
{
	return (queue == NULL || queue->size == 0);
}

int sizeOfQueue(QUEUE* queue)
{
	return (queue ? queue->size : 0);
}
