#include "CuTest.h"
#include "pair.h"
#include "testPair.h"

void TestMakePair(CuTest* tc)
{
    int firstValue = 42;
    int secondValue = 99;

    Pair* pair = makePair(&firstValue, &secondValue);

    CuAssertPtrNotNull(tc, pair);
    CuAssertPtrEquals(tc, &firstValue, getFirst(pair));
    CuAssertPtrEquals(tc, &secondValue, getSecond(pair));

    freePair(&pair); // Do not free elements
}

void TestFreePair(CuTest* tc)
{
    int firstValue = 42;
    int secondValue = 99;

    Pair* pair = makePair(&firstValue, &secondValue);

    freePair(&pair); // Free elements

    CuAssertPtrEquals(tc, NULL, pair);
}

void TestSwapPair(CuTest* tc)
{
    int firstValueA = 42;
    char secondValueA = 'a';
    Pair* pairA = makePair(&firstValueA, &secondValueA);

    int firstValueB = 11;
    char secondValueB = 'b';
    Pair* pairB = makePair(&firstValueB, &secondValueB);

    swapPair(pairA, pairB);

    CuAssertPtrEquals(tc, &firstValueB, getFirst(pairA));
    CuAssertPtrEquals(tc, &secondValueB, getSecond(pairA));
    CuAssertPtrEquals(tc, &firstValueA, getFirst(pairB));
    CuAssertPtrEquals(tc, &secondValueA, getSecond(pairB));

    freePair(&pairA); // Free elements
    freePair(&pairB); // Free elements
}

void TestGetFirst(CuTest* tc)
{
    int firstValue = 42;
    int secondValue = 99;
    Pair* pair = makePair(&firstValue, &secondValue);

    CuAssertPtrEquals(tc, &firstValue, getFirst(pair));

    freePair(&pair, 1); // Free elements
}

void TestGetSecond(CuTest* tc)
{
    int firstValue = 42;
    int secondValue = 99;
    Pair* pair = makePair(&firstValue, &secondValue);

    CuAssertPtrEquals(tc, &secondValue, getSecond(pair));

    freePair(&pair); // Free elements
}

void TestIsPairEmpty(CuTest* tc)
{
    int firstValue = 42;
    int secondValue = 99;
    Pair* nonEmptyPair = makePair(&firstValue, &secondValue);
    Pair* emptyPair = makePair(NULL, &secondValue);

    CuAssertIntEquals(tc, 0, isPairEmpty(nonEmptyPair));
    CuAssertIntEquals(tc, 1, isPairEmpty(emptyPair));

    freePair(&nonEmptyPair); // Free elements
    freePair(&emptyPair);    // Do not free elements
}

CuSuite* TestPair(void)
{
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestMakePair);
    SUITE_ADD_TEST(suite, TestFreePair);
    SUITE_ADD_TEST(suite, TestSwapPair);
    SUITE_ADD_TEST(suite, TestGetFirst);
    SUITE_ADD_TEST(suite, TestGetSecond);
    SUITE_ADD_TEST(suite, TestIsPairEmpty);

    return suite;
}
