#include <stdio.h>
#include<stdlib.h>

#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node
{
	Data data;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct _dbDLinkedList
{
	Node *head;
	Node *tail;
	Node *cur;
	int numOfData;
}DBDLinkedList;

typedef DBDLinkedList List;

#endif // !__DBD_LINKED_LIST_H__

void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->head->next == plist->tail) return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->cur->next == plist->tail) return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data remv = rpos->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;		//cur의 위치를 재조정
	
	free(rpos);
	(plist->numOfData)--;
	return remv;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);
	//저장된 데이터 조회
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
		printf("\n");
	}
	//2의 배수 삭제
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
				LRemove(&list);
		}
	}
	//저장된 데이터 조회
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
		printf("\n\n");
	}
	return 0;
}