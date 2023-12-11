#include "list.h"
#include<stdlib.h>
LIST* createList(int(*compare)(void* argu1, void* argu2))
{
    LIST* list = (LIST*)malloc(sizeof(LIST));
    if (list) {
        list->pos = NULL;
        list->head = NULL;
        list->rear = NULL;
        list->size = 0;
        list->compare = compare;
    }
    return list;
}

LIST* destroyList(LIST* list)
{
    return nullptr;
}

int addNode(LIST* pList, void* dataInPtr)
{
    return 0;
}

bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr)
{
    return false;
}

bool searchList(LIST* pList, void* pArgu, void** pDataOut)
{
    return false;
}

bool retrieveNode(LIST* pList, void* pArgu, void** dataOutPtr)
{
    return false;
}

bool traverse(LIST* pList, int fromWhere, void** dataOutPtr)
{
    return false;
}

int sizeOfList(LIST* pList)
{
    return 0;
}

bool isEmptyList(LIST* pList)
{
    return false;
}

bool isFullList(LIST* pList)
{
    return false;
}

int _insert(LIST* pList, LIST_NODE* pPre, void* dataInPtr)
{
    return 0;
}

void _delete(LIST* pList, LIST_NODE* pPre, LIST_NODE* pLoc, void** dataOutPtr)
{
}

bool _search(LIST* pList, LIST_NODE** pPre, LIST_NODE** pLoc, void* pArgu)
{
    return false;
}
