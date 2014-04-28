#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild, *rchild;
};

struct TreeNode* CreateBiTree();
struct TreeNode* insert_node(struct TreeNode *q, ElemType x);
int same_tree(struct TreeNode* t1, struct TreeNode* t2);

int main()
{
    int n;

    scanf("%d\n", &n);

    while (n != 0) {
        struct TreeNode* t1 = CreateBiTree();
        struct TreeNode* t2 = CreateBiTree();

        if (same_tree(t1, t2))
            printf("YES\n");
        else
            printf("NO\n");

        n--;
    }

    return 0;
}

struct TreeNode* CreateBiTree()
{
    // 创建一棵二叉树
    ElemType b;
    struct TreeNode *root = NULL;

    while ((b = getchar()) != '\n') {
        root = insert_node(root, b); 
    }

    return root;
}

struct TreeNode* insert_node(struct TreeNode *root, ElemType x)
{
    if (root == NULL) {
        struct TreeNode *p;
        p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        p->data = x;
        p->lchild = NULL;
        p->rchild = NULL;

        return p;
    }

    if (x < root->data)
        root->lchild = insert_node(root->lchild, x);
    else
        root->rchild = insert_node(root->rchild, x);

    return root;
}

int same_tree(struct TreeNode* t1, struct TreeNode* t2)
{
    if (t1 == NULL || t2 == NULL)
        return t1 == t2;

    return t1->data == t2->data && same_tree(t1->lchild, t2->lchild) && same_tree(t1->rchild, t2->rchild);
}
