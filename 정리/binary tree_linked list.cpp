#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;


#endif // !__BINARY_TREE_H__

//노드 생성
BTreeNode *MakeBTreeNode(void) {
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

//노드 값 반환
BTData GetData(BTreeNode *bt)
{
	return bt->data;
}
//노드 값 지정
void SetData(BTreeNode *bt, BTData data)
{
	bt->data = data;
}
//노드의 왼쪽에 있는 노드 반환
BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}
//노드 오른쪽에 있는 노드 반환
BTreeNode *GetRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

//main노드 왼쪽 노드 자리에 sub노드 연결
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->left != NULL) free(main->left);

	main->left = sub;
}
//오른쪽에 연결
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->right != NULL) free(main->right);

	main->right = sub;
}

//노드 삭제, 제귀적으로 해당 노드 아래 노드 모두 삭제
//이전 노드를 가리켜 NULL로 만들어 주지 않아서 순회시 문제가 있다
void DeleteTree(BTreeNode *bt)
{
	if (bt == NULL) return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("%d 삭제\n", bt->data);
	free(bt);
}
//전위 순회 방식
void PreorderTraverse(BTreeNode *bt)
{
	if (bt == NULL) return;

	printf("%d \n", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}
//중위 순회 방식
void InorderTraverse(BTreeNode *bt)
{
	if (bt == NULL) return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}
//후위 순회 방식
void PostorderTraverse(BTreeNode *bt)
{
	if (bt == NULL) return;
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d \n", bt->data);
}
int main()
{
	BTreeNode *bt1 = MakeBTreeNode();
	BTreeNode *bt2 = MakeBTreeNode();
	BTreeNode *bt3 = MakeBTreeNode();
	BTreeNode *bt4 = MakeBTreeNode();
	BTreeNode *bt5 = MakeBTreeNode();
	BTreeNode *bt6 = MakeBTreeNode();
	BTreeNode *bt7 = MakeBTreeNode();

	SetData(bt1, 1); SetData(bt2, 2);
	SetData(bt3, 3); SetData(bt4, 4);
	SetData(bt5, 5); SetData(bt6, 6);
	SetData(bt7, 7);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);

	printf("preorder \n");
	PreorderTraverse(bt1);
	printf("\n");
	printf("inorder \n");
	InorderTraverse(bt1);
	printf("\n");
	printf("postorder \n");
	PostorderTraverse(bt1);
	printf("\n");

	DeleteTree(bt3);
	
	printf("preorder \n");
	PreorderTraverse(bt1);
	printf("\n");

	return 0;


}