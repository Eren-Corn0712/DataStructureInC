#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<stdbool.h>

/*forward declaration*/
typedef struct queue_node QUEUE_NODE;
typedef struct queue QUEUE;

/*Queue ADT Type Defintions*/
struct queue_node
{
	void* dataPtr;
	struct queue_node* next;
};

struct queue
{
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int size;
};

//Prototype Declarations
QUEUE* createQueue(void);
void destroyQueue(QUEUE** queuePtr);

bool enQueue(QUEUE* queue, void* itemPtr);
bool dequeue(QUEUE* queue, void** itemPtr);
bool queueFront(QUEUE* queue, void** itemPtr);
bool queueRear(QUEUE* queue, void** itemPtr);

bool fullQueue(QUEUE* queue);
bool isEmptyQueue(QUEUE* queue);
int sizeOfQueue(QUEUE* queue);

#endif // !QUEUE_H
