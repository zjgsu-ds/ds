#include <stdio.h>

#define maxLen 5
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

    // һ���洢�������ݵ�ѭ����������
    struct queue_container s;

    // ��ʼ��ջ����
    InitQueue(&s);

    // �ڶ�β����һ����b
    b = 3.6;
    EnQueue(&s, b);
    EnQueue(&s, 3.0);
    EnQueue(&s, 4.0);
    EnQueue(&s, 5.0);
    EnQueue(&s, 6.0);
    EnQueue(&s, 7.0);

    // ����ͷ����
    DeQueue(&s);

    return 0;
}

int IsEmpty(struct queue_container *s)
{
    return s->front == s->rear;
}

int IsFull(struct queue_container *s)
{
    return (s->rear+1) % maxLen == s->front;
}

void InitQueue(struct queue_container *s)
{
    s->front = s->rear = 0;
}

void EnQueue(struct queue_container *s,  elemType b)
{
    // ����b�������
    if (IsFull(s)) {
        printf("The queue is full!!!\n");
        return;
    }
    s->data[s->rear] = b;
    s->rear = (s->rear+1) % maxLen;

    return;
}

void DeQueue(struct queue_container *s)
{
    // ɾ����ͷԪ��
    s->front = (s->front+1) % maxLen;
}


