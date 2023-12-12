#include"stack.h"
#include<stdlib.h>
#include<stdbool.h>
#include "queue.h"

/*
	Description: Creates a new empty queue.

	Parameters:
		- None

	Returns:
		- A pointer to the newly created Queue struct. Returns NULL if memory allocation fails.
*/
Queue* createQueue(void)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue) {
		queue->front = NULL;
		queue->rear = NULL;
		queue->size = 0;
	}
	return queue;
}

/*
	Description: Destroys the queue, freeing allocated memory.

	Parameters:
		- queuePtr: A pointer to a pointer to the Queue struct.

	Returns:
		- None
*/
void destroyQueue(Queue** queuePtr)
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

/*
	Description: Enqueues an item to the rear of the queue.

	Parameters:
		- queue: A pointer to the Queue struct.
		- itemPtr: A pointer to the data to be enqueued.

	Returns:
		- true if the item is enqueued successfully, false if memory allocation fails.
*/
bool enQueue(Queue* queue, void* itemPtr)
{
	QueueNode* newPtr = (QueueNode*)malloc(sizeof(QueueNode));

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

/*
	Description: Dequeues an item from the front of the queue.

	Parameters:
		- queue: A pointer to the Queue struct.
		- itemPtr: A pointer to store the dequeued item.

	Returns:
		- true if an item is dequeued successfully, false if the queue is empty.
*/
bool dequeue(Queue* queue, void** itemPtr)
{
	QueueNode* deleteLoc;
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

/*
	Description: Retrieves the item at the front of the queue without removing it.

	Parameters:
		- queue: A pointer to the Queue struct.
		- itemPtr: A pointer to store the retrieved item.

	Returns:
		- true if successful, false if the queue is empty.
*/
bool queueFront(Queue* queue, void** itemPtr)
{
	if (isEmptyQueue(queue)) {
		return false;
	}
	*itemPtr = queue->front->dataPtr;
	return true;
}

/*
	Description: Retrieves the item at the rear of the queue without removing it.

	Parameters:
		- queue: A pointer to the Queue struct.
		- itemPtr: A pointer to store the retrieved item.

	Returns:
		- true if successful, false if the queue is empty.
*/
bool queueRear(Queue* queue, void** itemPtr)
{
	if (isEmptyQueue(queue)) {
		return false;
	}
	*itemPtr = queue->rear->dataPtr;
	return true;
}

bool fullQueue(Queue* queue)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp) {
		free(temp);
		return false;
	}
	return true;
}

/*
	Description: Checks if the queue is empty.

	Parameters:
		- queue: A pointer to the Queue struct.

	Returns:
		- true if the queue is empty (NULL or size is 0), false otherwise.
*/
bool isEmptyQueue(Queue* queue)
{
	return (queue == NULL || queue->size == 0);
}

/*
	Description: Retrieves the current size of the queue.

	Parameters:
		- queue: A pointer to the Queue struct.

	Returns:
		- The size of the queue. Returns 0 if the queue is NULL.
*/
int sizeOfQueue(Queue* queue)
{
	return (queue != NULL ? queue->size : 0);
}
