#include "CuTest.h"
#include "queue.h"
#include "testQueue.h"

// Helper function to create a queue and enqueue some items for testing
static Queue* setupQueueForTesting(void) {
    Queue* queue = createQueue();
    enQueue(queue, (int*)1);
    enQueue(queue, (int*)2);
    enQueue(queue, (int*)3);
    return queue;
}

// Test case for createQueue function
void TestCreateQueue(CuTest* tc) {
    Queue* queue = createQueue();
    CuAssertPtrNotNull(tc, queue);
    CuAssertPtrEquals(tc, NULL, queue->front);
    CuAssertPtrEquals(tc, NULL, queue->rear);
    CuAssertIntEquals(tc, 0, queue->size);
    destroyQueue(&queue);
}

// Test case for destroyQueue function
void TestDestroyQueue(CuTest* tc) {
    Queue* queue = setupQueueForTesting();
    destroyQueue(&queue);
    CuAssertPtrEquals(tc, NULL, queue);
}

// Test case for enQueue and dequeue functions
void TestEnqueueDequeue(CuTest* tc) {
    Queue* queue = setupQueueForTesting();

    // Dequeue items and check if they match the expected values
    void* item;
    CuAssertTrue(tc, dequeue(queue, &item));
    CuAssertIntEquals(tc, 1, (int)item);

    CuAssertTrue(tc, dequeue(queue, &item));
    CuAssertIntEquals(tc, 2, (int)item);

    CuAssertTrue(tc, dequeue(queue, &item));
    CuAssertIntEquals(tc, 3, (int)item);

    // After dequeueing all items, the queue should be empty
    CuAssertTrue(tc, isEmptyQueue(queue));

    destroyQueue(&queue);
}

// Test case for queueFront function
void TestQueueFront(CuTest* tc) {
    Queue* queue = setupQueueForTesting();

    void* item;
    CuAssertTrue(tc, queueFront(queue, &item));
    CuAssertIntEquals(tc, 1, (int)item);

    destroyQueue(&queue);
}

// Test case for queueRear function
void TestQueueRear(CuTest* tc) {
    Queue* queue = setupQueueForTesting();

    void* item;
    CuAssertTrue(tc, queueRear(queue, &item));
    CuAssertIntEquals(tc, 3, (int)item);

    destroyQueue(&queue);
}

// Test case for fullQueue function
void TestFullQueue(CuTest* tc) {
    Queue* queue = setupQueueForTesting();
    CuAssertTrue(tc, !fullQueue(queue));
    destroyQueue(&queue);
}

// Test case for sizeOfQueue function
void TestSizeOfQueue(CuTest* tc) {
    Queue* queue = setupQueueForTesting();
    CuAssertIntEquals(tc, 3, sizeOfQueue(queue));
    destroyQueue(&queue);
}

CuSuite* TestQueue(void)
{
    CuSuite* suite = CuSuiteNew();
    // Add each test case to the suite
    SUITE_ADD_TEST(suite, TestCreateQueue);
    SUITE_ADD_TEST(suite, TestDestroyQueue);
    SUITE_ADD_TEST(suite, TestEnqueueDequeue);
    SUITE_ADD_TEST(suite, TestQueueFront);
    SUITE_ADD_TEST(suite, TestQueueRear);
    SUITE_ADD_TEST(suite, TestFullQueue);
    SUITE_ADD_TEST(suite, TestSizeOfQueue);

    return suite;
}
