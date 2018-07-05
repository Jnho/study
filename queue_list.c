#include <stdio.h>
#include<stdlib.h>
#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
}Node;

typedef struct _lQueue {
	Node *front;
	Node *rear;
}LQueue;

typedef LQueue Queue;
#endif

void QueueInit(Queue *pq) //ť �ʱ�ȭ
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue *pq)
{
	if (pq->front == NULL) return TRUE; //F�� NULL�̸� �� ��. 
	else return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) //ù ��° ��� �߰�
	{
		pq->front = newNode;
		pq->rear = newNode;
	} 
	else //�� ��° ��� �߰�
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue *pq)
{
	Node *delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;			//������ ����� �ּ� �� ����
	retData = delNode->data;		//������ ��尡 ���� �� ����
	pq->front = pq->front->next;	//������ ����� ���� ��带 front�� ����Ŵ

	free(delNode);
	return retData;
}

int main(void) 
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1); Enqueue(&q, 2);
	Enqueue(&q, 3); Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QIsEmpty(&q)) printf("%d ", Dequeue(&q));

	return 0;
}