# Implementing Data Structures in C

## Abstract
Implementing data structures in C and performing unit tests using the CuTest framework.

Implemented Data Structures:
* Stack
* Queue
* Pair

Testing Framework:
* CuTest

## STACK
This is a simple implementation of a stack data structure in C. The stack allows you to push and pop elements, check if it's empty, get its size, and more.
The stack is implemented using a linked list, where each node holds a pointer to the data and a link to the next node. The `Stack` structure maintains a pointer to the top of the stack and keeps track of the size.

### Usage
```c
Stack* myStack = createStack();
int element = 42;
pushStack(myStack, &element);
int* poppedElement = (int*)popStack(myStack);
int stackSize = sizeOfStack(myStack);
freeStack(&myStack);
```


## Queue
The queue is implemented using a linked list, where each node contains a pointer to the data and a link to the next node. The Queue structure maintains pointers to the front and rear of the queue and keeps track of the size.

### Usage
#### Creating a Queue
```
Queue* myQueue = createQueue();
```


## Pair

### 實作
以下為pair使用範例
```
```


