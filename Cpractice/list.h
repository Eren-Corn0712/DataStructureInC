#pragma once
#include <stdbool.h>
#ifndef LIST_H
#define LIST_H

/*forward declaration*/
typedef struct list_node ListNode;
typedef struct list List;

/*List ADT Type Defintions*/
struct list_node
{
	void* dataPtr;
	struct list_node* link;
};

struct list
{
	ListNode* pos;
	ListNode* head;
	ListNode* rear;
	int size;
	int (*compare)(void* argu1, void* argu2);
};

//Prototype Declarations 
List* createList(int (*compare)(void* argu1, void* argu2));
List* destroyList(LIST* list);
int addNode(List* pList, void* dataInPtr);
bool removeNode(List* pList, void* keyPtr, void** dataOutPtr);
bool searchList(List* pList, void* pArgu, void** pDataOut);

bool retrieveNode(List* pList, void* pArgu, void** dataOutPtr);
bool traverse(List* pList, int fromWhere, void** dataOutPtr);
int sizeOfList(List* pList);
bool isEmptyList(List* pList);
bool isFullList(List* pList);

static int _insert(List* pList, ListNode* pPre, void* dataInPtr);
static void _delete(List* pList, ListNode* pPre, ListNode* pLoc, void** dataOutPtr);
static bool _search(List* pList, ListNode** pPre, ListNode** pLoc, void* pArgu);
//End of List ADT Definitions
#endif // !LIST_H
