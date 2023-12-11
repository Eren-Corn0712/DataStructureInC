#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "queue.h"
#include "stack.h"
// Define a test structure that includes a test function and a description
typedef struct {
    void (*testFunc)(void);
    const char* description;
} Test;

// Test function prototypes
void test_create_push_pop_destroy(void);
void test_empty_stack(void);
void test_create_enqueue_dequeue(void);
void test_front_rear(void);
void test_isEmpty_size(void);

// Test suite containing all test functions
Test tests[] = {
    {test_create_enqueue_dequeue, "Test create, enqueue, and dequeue functions."},
    {test_front_rear, "Test front and rear functions."},
    {test_isEmpty_size, "Test isEmptyQueue and sizeOfQueue functions."},
    {test_create_push_pop_destroy, "Test create, pop, push, destroy stack functions."},
    {test_empty_stack, "Test isEmptyStack functions."},
    
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


void test_create_push_pop_destroy(void) {
    // Test createSTACK and pushStack
    STACK* myStack = createSTACK();
    assert(myStack != NULL);

    int data1 = 42;
    int data2 = 84;

    assert(pushStack(myStack, &data1));
    assert(pushStack(myStack, &data2));

    // Test topStack
    int* topData = (int*)topStack(myStack);
    assert(topData != NULL && *topData == data2);

    // Test popStack
    int* poppedData1 = (int*)popStack(myStack);
    assert(poppedData1 != NULL && *poppedData1 == data2);

    int* poppedData2 = (int*)popStack(myStack);
    assert(poppedData2 != NULL && *poppedData2 == data1);

    // Test isEmptyStack and sizeOfStack
    assert(isEmptyStack(myStack));
    assert(sizeOfStack(myStack) == 0);

    // Test destroyStack
    destroyStack(&myStack);
    assert(myStack == NULL);
}

void test_empty_stack(void) {
    // Test createSTACK with an empty stack
    STACK* myStack = createSTACK();
    assert(myStack != NULL);

    // Test isEmptyStack and sizeOfStack for an empty stack
    assert(isEmptyStack(myStack));
    assert(sizeOfStack(myStack) == 0);

    // Test popStack and topStack for an empty stack
    assert(popStack(myStack) == NULL);
    assert(topStack(myStack) == NULL);

    // Test destroyStack for an empty stack
    destroyStack(&myStack);
    assert(myStack == NULL);
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
