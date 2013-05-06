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

// 遍历二叉树
void prior_traverse(struct TreeNode *root);
void post_traverse(struct TreeNode *root);

int main()
{
    // 一棵二叉树容器
    struct TreeNode* root = NULL;
    char level[100];
    char mid[100];
    int i, n;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        gets(level);
        gets(mid);
        root = CreateBiTree(level, mid, strlen(mid));
        prior_traverse(root);
        putchar('\n');
        post_traverse(root);
        putchar('\n');
    }

    return 0;
}

int find(char x, char* mid, int len)
{
    int i;

   for (i = 0; i < len; i++)
      if (mid[i] == x)
         return i;

  return -1; 
}

struct TreeNode* CreateBiTree(char* level, char* mid, int len)
{
    struct TreeNode* root = NULL;
    int i, j;

    if (len == 0)
        return NULL;

    // Find root
    for (i = 0; level[i] != '\0'; i++) {
        j = find(level[i], mid, len);

        if (j >= 0)
            break;
    }

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = mid[j];
    
    root->lchild = CreateBiTree(level, mid, j);
    root->rchild = CreateBiTree(level, mid+j+1, len-j-1);

    return root;
}

void prior_traverse(struct TreeNode *root)
{
    if(root != NULL){ // 一棵非空的二叉树
        // 访问根节点
        printf("%c", root->data);

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
        printf("%c", root->data);
    }
}
