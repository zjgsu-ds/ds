#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild, *rchild;
};

struct TreeNode* CreateBiTree();

// 遍历二叉树
void mid_traverse(struct TreeNode *root);
void post_traverse(struct TreeNode *root);
void level_traverse(struct TreeNode *root);

int main()
{
    // 一棵二叉树容器
    struct TreeNode* root = NULL;

    // 构建该二叉树:依据树形关系把数据放入容器中
    root = CreateBiTree();

    // 中序遍历
    mid_traverse(root);

    putchar(' ');

    // 后续遍历
    post_traverse(root);

    putchar(' ');

    // 层次遍历
    level_traverse(root);

    putchar('\n');

    return 0;
}

struct TreeNode* CreateBiTree()
{
    // 创建一棵二叉树
    ElemType b;
    struct TreeNode *root;

    // 接收用户的输入作为根(如果输入为零,则为空树)
    scanf("%c", &b);
    if(b == '#')
        return NULL;

    // 建立二叉树的根
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = b;

    // 创建左右子树
    root->lchild = CreateBiTree();
    root->rchild = CreateBiTree();

    return root;
}

// 中序遍历二叉树
void mid_traverse(struct TreeNode *root)
{

    if(root != NULL){ // 一棵非空的二叉树
        // 中序遍历左子树
        mid_traverse(root->lchild);

        // 访问根节点
        printf("%c", root->data);

        // 中序遍历右子树
        mid_traverse(root->rchild);
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
        printf("%c", root->data);
    }
}

void level_traverse(struct TreeNode *root)
{
    struct TreeNode* q[2000];
    int front, rear;

    front = rear = 0;
    q[rear++] = root;

    while (front != rear) {
        printf("%c", q[front]->data);

        if (q[front]->lchild)
            q[rear++] = q[front]->lchild;

        if (q[front]->rchild)
            q[rear++] = q[front]->rchild;

        front++;
    }
}
