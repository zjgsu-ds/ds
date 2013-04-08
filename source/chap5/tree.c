
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

// 遍历二叉树
void MidTraverse(struct biTree_container *pTree);
void PriorTraverse(struct biTree_container *pTree);
void PostTraverse(struct biTree_container *pTree);

void main()
{
	// 一棵二叉树容器
	struct biTree_container tree;

	// 初始化该容器
	InitBiTree(&tree);

	// 构建该二叉树:依据树形关系把数据放入容器中
	CreateBiTree(&tree);

	// 插入一个数,作为根结点的左孩子
	InsertLeftNode(tree.root, 5);

	// 计算树的结点个数
	printf("The number of tree nodes is: %d\n", TreeNodeNumber(&tree));

	// 计算树的叶子结点数
	printf("The number of leaf nodes is: %d\n", LeafNodeNumber(&tree));

	// 计算树的深度
	printf("The depth of the tree is: %d\n", TreeDepth(&tree));

	return;
}

void InitBiTree(struct biTree_container *pTree)
{
	// 初始化为一棵空的二叉树:根结点为空
	pTree->root = 0;
}

void CreateBiTree(struct biTree_container *pTree)
{
	// 创建一棵二叉树
	elemType b;
	struct biTree_node *root;
	struct biTree_container ltree, rtree;

	// 接收用户的输入作为根(如果输入为零,则为空树)
	scanf("%d", &b);
	if(b == 0)
	{
		pTree->root = 0;
		return;
	}

	// 建立二叉树的根
	root = (struct biTree_node *)malloc(sizeof(struct biTree_node));
	root->data = b;
	pTree->root = root;

	// 创建左右子树
	CreateBiTree(&ltree);
	CreateBiTree(&rtree);

	// 建立根与左右子树联系
	root->lchild = ltree.root;
	root->rchild = rtree.root;
	
	return;
}

void InsertLeftNode(struct biTree_node *q, elemType x)
{
	// 插入数x作为q的左孩子结点
	struct biTree_node *p;

	// 为x新建一个结点
	p = (struct biTree_node *)malloc(sizeof(struct biTree_node));
	p->data = x;

	// 把q的左子树作为p的左子树,p的右子树为空
	p->lchild = q->lchild;
	p->rchild = 0;

	// 把新建结点p作为q的左孩子
	q->lchild = p;

	return;
}

int TreeNodeNumber(struct biTree_container *pTree)
{
	// 计算树的叶子结点个数
	struct biTree_container ltree, rtree;

	// 为一棵空树
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
	// 计算树的叶子结点个数
	struct biTree_container ltree, rtree;

	// 为一棵空树
	if(pTree->root == 0)
	{
		return 0;
	}

	// 根为叶子结点
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
	// 计算二叉树的深度
	struct biTree_container ltree, rtree;
	int ldepth, rdepth;

	// 为一棵空树
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
	// 中序遍历二叉树
	struct biTree_container ltree, rtree;

	if(pTree->root != 0){ // 一棵非空的二叉树
		// 中序遍历左子树
		ltree.root = pTree->root->lchild;
		MidTraverse( &ltree );

		// 访问根节点
		printf("%d ", pTree->root->data);

		// 中序遍历右子树
		rtree.root = pTree->root->rchild;
		MidTraverse( &rtree );
	}

	return;
}

void PriorTraverse(struct biTree_container *pTree)
{
	// 先序遍历二叉树
	struct biTree_container ltree, rtree;

	if(pTree->root != 0){ // 一棵非空的二叉树
		// 访问根节点
		printf("%d ", pTree->root->data);

		// 先序遍历左子树
		ltree.root = pTree->root->lchild;
		PriorTraverse( &ltree );

		// 先序遍历右子树
		rtree.root = pTree->root->rchild;
		PriorTraverse( &rtree );
	}

	return;
}

void PostTraverse(struct biTree_container *pTree)
{
	// 后序遍历二叉树
	struct biTree_container ltree, rtree;

	if(pTree->root != 0){ // 一棵非空的二叉树
		// 后序遍历左子树
		ltree.root = pTree->root->lchild;
		PriorTraverse( &ltree );

		// 后序遍历右子树
		rtree.root = pTree->root->rchild;
		PriorTraverse( &rtree );

		// 访问根节点
		printf("%d ", pTree->root->data);
	}

	return;
}
