#include <stdio.h>
#include <stdlib.h>

#define maxLen 100
typedef double elemType;
struct queue_container {
    elemType data[maxLen];
    int front, rear;
    int size;
};

void InitQueue(struct queue_container *s);
int EnQueue(struct queue_container *s,  elemType b);
int DeQueue(struct queue_container *s, elemType *b);
int HeadQueue(struct queue_container *s, elemType *b);

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

    // ����ͷ����
    DeQueue(&s, &b);

    return 0;
}

void InitQueue(struct queue_container *s)
{
    s->front = s->rear = 0;
    s->size = 0;
}

int EnQueue(struct queue_container *s,  elemType b)
{
    // ����b�������
    if(s->size == maxLen) {
        // ��������
        return -1;
    }

    s->data[s->rear] = b;
    s->rear = (s->rear+1) % maxLen;
    s->size ++;

    return 1;
}

int DeQueue(struct queue_container *s, elemType *b)
{
    // ɾ����ͷԪ��
    if(s->rear == s->front) {
        // ����Ϊ��
        return -1;
    }

    *b = s->front;
    s->front = (s->front+1) % maxLen;
    s->size --;

    return 1;
}

int HeadQueue(struct queue_container *s, elemType *b)
{
    // ��ȡ��ͷԪ��
    if(s->rear == s->front) {
        // ����Ϊ��
        return -1;
    }

    *b = s->front;

    return 1;
}




