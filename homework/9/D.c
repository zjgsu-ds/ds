#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;
struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild, *rchild;
};

struct TreeNode* CreateBiTree(char* prior, char* mid, int len);

// ����������
void post_traverse(struct TreeNode *root);

int main()
{
    // һ�ö���������
    struct TreeNode* root = NULL;
    char prior[100];
    char mid[100];
    int i;

    for (i = 0; i < 2; i++) {
        scanf("%s%s", prior, mid);
        root = CreateBiTree(prior, mid, strlen(prior));
        post_traverse(root);
        putchar('\n');
    }

    return 0;
}

struct TreeNode* CreateBiTree(char* prior, char* mid, int len)
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

void post_traverse(struct TreeNode *root)
{
    if(root != NULL){ // һ�÷ǿյĶ�����
        // �������������
        post_traverse(root->lchild);

        // �������������
        post_traverse(root->rchild);

        // ���ʸ��ڵ�
        printf("%c", root->data);
    }
}
