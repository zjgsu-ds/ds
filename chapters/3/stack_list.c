#include <stdio.h>
#include <stdlib.h>

typedef float elemType;
struct data_node {
    elemType data;
    struct data_node *next;
};

struct stack_listcontainer {
    struct data_node *top;
};

void InitStack(struct stack_listcontainer *s);
void Push(struct stack_listcontainer *s,  elemType b);
elemType Pop(struct stack_listcontainer *s);
int IsEmpty(struct stack_listcontainer *s);
int Count(struct stack_listcontainer *s);

int main()
{
    // һ���洢�������ݵ�ջ����
    struct stack_listcontainer s;

    // ��ʼ��ջ����
    InitStack(&s);

    // ��ջ���Ŷ��Ԫ��
    Push(&s, 1.0);
    Push(&s, 2.0);
    Push(&s, 3.0);

    printf("Count: %d\n", Count(&s));

    // ��ջ������
    printf("Pop: %f\n", Pop(&s));

    printf("Count: %d\n", Count(&s));
    
    return 0;
}


void InitStack(struct stack_listcontainer *s)
{
    s->top = NULL;
}

void Push(struct stack_listcontainer *s,  elemType b)
{
    // ����b����ջ��
    struct data_node *q = NULL;

    // Ϊb����һ���ڵ�ռ�
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == NULL) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    // ���½ڵ�嵽ջ��
    q->next = s->top;
    s->top = q;
}

elemType Pop(struct stack_listcontainer *s)
{
    // ɾ��ջ��Ԫ�أ�������ջ��Ԫ��
    struct data_node *p = s->top->next;
    elemType b = s->top->data;

    // �ͷ�ջ���ڵ�
    free(s->top);
    s->top = p;

    return b;
}

int IsEmpty(struct stack_listcontainer *s)
{
    return s->top == NULL;
}

int Count(struct stack_listcontainer *s)
{
    int n = 0;
    struct data_node *p = s->top;

    while (p) {
        n++;
        p = p->next;
    }

    return n;
}


