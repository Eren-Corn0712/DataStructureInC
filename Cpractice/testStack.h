#pragma once
#ifndef TEST_STACK
#define TEST_STACK

#include "CuTest.h"
#include "stack.h"

void TestCreateDestroyStack(CuTest* tc);
void TestPushPopStack(CuTest* tc);
CuSuite* TestStack(void);

#endif // !TEST_STACK
