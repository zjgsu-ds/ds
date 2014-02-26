#include <stdio.h>

#define maxLen  100
#define TRUE 1
#define FALSE 0

typedef char elemType;
struct data_container {
    elemType data[maxLen];
    int n;
};

int insert(struct data_container *s, int i, elemType b);
int del(struct data_container *s, int i);
int search(struct data_container *s, elemType b);
int Length(struct data_container *s);
elemType getElem(struct data_container *s, int i);
void Union(struct data_container *LA, struct data_container *LB);

int main()
{
    int i;
    char line[128];

    /* 两个存储空间容器，分别存放集合A和B */
    struct data_container LA, LB;

    /* 初始化空容器 */
    LA.n = 0;
    LB.n = 0;

    /* 输入集合A的数据 */
    printf("输入A: \n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* 读出line中的每个字符,并插入到容器的末尾 */
        insert(&LA, LA.n+1, line[i]);
        i++;
    }

    /* 输入集合B的数据 */
    printf("输入B: \n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* 读出line中的每个字符,并插入到容器的末尾 */
        insert(&LB, LB.n+1, line[i]);
        i++;
    }

    /* 合并集合A和B，合并数据存在集合A中 */
    Union(&LA, &LB);

    printf("Result:\n");

    for (i = 0; i < LA.n;++i)
        putchar(LA.data[i]);

    putchar('\n');

    return 0;
}

/* 将所有在LB中存在而LA中不存在的数据插入到LA中 */
void Union(struct data_container *LA, struct data_container *LB)
{
    int i;

    for(i = 1; i <= LB->n; i++) {
        /* 获得容器LB中的第i个数据 */
        elemType d = getElem(LB, i);

        /* 把数据插入到容器LA的第i个数据之前 */
        if (search(LA, d) < 0)
            insert(LA, LA->n + 1, d);
    }

    return;
}

/* 在第i个位置插入一个数b */
int insert(struct data_container *s, int i, elemType b)
{
    int j = 0;

    /* 检查参数合法性
       插入位置只能在范围[1, n+1]，且有足够的存储空间
     */
    if(i < 0 || i > (s->n+1) || s->n == maxLen)
        return FALSE;


    for(j = s->n-1; j >= (i-1); j--)
        s->data[j+1] = s->data[j];

    s->data[i-1] = b;
    s->n++;

    return TRUE;
}

/* 删除第i个整数 */
int del(struct data_container *s, int i)
{
    int j = 0;

    /* 检查参数合法性
       i的范围为:[1, n]
    */
    if(i < 0 || i > s->n)
        return FALSE;

    for(j = i; j <= s->n-1; j++)
        s->data[j-1] = s->data[j];

    s->n--;

    return TRUE;
}

/* 查找整数 b */
int search(struct data_container *s, elemType b)
{
    int j = 0;

    for(j = 0; j < s->n; j++)
        if(b == s->data[j])
            break;

    return (j >= s->n ? -1: j+1);
}

/* 计算容器中的数据个数 */
int Length(struct data_container *s)
{
    return s->n;
}

/* 获得容器s中的第i个数据 */
elemType getElem(struct data_container *s, int i)
{
    return s->data[i-1];
}


