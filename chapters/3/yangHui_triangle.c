#include "stdio.h"
#include "stdlib.h"

#define maxLen  100
typedef int elemType;
struct queue_container {
    elemType data[maxLen];
    int front, rear;
    int size;
};

void InitQueue(struct queue_container *s);
int EnQueue(struct queue_container *s,  elemType b);
int DeQueue(struct queue_container *s, elemType *b);
int HeadQueue(struct queue_container *s, elemType *b);
void PrintYangHuiTriangle(int n);

int main()
{
    int row = 0;
    char yes;

    while(1) {
        // �������
        printf("Please Input Row of YangHui Triangle:");
        scanf("%d", &row);

        PrintYangHuiTriangle(row);

        // �Ƿ����
        printf("Continue? (Y/N)");
        yes = getchar();
        printf("\n");

        if(yes != 'y' && yes != 'Y') {
            break;
        }
    }

    return 0;
}

void PrintYangHuiTriangle(int n)
{
    // ��ӡn���������
    int i = 0, k;
    elemType s, e;

    // һ���洢������ѭ����������
    struct queue_container q;
    InitQueue(&q);

    // ��һ��Ԫ��
    EnQueue(&q, 0);
    EnQueue(&q, 1);
    EnQueue(&q, 1);
    EnQueue(&q, 0);

    for(i = 1; i <= n; i ++) {
        // ��ӡ��i��Ԫ��,�������i+1��Ԫ��

        // ����i����ʼλ��
        for(k = 1; k <= (n-i); k ++) {
            printf(" ");
        }

        // ����ȡ����i�е�Ԫ��,�������i+1�е���ӦԪ��
        if(i < n)
            EnQueue(&q, 0); // ��i+1����ͷ0Ԫ��
        do {
            DeQueue(&q, &s);
            HeadQueue(&q, &e);
            if(e != 0)
                printf("%d ", e); // ��ӡ��i�еĸ�Ԫ��
            if(i < n)
                EnQueue(&q, s+e); // �����i+1�еĶ�ӦԪ��
        } while(e != 0); // e == 0: ��i��Ԫ����ȡ��

        printf("\n"); // ��i�д�ӡ����
        DeQueue(&q, &s); // ɾ����i��ĩβ0Ԫ��
        if(i < n)
            EnQueue(&q, 0); // ��i+1�н�β0Ԫ��
    }

    return;
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

    *b = s->data[s->front];
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

    *b = s->data[s->front];

    return 1;
}




