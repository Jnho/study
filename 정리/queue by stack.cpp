#pragma warning(disable:4996)

#include <stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}Node;

typedef struct _st
{
	Node *top;
}Stack;

void Init(Stack *st1,Stack *st2)
{
	st1->top = NULL;
	st2->top = NULL;
}

int IsEmpty(Stack *st)
{
	if (st->top == NULL) return 1;
	else return 0;
}

void Push(Stack *st, int data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = st->top;
	st->top = newNode;
}

int Pop(Stack*st)
{
	Node *rnode;
	int rdata;

	rnode = st->top;
	rdata = rnode->data;

	st->top = st->top->next;
	free(rnode);
	return rdata;
}

void EnQueue(Stack*st,int data)		//���� Push�������� EnQueue
{
	Push(st, data);
}

int DeQueue(Stack *st1,Stack*st2)
{
	int rdata;
	
	if (st2->top == NULL)
	{
		while (st1->top != NULL)
		{
			rdata = Pop(st1);	//st1 ������ ���θ� st2�� �ű�
			Push(st2, rdata);
		}
	}

	return Pop(st2);	//st2�� �Ű����ϱ� st2�� ������ �����͸� Pop�ϸ� ��ť ����ó�� ��
}

int main(void)
{
	Stack s1, s2;
	Init(&s1, &s2);

	EnQueue(&s1, 1); EnQueue(&s1, 2);
	EnQueue(&s1, 3); EnQueue(&s1, 4);
	EnQueue(&s1, 5); EnQueue(&s1, 6);

	for (int i = 0; i < 6; i++) printf("%d ", DeQueue(&s1, &s2));
	printf("\n");

	EnQueue(&s1, 7); EnQueue(&s1, 8);
	printf("%d ", DeQueue(&s1, &s2));
	printf("%d ", DeQueue(&s1, &s2));

	return 0;
}
