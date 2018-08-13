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

	if (IsEmpty(q1))	//q1�� ����ִٸ� q2�� �����Ͱ� �׿��ִ°�. �׷��� q1�� q2�� �ٲ㼭 POPȣ��
	{					//�ٲ㼭 ȣ���ϸ� ����ִ� ť�� �����͸� �ű�� ������ ������ ��ȯ
		return Pop(q2, q1); 
	}
	else 
	{
		while (q1->front != NULL) //ť�� ���� POP��� �ҽ� q1�� ���� �ƴ϶�� q2�� �����͸� �ű�
		{						  //�׸��� ������ �����͸� �ٸ� ť�� �ȿű�� ��ȯ
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