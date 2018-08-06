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
	Node *head;					//���� ��带 ����Ű�� ���
	Node *cur;					//���� �� ������ ���� ���
	Node *before;				//������ ���� ���
	int numOfData;		
	int(*comp)(int d1, int d2);	//������ ������ ����ϱ� ���� ���
}List;

void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node));	//���� ��� ����
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

	//�� ��尡 �� ��ġ�� ã�� ���� �ݺ���
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List*plist, int data)
{
	if (plist->comp == NULL)	//���� ������ ���õ��� �ʾҴٸ�
		FInsert(plist, data);	//�Ӹ��� �߰�
	else
		SInsert(plist, data);	//���ı��ؿ� �ٰ��Ͽ� ��� �߰�
}

//������ ��ȸ �Լ�
int LFirst(List*plist, int *data)
{
	if (plist->head->next == NULL)
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*data = plist->cur->data;
	return TRUE;
}
//������ ��ȸ �Լ�
int LNext(List*plist, int *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

//��� ���� �Լ�
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
	if (d1 < d2) //d1�� ���� ������ �ռ���
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