#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild, *rchild;
};

struct TreeNode* CreateBiTree();

// ����������
void mid_traverse(struct TreeNode *root);
void post_traverse(struct TreeNode *root);
void level_traverse(struct TreeNode *root);

int main()
{
    // һ�ö���������
    struct TreeNode* root = NULL;

    // �����ö�����:�������ι�ϵ�����ݷ���������
    root = CreateBiTree();

    // �������
    mid_traverse(root);

    putchar(' ');

    // ��������
    post_traverse(root);

    putchar(' ');

    // ��α���
    level_traverse(root);

    putchar('\n');

    return 0;
}

struct TreeNode* CreateBiTree()
{
    // ����һ�ö�����
    ElemType b;
    struct TreeNode *root;

    // �����û���������Ϊ��(�������Ϊ��,��Ϊ����)
    scanf("%c", &b);
    if(b == '#')
        return NULL;

    // �����������ĸ�
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = b;

    // ������������
    root->lchild = CreateBiTree();
    root->rchild = CreateBiTree();

    return root;
}

// �������������
void mid_traverse(struct TreeNode *root)
{

    if(root != NULL){ // һ�÷ǿյĶ�����
        // �������������
        mid_traverse(root->lchild);

        // ���ʸ��ڵ�
        printf("%c", root->data);

        // �������������
        mid_traverse(root->rchild);
    }
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
