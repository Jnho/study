#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}Node;

void Init(Node *st)
{
	st = NULL;
}

Node* Push(Node*st, int data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = st;
	st = newNode;
	return st;
}
Node* Pop(Node*st,int *rdata)
{
	Node*rnode;

	rnode = st;
	*rdata = rnode->data;
	st = st->next;
	
	free(rnode);
	return st;
}

int main(void)
{
	int element;
	Node*top = NULL;
	Init(top);
	top=Push(top, 1); 
	top=Push(top, 2);
	top=Push(top, 3); 

	for (int i = 0; i < 3; i++) {
		top = Pop(top, &element);
		printf("%d\n", element);
	}
	return 0;
}