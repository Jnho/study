#include <stdio.h>
#include<stdlib.h>

#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *next;
}Node;

typedef struct _CLL
{
	Node *tail;
	Node *cur;
	Node *before;
	int numOfData;
}CList;

typedef CList List;

#endif

void ListInit(List *plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List *plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) //첫 번째 노드라면
	{
		plist->tail = newNode;		//tail이 새 노드를 가리키게 한다
		newNode->next = newNode;	//새 노드 자신을 가리키게 한다
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	(plist->numOfData)++;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;			//LInsertFront 함수와의 유일한 차이점
	}
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->tail == NULL) return FALSE;

	plist->before = plist->tail;		//before가 꼬리를 가리키게 한다
	plist->cur = plist->tail->next;		//cur이 머리를 가리키게 한다

	*pdata = plist->cur->data;			//cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->tail == NULL) return FALSE;

	plist->before = plist->cur;			//before가 다음 노드를 가리키게 한다.
	plist->cur = plist->cur->next;		//cur이 다음 노드를 가리키게 한다

	*pdata = plist->cur->data;			//cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)		//예외상황, 삭제 대상을 tail이 가르킨다면
	{
		if (plist->tail == plist->tail->next) plist->tail = NULL;  //예외상황2, 그리고 마지막 남은 노드라면
		else plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;		//삭제할 노드의 이전 노드가, 삭제할 노드의 다음 노드를 가리키게 한다
	plist->cur = plist->before;					//포인터 변수 cur을 한 칸 뒤로 이동시킨다

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

int main(void)
{
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	//리스트에 저장된 데이터를 연속 3회 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	//2의 배수를 찾아서 모두 삭제
	nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	//전체 데이터 1회 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	return 0;
}
