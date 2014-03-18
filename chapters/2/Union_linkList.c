#include <stdio.h>
#include <stdlib.h>

typedef char elemType;
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

int Length(struct data_listcontainer *s);
elemType getElem(struct data_listcontainer *s, int i);
void Union(struct data_listcontainer *LA, struct data_listcontainer *LB);
void print_list(struct data_listcontainer* s);

int main()
{
    int i;
    char line[128];

    /* �����洢�ռ��������ֱ��ż���A��B */
    struct data_listcontainer LA, LB;

    /* ��ʼ�������� */
    init(&LA);
    init(&LB);

    /* ���뼯��A������ */
    printf("����A:\n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* ����line�е�ÿ���ַ�,�����뵽������ĩβ */
        insert(&LA, i+1, line[i]);
        i++;
    }

    /* ���뼯��B������ */
    printf("����B:\n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* ����line�е�ÿ���ַ�,�����뵽������ĩβ */
        insert(&LB, i+1, line[i]);
        i++;
    }

    /* �ϲ�����A��B���ϲ����ݴ��ڼ���A�� */
    Union(&LA, &LB);

    printf("Result: \n");
    print_list(&LA);

    /* �ͷ������ռ� */
    destroy(&LA);
    destroy(&LB);

    return 0;
}

/* ��������LB�д��ڶ�LA�в����ڵ����ݲ��뵽LA�� */
void Union(struct data_listcontainer *LA, struct data_listcontainer *LB)
{
    int nA = Length(LA);
    int nB = Length(LB);
    int i;

    for(i = 1; i <= nB; i++) {
        /* �������LB�еĵ�i������ */
        elemType d = getElem(LB, i);

        /* �����ݲ��뵽����LA�ĵ�i������֮ǰ */
        if (search(LA, d) < 0) {
            nA++;
            insert(LA, nA, d);
        }
    }

    return;
}

/* ��ʼ����������һ��ͷ��� */
void init(struct data_listcontainer *s)
{
    struct data_node *node = 0;

    node = (struct data_node *)malloc(sizeof(struct data_node));
    if(node == 0) {
        printf("memory allocation error\n");
        return;
    }

    node->next = 0;
    s->head = node;
    return;
}

/* ���ҵ�i������ */
struct data_node* find(struct data_listcontainer* s, int i)
{
    struct data_node* p = s->head;
    int j = 0;

    if (i < 0)
        return NULL;

    while (j < i) {
        p = p->next;
        ++j;
    }

    return p;
}

/* ����һ�������ݽڵ� */
void insert(struct data_listcontainer *s, int i, elemType b)
{
    struct data_node* p = find(s, i-1);
    struct data_node *q = 0;

    /* Ϊb����һ���ڵ�ռ� */
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == 0) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    /* ���½ڵ���뵽��i�����ݽڵ�֮ǰ */
    q->next = p->next;
    p->next = q;

    return;
}

/* ɾ����i�����ݽڵ� */
void del(struct data_listcontainer *s, int i)
{
    struct data_node *p = find(s, i-1);
    struct data_node *q;
    int j = 1;

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

    while(p != 0) {
        if(p->data == b) {
            return j;
        }

        p = p->next;
        j++;
    }

    return -1;
}

/* ������� */
void destroy(struct data_listcontainer *s)
{
    struct data_node *p = s->head, *q;

    /* �ͷ�������ÿһ���ڵ� */
    while(p != 0) {
        q = p->next; /* ������һ���ڵ�ĵ�ַ */
        free(p);
        p = q;
    }

    s->head = 0;
}

/* ���������е����ݸ��� */
int Length(struct data_listcontainer *s)
{
    struct data_node *p= s->head->next;
    int n = 0;

    while(p) {
        n++;
        p = p->next;
    }

    return n;
}

/* ��ӡ���� */
void print_list(struct data_listcontainer* s)
{
    struct data_node* p = s->head->next;

    while (p) {
        putchar(p->data);
        p = p->next;
    }

    putchar('\n');
}

/* ��������еĵ�i������ */
elemType getElem(struct data_listcontainer *s, int i)
{
    return find(s, i)->data;
}
