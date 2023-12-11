#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "queue.h"

// Define a test structure that includes a test function and a description
typedef struct {
    void (*testFunc)(void);
    const char* description;
} Test;

// Test function prototypes
void test_create_enqueue_dequeue(void);
void test_front_rear(void);
void test_isEmpty_size(void);

// Test suite containing all test functions
Test tests[] = {
    {test_create_enqueue_dequeue, "Test create, enqueue, and dequeue functions"},
    {test_front_rear, "Test front and rear functions"},
    {test_isEmpty_size, "Test isEmptyQueue and sizeOfQueue functions"},
    // Add more tests as needed
    {NULL, NULL} // End marker
};

// Main test function
int main(void) {
    for (int i = 0; tests[i].testFunc != NULL; ++i) {
        printf("Running test: %s\n", tests[i].description);
        tests[i].testFunc();
        printf("Test passed!\n\n");
    }

    printf("All tests passed successfully!\n");

    return 0;
}

// Actual test functions
void test_create_enqueue_dequeue(void) {
    QUEUE* myQueue = createQueue();
    assert(myQueue != NULL);

    int data1 = 42;
    int data2 = 84;

    assert(enQueue(myQueue, &data1));
    assert(enQueue(myQueue, &data2));

    int* dequeuedData;
    assert(dequeue(myQueue, (void**)&dequeuedData) && *dequeuedData == data1);

    destroyQueue(&myQueue);
}

void test_front_rear(void) {
    QUEUE* myQueue = createQueue();
    assert(myQueue != NULL);

    int data1 = 42;

    assert(enQueue(myQueue, &data1));

    int* frontData;
    assert(queueFront(myQueue, (void**)&frontData) && *frontData == data1);

    int* rearData;
    assert(queueRear(myQueue, (void**)&rearData) && *rearData == data1);

    destroyQueue(&myQueue);
}

void test_isEmpty_size(void) {
    QUEUE* myQueue = createQueue();
    assert(myQueue != NULL);

    assert(isEmptyQueue(myQueue) && sizeOfQueue(myQueue) == 0);

    int data1 = 42;
    assert(enQueue(myQueue, &data1));

    assert(!isEmptyQueue(myQueue) && sizeOfQueue(myQueue) == 1);

    destroyQueue(&myQueue);
}
