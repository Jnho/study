#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
	int data;
	struct _node *next;
}Node;

typedef struct _linkedList
{
	Node *head;					//더미 노드를 가리키는 멤버
	Node *cur;					//참조 및 삭제를 돕는 멤버
	Node *before;				//삭제를 돕는 멤버
	int numOfData;		
	int(*comp)(int d1, int d2);	//정렬의 기준을 등록하기 위한 멤버
}List;

void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node));	//더미 노드 생성
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List *plist, int data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List*plist, int data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	Node*pred = plist->head;
	newNode->data = data;

	//새 노드가 들어갈 위치를 찾기 위한 반복문
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List*plist, int data)
{
	if (plist->comp == NULL)	//정렬 기준이 마련되지 않았다면
		FInsert(plist, data);	//머리에 추가
	else
		SInsert(plist, data);	//정렬기준에 근거하여 노드 추가
}

//데이터 조회 함수
int LFirst(List*plist, int *data)
{
	if (plist->head->next == NULL)
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*data = plist->cur->data;
	return TRUE;
}
//데이터 조회 함수
int LNext(List*plist, int *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

//노드 삭제 함수
int LRemove(List*plist)
{
	Node*rpos = plist->cur;
	int rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

void SetSortRule(List *plist, int(*comp)(int d1, int d2))
{
	plist->comp = comp;
}

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2) //d1이 정렬 순서상 앞선다
		return 0;
	else
		return 1;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	LInsert(&list, 11); LInsert(&list, 22);
	LInsert(&list, 33); LInsert(&list, 44);
	LInsert(&list, 55); LInsert(&list, 66);
	
	printf("%d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data))
	{
		if (data == 22) LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}
	printf("%d\n", LCount(&list));
	return 0;
}