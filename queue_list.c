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

void QueueInit(Queue *pq) //큐 초기화
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue *pq)
{
	if (pq->front == NULL) return TRUE; //F가 NULL이면 빈 것. 
	else return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) //첫 번째 노드 추가
	{
		pq->front = newNode;
		pq->rear = newNode;
	} 
	else //두 번째 노드 추가
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

	delNode = pq->front;			//삭제할 노드의 주소 값 저장
	retData = delNode->data;		//삭제할 노드가 지닌 값 저장
	pq->front = pq->front->next;	//삭제할 노드의 다음 노드를 front가 가리킴

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