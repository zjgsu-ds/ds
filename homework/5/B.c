
#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
struct data_node {
    elemType data;
    struct data_node *next;
};

struct data_listcontainer {
    struct data_node *head;
};

void init(struct data_listcontainer *s);
void insert(struct data_listcontainer *s, int i, elemType b);
void del(struct data_listcontainer *s, int i);
int search(struct data_listcontainer *s, elemType b);
void destroy(struct data_listcontainer *s);
int length(struct data_listcontainer *s);

int main()
{
    struct data_listcontainer s;

    init(&s);


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

int length_helper(struct data_node *p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + length_helper(p->next);
}

int length(struct data_listcontainer *s)
{
    return length_helper(s->head->next);
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
    q->data = b;

    /* ���½ڵ���뵽��i�����ݽڵ�֮ǰ */
    q->next = p->next;
    p->next = q;
}

void del(struct data_listcontainer *s, int i)
{
    /* ɾ����i�����ݽڵ� */
    struct data_node *q;
    struct data_node *p = find(s, i-1); /* �ҵ���i-1������ */

    /* �޸�ָ�룺�ѵ�i���ڵ���������Ƴ� */
    q = p->next;
    p->next = q->next;

    /* �ͷŽڵ��ڴ� */
    free(q);
}

/* �����������Ƿ������b.
   ������,�������״γ��ֵ�λ��;���򷵻�-1
 */
int search(struct data_listcontainer *s, elemType b)
{
    struct data_node *p = s->head->next;
    int j = 1;

    while(p != NULL) {
        if(p->data == b) {
            return j;
        }

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
