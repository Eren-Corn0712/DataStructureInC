#include "pair.h"
#include<stdlib.h>

Pair* makePair(void* first, void* second)
{
	Pair* pair = (Pair*)malloc(sizeof(Pair));
	if (pair) {
		pair->first = first;
		pair->second = second;
	}
	return pair;
}

void freePair(Pair** pairPtr)
{
	if (pairPtr && *pairPtr) {
		if (!isPairEmpty(*pairPtr)) {
			;
		}
		free(*pairPtr);
		*pairPtr = NULL;
	}
}

void swapPair(Pair* pairA, Pair* pairB)
{
	if (!isPairEmpty(pairA) && !isPairEmpty(pairB)) {
		swap(&(pairA->first), &(pairB->first));
		swap(&(pairA->second), &(pairB->second));
	}
}

void swap(void** x, void** y)
{	
	void* temp = *x;
	*x = *y;
	*y = temp;
}

const void* getFirst(const Pair* pair) {
	return (pair && !isPairEmpty(pair)) ? pair->first : NULL;
}

const void* getSecond(const Pair* pair) {
	return (pair && !isPairEmpty(pair)) ? pair->second : NULL;
}

int isPairEmpty(const Pair* pair)
{
	return (pair->first == NULL || pair->second == NULL);;
}
