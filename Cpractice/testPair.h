#pragma once
#ifndef TEST_PAIR
#define TEST_PAIR
#include "CuTest.h"
#include "pair.h"

void TestMakePair(CuTest* tc);
void TestFreePair(CuTest* tc);
void TestSwapPair(CuTest* tc);
void TestGetFirst(CuTest* tc);
void TestGetSecond(CuTest* tc);
void TestIsPairEmpty(CuTest* tc);

CuSuite* TestPair(void);

#endif // !TEST_PAIR

