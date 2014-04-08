#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild, *rchild;
};

struct TreeNode* CreateBiTree();
void insert_left_node(struct TreeNode *q, ElemType x);
int tree_node_number(struct TreeNode *root);
int leaf_node_number(struct TreeNode *root);
int tree_depth(struct TreeNode *root);

// 遍历二叉树
void mid_traverse(struct TreeNode *root);
void prior_traverse(struct TreeNode *root);
void post_traverse(struct TreeNode *root);

int main()
{
    // 一棵二叉树容器
    struct TreeNode* root = NULL;

    // 构建该二叉树:依据树形关系把数据放入容器中
    root = CreateBiTree();

    // 插入一个数,作为根结点的左孩子
    insert_left_node(root, 5);

    // 计算树的结点个数
    printf("The number of tree nodes is: %d\n", tree_node_number(root));

    // 计算树的叶子结点数
    printf("The number of leaf nodes is: %d\n", leaf_node_number(root));

    // 计算树的深度
    printf("The depth of the tree is: %d\n", tree_depth(root));

    return 0;
}

struct TreeNode* CreateBiTree()
{
    // 创建一棵二叉树
    ElemType b;
    struct TreeNode *root;

    // 接收用户的输入作为根(如果输入为零,则为空树)
    scanf("%d", &b);
    if(b == 0)
        return NULL;

    // 建立二叉树的根
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = b;

    // 创建左右子树
    root->lchild = CreateBiTree();
    root->rchild = CreateBiTree();

    return root;
}

void insert_left_node(struct TreeNode *root, ElemType x)
{
    // 插入数x作为q的左孩子结点
    struct TreeNode *p;

    // 为x新建一个结点
    p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = x;

    // 把q的左子树作为p的左子树,p的右子树为空
    p->lchild = root->lchild;
    p->rchild = NULL;

    // 把新建结点p作为q的左孩子
    root->lchild = p;

    return;
}

int tree_node_number(struct TreeNode *root)
{
    // 为一棵空树
    if(root == NULL)
        return 0;
    else
        return 1 + tree_node_number(root->lchild) + tree_node_number(root->rchild);
}

int leaf_node_number(struct TreeNode *root)
{
    if(root == NULL)
        return 0;
    else if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    else
        return leaf_node_number(root->lchild) + leaf_node_number(root->rchild);
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int tree_depth(struct TreeNode *root)
{
    if(root == NULL)
        return 0;
    else
        return 1 + max(tree_depth(root->lchild), tree_depth(root->rchild));
}

// 中序遍历二叉树
void mid_traverse(struct TreeNode *root)
{

    if(root != NULL){ // 一棵非空的二叉树
        // 中序遍历左子树
        mid_traverse(root->lchild);

        // 访问根节点
        printf("%d ", root->data);

        // 中序遍历右子树
        mid_traverse(root->rchild);
    }
}

// 先序遍历二叉树
void prior_traverse(struct TreeNode *root)
{
    if(root != NULL){ // 一棵非空的二叉树
        // 访问根节点
        printf("%d ", root->data);

        // 先序遍历左子树
        prior_traverse(root->lchild);

        // 先序遍历右子树
        prior_traverse(root->rchild);
    }
}

void post_traverse(struct TreeNode *root)
{
    if(root != NULL){ // 一棵非空的二叉树
        // 后序遍历左子树
        post_traverse(root->lchild);

        // 后序遍历右子树
        post_traverse(root->rchild);

        // 访问根节点
        printf("%d ", root->data);
    }
}
