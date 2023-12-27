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

### 實作
以下為stack使用範例
```c
Stack* myStack = createStack();
int element = 42;
pushStack(myStack, &element);
int* poppedElement = (int*)popStack(myStack);
int stackSize = sizeOfStack(myStack);
freeStack(&myStack);
```


## Queue
在這裡簡要描述你實作的Queue資料結構。

### 實作
以下為queue使用範例
```
```


## Pair
在這裡簡要描述你實作的Pair資料結構。

### 實作
以下為pair使用範例
```
```


