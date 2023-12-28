#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<stdbool.h>

// Forward declaration
typedef struct queue_node QueueNode;
typedef struct queue Queue;


// Queue ADT Type Definitions
struct queue_node
{
    void* dataPtr;
    struct queue_node* next;
};

struct queue
{
    QueueNode* front;
    QueueNode* rear;
    int size;
};

// Prototype Declarations
Queue* createQueue(void);
void destroyQueue(Queue** queuePtr);

bool enQueue(Queue* queue, void* itemPtr);
bool dequeue(Queue* queue, void** itemPtr);
bool queueFront(Queue* queue, void** itemPtr);
bool queueRear(Queue* queue, void** itemPtr);

bool fullQueue(const Queue * queue);
bool isEmptyQueue(const Queue * queue);
int sizeOfQueue(const Queue * queue);

#endif // !QUEUE_H
