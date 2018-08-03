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

//��� ����
BTreeNode *MakeBTreeNode(void) {
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

//��� �� ��ȯ
BTData GetData(BTreeNode *bt)
{
	return bt->data;
}
//��� �� ����
void SetData(BTreeNode *bt, BTData data)
{
	bt->data = data;
}
//����� ���ʿ� �ִ� ��� ��ȯ
BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}
//��� �����ʿ� �ִ� ��� ��ȯ
BTreeNode *GetRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

//main��� ���� ��� �ڸ��� sub��� ����
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->left != NULL) free(main->left);

	main->left = sub;
}
//�����ʿ� ����
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->right != NULL) free(main->right);

	main->right = sub;
}

//��� ����, ���������� �ش� ��� �Ʒ� ��� ��� ����
//���� ��带 ������ NULL�� ����� ���� �ʾƼ� ��ȸ�� ������ �ִ�
void DeleteTree(BTreeNode *bt)
{
	if (bt == NULL) return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("%d ����\n", bt->data);
	free(bt);
}
//���� ��ȸ ���
void PreorderTraverse(BTreeNode *bt)
{
	if (bt == NULL) return;

	printf("%d \n", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}
//���� ��ȸ ���
void InorderTraverse(BTreeNode *bt)
{
	if (bt == NULL) return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}
//���� ��ȸ ���
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