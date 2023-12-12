#include "CuTest.h"
#include "stack.h"
#include "testStack.h"


void TestCreateStack(CuTest* tc) {
    Stack* stack = createStack();
    CuAssertPtrNotNull(tc, stack);
}


void TestCreateDestroyStack(CuTest* tc)
{
    Stack* stack = createStack();
    CuAssertPtrNotNull(tc, stack);
    CuAssertTrue(tc, isEmptyStack(stack));
    CuAssertIntEquals(tc, 0, sizeOfStack(stack));

    destroyStack(&stack);
    CuAssertPtrEquals(tc, NULL, stack);
}

void TestPushPopStack(CuTest* tc)
{
    Stack* stack = createStack();
    int a = 42;
    char b = 'a';

    CuAssertTrue(tc, pushStack(stack, &a));
    CuAssertTrue(tc, pushStack(stack, &b));

    CuAssertIntEquals(tc, 2, sizeOfStack(stack));

    void* poppedData = (char*)popStack(stack);
    CuAssertPtrNotNull(tc, poppedData);

    CuAssertIntEquals(tc, b, *(char*)poppedData);
    CuAssertIntEquals(tc, 1, sizeOfStack(stack));

    poppedData = popStack(stack);
    CuAssertIntEquals(tc, a, *(int*)poppedData);
    CuAssertIntEquals(tc, 0, sizeOfStack(stack));
    destroyStack(&stack);
}


CuSuite* TestStack(void) {
    CuSuite* suite = CuSuiteNew();
    // Add each test case to the suite
    SUITE_ADD_TEST(suite, TestCreateStack);
    SUITE_ADD_TEST(suite, TestPushPopStack);
    return suite;
}