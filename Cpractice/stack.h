#pragma once
#ifndef STACK_H
#define STACK_H
#include<stdbool.h>

/*forward declaration*/
typedef struct stack STACK;
typedef struct stack_node STACK_NODE;

struct stack {
	STACK_NODE* top;
	int size;
};

struct stack_node {
	void* data;
	STACK_NODE* link;
};

STACK* createSTACK(void);
void destroyStack(STACK** stackPtr);

bool pushStack(STACK* stack, void* dataInPtr);
void* popStack(STACK* stack);
void* topStack(STACK* stack);

bool isEmptyStack(STACK* stack);
int	sizeOfStack(STACK* stack);


#endif // !STACK_H
