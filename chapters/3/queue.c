#include <stdio.h>

const int maxLen = 100;
typedef float elemType;
struct queue_container {
    elemType data[maxLen];
    int front, rear;
};

void InitQueue(struct queue_container *s);
void EnQueue(struct queue_container *s,  elemType b);
void DeQueue(struct queue_container *s);

int main()
{
    elemType b;

    // һ���洢�������ݵĶ�������
    struct queue_container s;

    // ��ʼ��ջ����
    InitQueue(&s);

    // �ڶ�β����һ����b
    b = 3.6;
    EnQueue(&s, b);

    // ����ͷ����
    DeQueue(&s);

    return 0;
}


void InitQueue(struct queue_container *s)
{
    s->front = s->rear = 0;
}

void EnQueue(struct queue_container *s,  elemType b)
{
    // ����b�������
    s->data[s->rear] = b;
    s->rear++;

    return;
}

void DeQueue(struct queue_container *s)
{
    // ɾ����ͷԪ��
    s->front ++;
}




