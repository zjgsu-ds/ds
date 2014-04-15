
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char elemType[100];
struct data_node {
    elemType data;
    struct data_node *next;
};

struct data_listcontainer {
    struct data_node *head;
};

void init(struct data_listcontainer *s);
void insert(struct data_listcontainer *s, int i, elemType b);
int search(struct data_listcontainer *s, elemType b);
void destroy(struct data_listcontainer *s);

int main()
{
    int n, i, count;
    elemType b;

    /* һ���������ݴ洢�ռ����� */
    struct data_listcontainer s;
    struct data_node *p;

    scanf("%d", &n);

    /* ��ʼ�������ռ� */
    init(&s);

    count = 0;
    for (i = 0 ; i < n; i++) {
        scanf("%s", b);
        if (search(&s, b) == -1)
            insert(&s, ++count, b);
    }

    for (p = s.head->next; p != NULL; p = p->next)
        printf("%s ", p->data);

    printf("\n");

    /* ��������ռ� */
    destroy(&s);

    return 0;
}

/* ��ʼ����������һ��ͷ��� */
void init(struct data_listcontainer *s)
{
    struct data_node *node = NULL;

    node = (struct data_node *)malloc(sizeof(struct data_node));
    if(node == NULL) {
        printf("memory allocation error\n");
        return;
    }

    node->next = NULL;
    s->head = node;
}

/* ���ҵ�i������ */
struct data_node* find_helper(struct data_node *p, int i)
{
    if (i == 0 || p == NULL)
        return p;
    else
        return find_helper(p->next, i-1);

}

struct data_node* find(struct data_listcontainer* s, int i)
{
    return find_helper(s->head, i);
}

/* ��λ��i����һ�������ݽڵ� */
void insert(struct data_listcontainer *s, int i, elemType b)
{
    struct data_node *q = NULL;
    struct data_node *p = find(s, i-1); /* �ҵ���i-1������ */

    if (p == NULL) {
        printf("No such node, insertion failed.\n");
        return;
    }

    /* Ϊb����һ���ڵ�ռ� */
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == NULL) {
        printf("memory allocation error\n");
        return;
    }
    strcpy(q->data, b);

    /* ���½ڵ���뵽��i�����ݽڵ�֮ǰ */
    q->next = p->next;
    p->next = q;
}

/* �����������Ƿ������b.
   ������,�������״γ��ֵ�λ��;���򷵻�-1
 */
int search(struct data_listcontainer *s, elemType b)
{
    struct data_node *p = s->head->next;
    int j = 1;

    while(p != NULL) {
        if(strcmp(p->data, b) == 0)
            return j;

        p = p->next;
        j++;
    }

    return -1;
}

void destroy(struct data_listcontainer *s)
{
    /* ������� */
    struct data_node *p = s->head, *q;

    /* �ͷ�������ÿһ���ڵ� */
    while(p != NULL) {
        q = p->next; /* ������һ���ڵ�ĵ�ַ */
        free(p);
        p = q;
    }

    s->head = NULL;
}
