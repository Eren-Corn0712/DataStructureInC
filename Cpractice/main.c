#include <assert.h>
#include "stack.h"

int main() {
    // ���� createSTACK �M destroyStack
    STACK* stack = createSTACK();
    assert(stack != NULL);
    assert(isEmptyStack(stack));
    assert(sizeOfStack(stack) == 0);

    // ���� pushStack
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    assert(pushStack(stack, &data1));
    assert(!isEmptyStack(stack));
    assert(sizeOfStack(stack) == 1);

    assert(pushStack(stack, &data2));
    assert(sizeOfStack(stack) == 2);

    assert(pushStack(stack, &data3));
    assert(sizeOfStack(stack) == 3);

    // ���� topStack
    int* topData = (int*)topStack(stack);
    assert(topData != NULL);
    assert(*topData == data3);

    // ���� popStack
    int* poppedData = (int*)popStack(stack);
    assert(poppedData != NULL);
    assert(*poppedData == data3);
    assert(sizeOfStack(stack) == 2);

    poppedData = (int*)popStack(stack);
    assert(poppedData != NULL);
    assert(*poppedData == data2);
    assert(sizeOfStack(stack) == 1);

    poppedData = (int*)popStack(stack);
    assert(poppedData != NULL);
    assert(*poppedData == data1);
    assert(isEmptyStack(stack));

    // ���� topStack �Ű��|���p
    assert(topStack(stack) == NULL);

    // ������|
    destroyStack(&stack);
    assert(stack == NULL);

    return 0;
}
