#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild, *rchild;
};

struct TreeNode* CreateBiTree(int* prior, int* mid, int len);
int tree_depth(struct TreeNode *root);

int main()
{
    // Ò»¿Ã¶þ²æÊ÷ÈÝÆ÷
    struct TreeNode* root = NULL;
    int prior[100];
    int mid[100];
    int i, j, m, n;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &m);

        for (j = 0; j < m; j++)
            scanf("%d", prior+j);

        for (j = 0; j < m; j++)
            scanf("%d", mid+j);

        root = CreateBiTree(prior, mid, m);

        printf("%d\n", tree_depth(root));
    }

    return 0;
}

struct TreeNode* CreateBiTree(int* prior, int* mid, int len)
{
    struct TreeNode* root = NULL;
    int i;

    if (len == 0)
        return NULL;

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = prior[0];

    i = 0;
    while (mid[i] != prior[0])
        i++;

    root->lchild = CreateBiTree(prior+1, mid, i);
    root->rchild = CreateBiTree(prior+i+1, mid+i+1, len-i-1);

    return root;
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
