#pragma warning(disable:4996)
#include <stdio.h>
#include<stdlib.h>
#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
}Node;

typedef struct _listStack {
	Node *head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack) //스택 초기화
{
	pstack->head = NULL;
}

int SIsEmpty(Stack *pstack) //스택이 비어 있는지 확인
{
	if (pstack->head == NULL) return TRUE;
	else return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack *pstack)
{
	Data rdata;
	Node *rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->head->data;
}

int main(void) {
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SIsEmpty(&stack)) printf("%d ", SPop(&stack));

	return 0;
	{

	}
}
#endif