#pragma once
#ifndef STACK_H
#define STACK_H
#include<stdbool.h>

// Forward declaration
typedef struct stack Stack;
typedef struct stack_node StackNode;

// Definition of stack structure 
struct stack {
	StackNode* top;
	int size;
};

// Queue ADT Type Definitions
struct stack_node {
    void* data;            // Pointer to the data stored in the node
    StackNode* link;      // Pointer to the next node in the stack
};

// Prototype Declarations
Stack* createStack(void);
void freeStack(Stack** stackPtr);

bool pushStack(Stack* stack, void* dataInPtr);
void* popStack(Stack* stack);
void* topStack(Stack* stack);

bool isEmptyStack(const Stack * stack);
int	sizeOfStack(const Stack * stack);

#endif // !STACK_H
