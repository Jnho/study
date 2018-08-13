#pragma warning(disable:4996)

#include <stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}Node;

typedef struct _Q
{
	Node *front;
	Node*rear;
}Queue;


void init(Queue *q1, Queue *q2)
{
	q1->front = q2->front = NULL;
	q1->rear = q2->rear = NULL;
}

int IsEmpty(Queue *q)
{
	if (q->front == NULL) return 1;
	else return 0;
}

void EnQueue(Queue *q, int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;

	if (q->front == NULL)
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else 
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

int DeQueue(Queue*q)
{
	Node *delNode;
	int rData;

	delNode = q->front;
	rData = delNode->data;

	q->front = q->front->next;

	free(delNode);
	return rData;
}

void Push(Queue *q, int data)
{
	EnQueue(q, data); 
}

int Pop(Queue *q1, Queue *q2)
{
	int rData;

	if (IsEmpty(q1))	//q1이 비어있다면 q2에 데이터가 쌓여있는것. 그러면 q1과 q2를 바꿔서 POP호출
	{					//바꿔서 호출하면 비어있는 큐로 데이터를 옮기고 마지막 데이터 반환
		return Pop(q2, q1); 
	}
	else 
	{
		while (q1->front != NULL) //큐로 스택 POP기능 할시 q1이 널이 아니라면 q2로 데이터를 옮김
		{						  //그리고 마지막 데이터를 다른 큐로 안옮기고 반환
			rData = DeQueue(q1);

			if (IsEmpty(q1)) break;

			EnQueue(q2, rData);
		}
		return rData;
	}
}

int main(void)
{
	Queue q1, q2;

	init(&q1, &q2);

	Push(&q1, 1); Push(&q1, 2);
	Push(&q1, 3); Push(&q1, 4);
	Push(&q1, 5); Push(&q1, 6);

	for (int i = 0; i < 6; i++) {
		printf("%d ", Pop(&q1, &q2));
	}
	printf("\n");
	Push(&q1, 1); Push(&q1, 2);
	printf("%d ", Pop(&q1, &q2));
	printf("%d ", Pop(&q1, &q2));

	return 0;
}