#include <assert.h>
#include "stack.h"

int main() {
    // 測試 createSTACK 和 destroyStack
    STACK* stack = createSTACK();
    assert(stack != NULL);
    assert(isEmptyStack(stack));
    assert(sizeOfStack(stack) == 0);

    // 測試 pushStack
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

    // 測試 topStack
    int* topData = (int*)topStack(stack);
    assert(topData != NULL);
    assert(*topData == data3);

    // 測試 popStack
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

    // 測試 topStack 空堆疊情況
    assert(topStack(stack) == NULL);

    // 釋放堆疊
    destroyStack(&stack);
    assert(stack == NULL);

    return 0;
}
