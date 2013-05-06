#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild, *rchild;
};

void merge(struct TreeNode* nodes[], int n);
int weight(struct TreeNode* root, int depth);

int main()
{
    int i, n;
    struct TreeNode* nodes[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        nodes[i] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        scanf("%d", &nodes[i]->data);
    }

    for (i = n; i > 1; i--)
        merge(nodes, i);

    printf("%d\n", weight(nodes[0], 0));

    return 0;
}

int find_min(struct TreeNode* nodes[], int n)
{
    int i, min_i;

    min_i = 0;
    for (i = 1; i < n; i++)
        if (nodes[i]->data < nodes[min_i]->data)
            min_i = i;

    return min_i;
}

void move_min_to_end(struct TreeNode* nodes[], int n)
{
    struct TreeNode* tmp;
    int i = find_min(nodes, n);

    tmp = nodes[i];
    nodes[i] = nodes[n-1];
    nodes[n-1] = tmp;
}

void merge(struct TreeNode* nodes[], int n)
{
    int i, j;
    struct TreeNode* parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    move_min_to_end(nodes, n);
    move_min_to_end(nodes, n-1);

    parent->lchild = nodes[n-1];
    parent->rchild = nodes[n-2];
    parent->data = parent->lchild->data + parent->rchild->data;

    nodes[n-2] = parent;
}

int weight(struct TreeNode* root, int depth)
{
    if (root == NULL)
        return 0;

    if (root->lchild == NULL && root->rchild == NULL)
        return root->data * depth;

    return weight(root->lchild, depth+1) + weight(root->rchild, depth + 1);
}
