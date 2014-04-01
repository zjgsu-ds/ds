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

    // 一个存储浮点数据的循环队列容器
    struct queue_container s;

    // 初始化栈容器
    InitQueue(&s);

    // 在队尾放入一个数b
    b = 3.6;
    EnQueue(&s, b);
    EnQueue(&s, 3.0);
    EnQueue(&s, 4.0);
    EnQueue(&s, 5.0);
    EnQueue(&s, 6.0);
    EnQueue(&s, 7.0);

    // 出队头数据
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
    // 把数b放入队列
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
    // 删除队头元素
    s->front = (s->front+1) % maxLen;
}


