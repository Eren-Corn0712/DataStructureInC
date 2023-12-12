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

void destroyList(LIST ** ptrList)
{
	if (ptrList && *ptrList) {
		LIST_NODE* deletePtr;
		while (!isEmptyList(*ptrList)) {
			deletePtr = (*ptrList)->head;
			(*ptrList)->head = (*ptrList)->head->link;
			((*ptrList)->size)--;
			free(deletePtr);
		}
		free(*ptrList);
		*ptrList = NULL;
	}
}

int addNode(LIST* pList, void* dataInPtr)
{
	bool found;
	bool success;

	LIST_NODE* pPre;
	LIST_NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, dataInPtr);
	if (found) {
		return (1);
	}
	success = _insert(pList, pPre, dataInPtr);
	if (!success) {
		return (-1);
	}
	return (0);
}

bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr)
{
	bool found;

	LIST_NODE* pPre;
	LIST_NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, keyPtr);
	if (found) {
		_delete(pList, pPre, pLoc, dataOutPtr);
	}
	return found;
}

bool searchList(LIST* pList, void* pArgu, void** pDataOut)
{
	bool found;
	LIST_NODE* pPre;
	LIST_NODE* pLoc;
	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found) {
		*pDataOut = pLoc->dataPtr;
	}
	else {
		*pDataOut = NULL;
	}
	return found;
}

bool retrieveNode(LIST* pList, void* pArgu, void** dataOutPtr)
{
	bool found;
	LIST_NODE* pPre;
	LIST_NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found)
	{
		*dataOutPtr = pLoc->dataPtr;
		return true;
	} // if 
	*dataOutPtr = NULL;
	return false;
}

bool traverse(LIST* pList, int fromWhere, void** dataOutPtr)
{
	if (isEmptyList(pList)) {
		return false;
	}
	if (fromWhere == 0) {
		pList->pos = pList->head;
		*dataOutPtr = pList->pos->dataPtr;
		return true;
	}
	else {
		if (pList->pos->link == NULL) {
			return false;
		}
		else {
			pList->pos = pList->pos->link;
			*dataOutPtr = pList->pos->dataPtr;
			return true;
		}
	}
}

int sizeOfList(LIST* pList)
{
	return (pList ? pList->size : 0);
}

bool isEmptyList(LIST* pList)
{
	return (pList == NULL || pList->size == 0);
}

bool isFullList(LIST* pList)
{
	LIST_NODE* temp = (LIST_NODE*)malloc(sizeof(*(pList->head)));
	if (temp) {
		free(temp);
		return false;
	}
	return true;
}

bool _insert(LIST* pList, LIST_NODE* pPre, void* dataInPtr)
{
	LIST_NODE* pNew = (LIST_NODE*)malloc(sizeof(LIST_NODE));

	if (pList == NULL || !pNew) {
		return false;
	}

	pNew->dataPtr = dataInPtr;
	pNew->link = NULL;

	if (pPre == NULL) {
		pNew->link = pList->head;
		pList->head = pNew;
		if (pList->size == 0) {
			pList->rear = pNew;
		}
	}
	else {
		pNew->link = pPre->link;
		pPre->link = pNew;
		if (pNew->link == NULL) {
			pList->rear = pNew;
		}
	}
	(pList->size)++;
	return true;
}

void _delete(LIST* pList, LIST_NODE* pPre, LIST_NODE* pLoc, void** dataOutPtr)
{
	*dataOutPtr = pLoc;
	if (pPre == NULL) {
		pList->head = pLoc->link;
	}
	else {
		pPre->link = pLoc->link;
	}

	if (pLoc->link == NULL) {
		pList->rear = pPre;
	}
	(pList->size)--;
	free(pLoc);
	return;
}

bool _search(LIST* pList, LIST_NODE** pPre, LIST_NODE** pLoc, void* pArgu)
{
#define COMPARE \
( ((* pList->compare) (pArgu, (*pLoc)->dataPtr)) )
#define COMPARE_LAST \
((* pList->compare) (pArgu, pList->rear->dataPtr))
	
	int result;
	*pPre = NULL;
	*pLoc = pList->head;
	
	if (isEmptyList(pList)) {
		return false;
	}
	if (COMPARE_LAST > 0) {
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	}
	while ((result = COMPARE) > 0)
	{
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	}
	if (result == 0) {
		return true;
	}
	return false;
}
