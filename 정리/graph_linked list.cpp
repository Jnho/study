#pragma warning(disable:4996)

#include <stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}Node;

typedef struct _linkedList
{
	Node*head;
	Node*cur;
	Node*before;
	int numOfData;
	int(*comp)(int d1, int d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List *plist) 
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, int data)
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

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}
void LInsert(List*plist, int data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List *plist, int *pdata)
{
	if (plist->head->next == NULL) return 0;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return 1;
}

int LNext(List*plist, int *pdata)
{
	if (plist->cur->next == NULL) return 0;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return 1;
}


int LRemove(List *plist)
{
	Node *rpos = plist->cur;
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

void SetSortRule(List* plist, int(*comp)(int d1, int d2))
{
	plist->comp = comp;
}

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;
	else return 1;
}

//인접 리스트 기반의 그래프 구현

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV; //정점의 수
	int numE; //간선의 수
	List *adjList;
}ALGraph;

void GraphInit(ALGraph *pg, int nv) //그래프 초기화
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);  //간선정보를 저장할 리스트 생성
	pg->numV = nv;		//정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;		//초기의 간선 수는 0개

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);		//알파벳 순으로 출력하기 위해 쓴 것. 그래프와는 무관
	}
}
void GrapgDestroy(ALGraph *pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList); //동적 할당된 연결리스트 소멸
}

//간선의 추가
void AddEdge(ALGraph *pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph *pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ",vx+65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 5);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);
	
	ShowGraphEdgeInfo(&graph);
	GrapgDestroy(&graph);
	return 0;
}