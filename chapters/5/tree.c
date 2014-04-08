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

// ����������
void mid_traverse(struct TreeNode *root);
void prior_traverse(struct TreeNode *root);
void post_traverse(struct TreeNode *root);

int main()
{
    // һ�ö���������
    struct TreeNode* root = NULL;

    // �����ö�����:�������ι�ϵ�����ݷ���������
    root = CreateBiTree();

    // ����һ����,��Ϊ����������
    insert_left_node(root, 5);

    // �������Ľ�����
    printf("The number of tree nodes is: %d\n", tree_node_number(root));

    // ��������Ҷ�ӽ����
    printf("The number of leaf nodes is: %d\n", leaf_node_number(root));

    // �����������
    printf("The depth of the tree is: %d\n", tree_depth(root));

    return 0;
}

struct TreeNode* CreateBiTree()
{
    // ����һ�ö�����
    ElemType b;
    struct TreeNode *root;

    // �����û���������Ϊ��(�������Ϊ��,��Ϊ����)
    scanf("%d", &b);
    if(b == 0)
        return NULL;

    // �����������ĸ�
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = b;

    // ������������
    root->lchild = CreateBiTree();
    root->rchild = CreateBiTree();

    return root;
}

void insert_left_node(struct TreeNode *root, ElemType x)
{
    // ������x��Ϊq�����ӽ��
    struct TreeNode *p;

    // Ϊx�½�һ�����
    p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = x;

    // ��q����������Ϊp��������,p��������Ϊ��
    p->lchild = root->lchild;
    p->rchild = NULL;

    // ���½����p��Ϊq������
    root->lchild = p;

    return;
}

int tree_node_number(struct TreeNode *root)
{
    // Ϊһ�ÿ���
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

// �������������
void mid_traverse(struct TreeNode *root)
{

    if(root != NULL){ // һ�÷ǿյĶ�����
        // �������������
        mid_traverse(root->lchild);

        // ���ʸ��ڵ�
        printf("%d ", root->data);

        // �������������
        mid_traverse(root->rchild);
    }
}

// �������������
void prior_traverse(struct TreeNode *root)
{
    if(root != NULL){ // һ�÷ǿյĶ�����
        // ���ʸ��ڵ�
        printf("%d ", root->data);

        // �������������
        prior_traverse(root->lchild);

        // �������������
        prior_traverse(root->rchild);
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
        printf("%d ", root->data);
    }
}
