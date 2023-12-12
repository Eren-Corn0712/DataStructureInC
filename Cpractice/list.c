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

void destroyList(List ** ptrList)
{
	if (ptrList && *ptrList) {
		ListNode* deletePtr;
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

int addNode(List* pList, void* dataInPtr)
{
	bool found;
	bool success;

	ListNode* pPre;
	ListNode* pLoc;

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

bool removeNode(List* pList, void* keyPtr, void** dataOutPtr)
{
	bool found;

	ListNode* pPre;
	ListNode* pLoc;

	found = _search(pList, &pPre, &pLoc, keyPtr);
	if (found) {
		_delete(pList, pPre, pLoc, dataOutPtr);
	}
	return found;
}

bool searchList(List* pList, void* pArgu, void** pDataOut)
{
	bool found;
	ListNode* pPre;
	ListNode* pLoc;
	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found) {
		*pDataOut = pLoc->dataPtr;
	}
	else {
		*pDataOut = NULL;
	}
	return found;
}

bool retrieveNode(List* pList, void* pArgu, void** dataOutPtr)
{
	bool found;
	ListNode* pPre;
	ListNode* pLoc;

	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found)
	{
		*dataOutPtr = pLoc->dataPtr;
		return true;
	} // if 
	*dataOutPtr = NULL;
	return false;
}

bool traverse(List* pList, int fromWhere, void** dataOutPtr)
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

int sizeOfList(List* pList)
{
	return (pList ? pList->size : 0);
}

bool isEmptyList(List* pList)
{
	return (pList == NULL || pList->size == 0);
}

bool isFullList(List* pList)
{
	ListNode* temp = (ListNode*)malloc(sizeof(*(pList->head)));
	if (temp) {
		free(temp);
		return false;
	}
	return true;
}

bool _insert(List* pList, ListNode* pPre, void* dataInPtr)
{
	ListNode* pNew = (ListNode*)malloc(sizeof(ListNode));

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

void _delete(List* pList, ListNode* pPre, ListNode* pLoc, void** dataOutPtr)
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

bool _search(List* pList, ListNode** pPre, ListNode** pLoc, void* pArgu)
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
