#pragma once
#ifndef TEST_QUEUE
#define TEST_QUEUE

#include "CuTest.h"
#include "queue.h"

// Helper function to create a queue and enqueue some items for testing
static Queue* setupQueueForTesting(void);


// Test case for createQueue function
void TestCreateQueue(CuTest* tc);

// Test case for destroyQueue function
void TestDestroyQueue(CuTest* tc);

// Test case for enQueue and dequeue functions
void TestEnqueueDequeue(CuTest* tc);

// Test case for queueFront function
void TestQueueFront(CuTest* tc);

// Test case for queueRear function
void TestQueueRear(CuTest* tc);

// Test case for fullQueue function
void TestFullQueue(CuTest* tc);

// Test case for sizeOfQueue function
void TestSizeOfQueue(CuTest* tc);

// Test All of the case for queue
CuSuite* TestQueue(void);
#endif // !TEST_QUEUE
