#pragma once
#include <stdbool.h>
#ifndef LIST_H
#define LIST_H

/*forward declaration*/
typedef struct list_node LIST_NODE;
typedef struct list LIST;

/*List ADT Type Defintions*/
struct list_node
{
	void* dataPtr;
	struct list_node* link;
};

struct list
{
	LIST_NODE* pos;
	LIST_NODE* head;
	LIST_NODE* rear;
	int size;
	int (*compare)(void* argu1, void* argu2);
};

//Prototype Declarations 
LIST* createList(int (*compare)(void* argu1, void* argu2));
void destroyList(LIST ** ptrList);
int addNode(LIST* pList, void* dataInPtr);
bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr);
bool searchList(LIST* pList, void* pArgu, void** pDataOut);

bool retrieveNode(LIST* pList, void* pArgu, void** dataOutPtr);
bool traverse(LIST* pList, int fromWhere, void** dataOutPtr);
int sizeOfList(LIST* pList);
bool isEmptyList(LIST* pList);
bool isFullList(LIST* pList);

static bool _insert(LIST* pList, LIST_NODE* pPre, void* dataInPtr);
static void _delete(LIST* pList, LIST_NODE* pPre, LIST_NODE* pLoc, void** dataOutPtr);
static bool _search(LIST* pList, LIST_NODE** pPre, LIST_NODE** pLoc, void* pArgu);
//End of List ADT Definitions
#endif // !LIST_H
