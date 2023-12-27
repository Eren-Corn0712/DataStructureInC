#pragma once
#ifndef PAIR_H
#define PAIR_H

// Forward declaration
typedef struct pair Pair;


struct pair
{
	void* first;
	void* second;
};

// Prototype Declarations
Pair* makePair(void* first, void* second);
void freePair(Pair ** pairPtr);

void swapPair(Pair* pairA, Pair* pairB);
static void swap(void** x, void** y);

const void* getFirst(const Pair* pair);
const void* getSecond(const Pair* pair);
int isPairEmpty(const Pair* pair);

#endif // !PAIR_H
