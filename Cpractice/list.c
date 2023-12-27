#include "list.h"
#include<stdlib.h>
List* createList(int(*compare)(void* argu1, void* argu2))
{
    List* list = (List*)malloc(sizeof(List));
    if (list) {
        list->pos = NULL;
        list->head = NULL;
        list->rear = NULL;
        list->size = 0;
        list->compare = compare;
    }
    return list;
}

List* destroyList(List* list)
{
    return nullptr;
}

int addNode(List* pList, void* dataInPtr)
{
    return 0;
}

bool searchList(List* pList, void* pArgu, void** pDataOut)
{
    return false;
}

bool searchList(LIST* pList, void* pArgu, void** pDataOut)
{
    return false;
}

bool traverse(List* pList, int fromWhere, void** dataOutPtr)
{
    return false;
}

int sizeOfList(List* pList)
{
    return false;
}

bool isEmptyList(List* pList)
{
    return 0;
}

bool isFullList(List* pList)
{
    return false;
}

bool _insert(List* pList, ListNode* pPre, void* dataInPtr)
{
    return false;
}

int _insert(List* pList, ListNode* pPre, void* dataInPtr)
{
    return 0;
}

	if (pLoc->link == NULL) {
		pList->rear = pPre;
	}
	(pList->size)--;
	free(pLoc);
	return;
}

bool _search(List* pList, ListNode** pPre, ListNode** pLoc, void* pArgu)
{
}

bool _search(LIST* pList, LIST_NODE** pPre, LIST_NODE** pLoc, void* pArgu)
{
    return false;
}
