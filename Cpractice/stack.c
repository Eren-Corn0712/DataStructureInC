#include"stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h> 

STACK* createSTACK(void)
{
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if (stack) {
		stack->size = 0;
		stack->top = NULL;
	}
	return stack;
}

bool pushStack(STACK* stack, void* dataInPtr)
{
	if (!stack) {
		return false;
	}
	STACK_NODE* newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (newPtr) {
		newPtr->data = dataInPtr;
		newPtr->link = stack->top;
		stack->top = newPtr;
		(stack->size)++;
		return true;
	}
	return false;
}

void* popStack(STACK* stack)
{
	if (isEmptyStack(stack)) {
		return NULL;
	}
	void* dataOutPtr = NULL;
	STACK_NODE* temp = stack->top;

	dataOutPtr = stack->top->data;
	stack->top = stack->top->link;
	free(temp);
	(stack->size)--;
	return dataOutPtr;
}

void* topStack(STACK* stack)
{
	if (isEmptyStack(stack)) {
		return NULL;
	}
	return stack->top->data;
}

bool isEmptyStack(STACK* stack)
{
	return  (!stack || stack->size == 0);
}

int sizeOfStack(STACK* stack)
{
	return (stack ? stack->size : 0);
}

void destroyStack(STACK ** stackPtr)
{
	STACK_NODE* temp;
	if (stackPtr && *stackPtr) {
		STACK* stack = *stackPtr;
		while (stack->top != NULL) {
			temp = stack->top;
			stack->top = stack->top->link;
			free(temp->data);
			free(temp);
		}
		free(stack);
		*stackPtr = NULL; 
	}
}


