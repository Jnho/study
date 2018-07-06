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

	if (plist->tail == NULL) //ù ��° �����
	{
		plist->tail = newNode;		//tail�� �� ��带 ����Ű�� �Ѵ�
		newNode->next = newNode;	//�� ��� �ڽ��� ����Ű�� �Ѵ�
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
		plist->tail = newNode;			//LInsertFront �Լ����� ������ ������
	}
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->tail == NULL) return FALSE;

	plist->before = plist->tail;		//before�� ������ ����Ű�� �Ѵ�
	plist->cur = plist->tail->next;		//cur�� �Ӹ��� ����Ű�� �Ѵ�

	*pdata = plist->cur->data;			//cur�� ����Ű�� ����� ������ ��ȯ
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->tail == NULL) return FALSE;

	plist->before = plist->cur;			//before�� ���� ��带 ����Ű�� �Ѵ�.
	plist->cur = plist->cur->next;		//cur�� ���� ��带 ����Ű�� �Ѵ�

	*pdata = plist->cur->data;			//cur�� ����Ű�� ����� ������ ��ȯ
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)		//���ܻ�Ȳ, ���� ����� tail�� ����Ų�ٸ�
	{
		if (plist->tail == plist->tail->next) plist->tail = NULL;  //���ܻ�Ȳ2, �׸��� ������ ���� �����
		else plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;		//������ ����� ���� ��尡, ������ ����� ���� ��带 ����Ű�� �Ѵ�
	plist->cur = plist->before;					//������ ���� cur�� �� ĭ �ڷ� �̵���Ų��

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

	//����Ʈ�� ����� �����͸� ���� 3ȸ ���
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

	//2�� ����� ã�Ƽ� ��� ����
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

	//��ü ������ 1ȸ ���
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
