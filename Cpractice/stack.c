#include"stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h> 

/*
    Description: Creates a new stack and allocates memory for it.

    Returns:
        - A pointer to the newly created stack, or NULL if memory allocation fails.
*/
Stack* createStack(void)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack) {
		stack->size = 0;
		stack->top = NULL;
	}
	return stack;
}

/*
	Description: Deallocates the resources occupied by the stack and sets the pointer to NULL.

	Parameters:
		- stackPtr: Double pointer to the stack, pointing to the pointer to the stack.
*/
void freeStack(Stack** stackPtr)
{
	if (stackPtr && *stackPtr) {
		while (!isEmptyStack(*stackPtr)) {
			popStack(*stackPtr);
		}
		free(*stackPtr);
		*stackPtr = NULL;
	}
	return;
}

/*
	Description: Deallocates the resources occupied by the stack and sets the pointer to NULL.

	Parameters:
		- stackPtr: Double pointer to the stack, pointing to the pointer to the stack.
*/
bool pushStack(Stack* stack, void* dataInPtr)
{
	StackNode* newPtr = (StackNode*)malloc(sizeof(StackNode));
	if (!stack || !newPtr) {
		return false;
	}

	newPtr->data = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;
	(stack->size)++;
	return true;
}

/*
	Description: Removes and returns the top element from the stack.

	Parameters:
		- stack: Pointer to the stack from which the element will be popped.

	Returns:
		- A pointer to the data of the popped element, or NULL if the stack is empty.
*/
void* popStack(Stack* stack)
{
	if (isEmptyStack(stack)) {
		return NULL;
	}
	void* dataOutPtr = NULL;
	StackNode* temp = stack->top;

	dataOutPtr = stack->top->data;
	stack->top = stack->top->link;
	free(temp);
	(stack->size)--;
	return dataOutPtr;
}

/*
	Description: Returns the data of the element at the top of the stack without removing it.

	Parameters:
		- stack: Pointer to the stack for which the top element's data will be retrieved.

	Returns:
		- A pointer to the data of the top element, or NULL if the stack is empty.
*/
void* topStack(Stack* stack)
{
	if (isEmptyStack(stack)) {
		return NULL;
	}
	return stack->top->data;
}

/*
	Description: Checks if the stack is empty.

	Parameters:
		- stack: Pointer to the stack to be checked.

	Returns:
		- true if the stack is empty or NULL, false otherwise.
*/
bool isEmptyStack(Stack* stack)
{
	return  (stack == NULL || stack->size == 0);
}


/*
	Description: Returns the current size of the stack.

	Parameters:
		- stack: Pointer to the stack for which the size will be retrieved.

	Returns:
		- The current size of the stack, or 0 if the stack is NULL.
*/
int sizeOfStack(Stack* stack)
{
	return (stack != NULL ? stack->size : 0);
}


