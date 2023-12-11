#pragma once
#ifndef STACK_H
#define STACK_H
#include<stdbool.h>
typedef struct stack STACK;
typedef struct stack_node STACK_NODE;

struct stack {
	int size;
	STACK_NODE* top;
};

struct stack_node {
	void* data;
	STACK_NODE* link;
};

STACK* createSTACK(void);

bool pushStack(STACK* stack, void* dataInPtr);
void* popStack(STACK* stack);
void* topStack(STACK* stack);
bool isEmptyStack(STACK* stack);
int	sizeOfStack(STACK* stack);
void destroyStack(STACK ** stackPtr);

#endif // !STACK_H
