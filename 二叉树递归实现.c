#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lChild;
	struct BINARYNODE* rChild;
}BinaryNode;
//ÏÈÐò
void Recursion(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->ch);
	Recursion(root->lChild);
	Recursion(root->rChild);
}
//ÖÐÐò
void Recursion1(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Recursion1(root->lChild);
	printf("%c ", root->ch);
	
	Recursion1(root->rChild);
}
//ºóÐò
void Recursion2(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	Recursion2(root->lChild);
	Recursion2(root->rChild);
	printf("%c ", root->ch);

}
void CreateBinaryTree()
{
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	node1.lChild = &node2;
	node1.rChild = &node6;
	node2.rChild = &node3;
	node3.lChild = &node4;
	node3.rChild = &node5;
	node6.rChild = &node7;
	node7.lChild = &node8;

	Recursion(&node1);
	printf("\n");
	Recursion1(&node1);
	printf("\n");
	Recursion2(&node1);
}
int main()
{
	CreateBinaryTree();
	return 0;
}