#include <stdio.h>
#include<stdlib.h>
#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct _dlDeque {
	Node *head;
	Node *tail;
}DLDeque;

typedef DLDeque Deque;
#endif

void DequeInit(Deque *pdeq) 
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
	if (pdeq->head == NULL) return TRUE;
	else return FALSE;
}

void DQAddFirst(Deque *pdeq, Data data)  //덱의 머리에 데이터 추가
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq)) pdeq->tail = newNode;
	else pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data) //덱의 꼬리에 데이터 추가
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq)) pdeq->head = newNode;
	else pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq) //덱의 머리에서 데이터 삭제
{
	Node *rnode = pdeq->head;
	Data rdata = pdeq->head->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	pdeq->head = pdeq->head->next;
	free(rnode);

	if (pdeq->head == NULL) pdeq->tail = NULL;
	else pdeq->head->prev = NULL;

	return rdata;
}

Data DQRemoveLast(Deque *pdeq) //덱의 꼬리에서 데이터 삭제
{
	Node *rnode = pdeq->tail;
	Data rdata = pdeq->tail->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	pdeq->tail = pdeq->tail->prev;
	free(rnode);

	if (pdeq->tail == NULL) pdeq->head = NULL;
	else pdeq->tail->next = NULL;

	return rdata;
}

Data DQGetFirst(Deque *pdeq) //덱의 머리에서 데이터 참조
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	return pdeq->head->data;
}

Data DQGetLast(Deque *pdeq)  //덱의 꼬리에서 데이터 참조
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	return pdeq->tail->data;
}

int main(void)
{
	Deque deq;
	DequeInit(&deq);

	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	while (!DQIsEmpty(&deq)) printf("%d ", DQRemoveFirst(&deq));

	printf("\n");

	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	while (!DQIsEmpty(&deq)) printf("%d ", DQRemoveLast(&deq));

	return 0;
}