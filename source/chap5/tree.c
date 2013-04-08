
#include "stdio.h"
#include "stdlib.h"

typedef int elemType;
struct biTree_node
{
	elemType data;
	struct biTree_node *lchild, *rchild;
};
struct biTree_container
{
	struct biTree_node *root;
};

void InitBiTree(struct biTree_container *pTree);
void CreateBiTree(struct biTree_container *pTree);
void InsertLeftNode(struct biTree_node *q, elemType x);
int TreeNodeNumber(struct biTree_container *pTree);
int LeafNodeNumber(struct biTree_container *pTree);
int TreeDepth(struct biTree_container *pTree);

// ����������
void MidTraverse(struct biTree_container *pTree);
void PriorTraverse(struct biTree_container *pTree);
void PostTraverse(struct biTree_container *pTree);

void main()
{
	// һ�ö���������
	struct biTree_container tree;

	// ��ʼ��������
	InitBiTree(&tree);

	// �����ö�����:�������ι�ϵ�����ݷ���������
	CreateBiTree(&tree);

	// ����һ����,��Ϊ����������
	InsertLeftNode(tree.root, 5);

	// �������Ľ�����
	printf("The number of tree nodes is: %d\n", TreeNodeNumber(&tree));

	// ��������Ҷ�ӽ����
	printf("The number of leaf nodes is: %d\n", LeafNodeNumber(&tree));

	// �����������
	printf("The depth of the tree is: %d\n", TreeDepth(&tree));

	return;
}

void InitBiTree(struct biTree_container *pTree)
{
	// ��ʼ��Ϊһ�ÿյĶ�����:�����Ϊ��
	pTree->root = 0;
}

void CreateBiTree(struct biTree_container *pTree)
{
	// ����һ�ö�����
	elemType b;
	struct biTree_node *root;
	struct biTree_container ltree, rtree;

	// �����û���������Ϊ��(�������Ϊ��,��Ϊ����)
	scanf("%d", &b);
	if(b == 0)
	{
		pTree->root = 0;
		return;
	}

	// �����������ĸ�
	root = (struct biTree_node *)malloc(sizeof(struct biTree_node));
	root->data = b;
	pTree->root = root;

	// ������������
	CreateBiTree(&ltree);
	CreateBiTree(&rtree);

	// ������������������ϵ
	root->lchild = ltree.root;
	root->rchild = rtree.root;
	
	return;
}

void InsertLeftNode(struct biTree_node *q, elemType x)
{
	// ������x��Ϊq�����ӽ��
	struct biTree_node *p;

	// Ϊx�½�һ�����
	p = (struct biTree_node *)malloc(sizeof(struct biTree_node));
	p->data = x;

	// ��q����������Ϊp��������,p��������Ϊ��
	p->lchild = q->lchild;
	p->rchild = 0;

	// ���½����p��Ϊq������
	q->lchild = p;

	return;
}

int TreeNodeNumber(struct biTree_container *pTree)
{
	// ��������Ҷ�ӽ�����
	struct biTree_container ltree, rtree;

	// Ϊһ�ÿ���
	if(pTree->root == 0)
	{
		return 0;
	}
	else
	{
		ltree.root = pTree->root->lchild;
		rtree.root = pTree->root->rchild;

		return 1 + TreeNodeNumber(&ltree) + TreeNodeNumber(&rtree); 
	}
}

int LeafNodeNumber(struct biTree_container *pTree)
{
	// ��������Ҷ�ӽ�����
	struct biTree_container ltree, rtree;

	// Ϊһ�ÿ���
	if(pTree->root == 0)
	{
		return 0;
	}

	// ��ΪҶ�ӽ��
	if(pTree->root->lchild == 0 && pTree->root->rchild == 0)
	{
		return 1;
	}
	else
	{
		ltree.root = pTree->root->lchild;
		rtree.root = pTree->root->rchild;

		return LeafNodeNumber(&ltree) + LeafNodeNumber(&rtree); 
	}
}

int TreeDepth(struct biTree_container *pTree)
{
	// ��������������
	struct biTree_container ltree, rtree;
	int ldepth, rdepth;

	// Ϊһ�ÿ���
	if(pTree->root == 0)
	{
		return 0;
	}
	else{
		ltree.root = pTree->root->lchild;
		rtree.root = pTree->root->rchild;

		ldepth = TreeDepth(&ltree);
		rdepth = TreeDepth(&rtree);

		return (ldepth >= rdepth ? ldepth+1 : rdepth+1);
	}
}

void MidTraverse(struct biTree_container *pTree)
{
	// �������������
	struct biTree_container ltree, rtree;

	if(pTree->root != 0){ // һ�÷ǿյĶ�����
		// �������������
		ltree.root = pTree->root->lchild;
		MidTraverse( &ltree );

		// ���ʸ��ڵ�
		printf("%d ", pTree->root->data);

		// �������������
		rtree.root = pTree->root->rchild;
		MidTraverse( &rtree );
	}

	return;
}

void PriorTraverse(struct biTree_container *pTree)
{
	// �������������
	struct biTree_container ltree, rtree;

	if(pTree->root != 0){ // һ�÷ǿյĶ�����
		// ���ʸ��ڵ�
		printf("%d ", pTree->root->data);

		// �������������
		ltree.root = pTree->root->lchild;
		PriorTraverse( &ltree );

		// �������������
		rtree.root = pTree->root->rchild;
		PriorTraverse( &rtree );
	}

	return;
}

void PostTraverse(struct biTree_container *pTree)
{
	// �������������
	struct biTree_container ltree, rtree;

	if(pTree->root != 0){ // һ�÷ǿյĶ�����
		// �������������
		ltree.root = pTree->root->lchild;
		PriorTraverse( &ltree );

		// �������������
		rtree.root = pTree->root->rchild;
		PriorTraverse( &rtree );

		// ���ʸ��ڵ�
		printf("%d ", pTree->root->data);
	}

	return;
}
