#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100

typedef struct _cQueue
{
	int front;
	int rear;
	int queArr[QUE_LEN];
}CQueue;

#endif

void QueueInit(CQueue*pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(CQueue*pq)
{
	if (pq->front == pq->rear) return TRUE;
	else return FALSE;
}

int NextPosIdx(int pos) //원형 큐 회전을 위한 인덱스 
{
	if (pos == QUE_LEN - 1) return 0;
	else return pos + 1;
}

void Enqueue(CQueue*pq, int data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("error");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

int Dequeue(CQueue*pq)
{
	if (QIsEmpty(pq))
	{
		printf("error");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

int main(void)
{
	CQueue q;
	QueueInit(&q);

	Enqueue(&q, 1); Enqueue(&q, 2);
	Enqueue(&q, 3); Enqueue(&q, 4);
	Enqueue(&q, 5); Enqueue(&q, 6);

	while (!QIsEmpty(&q)) {		
		printf("%d ", Dequeue(&q));
	}

	return 0;
}