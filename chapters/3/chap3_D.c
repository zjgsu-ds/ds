#include <stdio.h>

#define maxLen  100

typedef int elemType;
struct data_container {
    elemType data[maxLen];
    int n;
};

void init(struct data_container* s);
void insert(struct data_container *s, int i, elemType b);
void del(struct data_container *s, int i);
int search(struct data_container *s, elemType b);
int kickout(struct data_container *s, int start, int m);

int main()
{
    struct data_container s;
    int i, m, n;

    init(&s);

    scanf("%d%d", &n, &m);

    /* 填充数组 */
    for (i = 1; i <= n; i++)
        insert(&s, i, i);

    i = 0;
    while (s.n > 1) {
        i = kickout(&s, i, m);
    }

    printf("%d\n", s.data[0]);

    return 0;
}

/* Kick out one person, return new start index */
int kickout(struct data_container *s, int start, int m)
{
    int i;

    for (i = 1; i < m; i++, start = (start+1) % s->n)
        ;

    del(s, start + 1);

    return start % s->n;
}

void init(struct data_container* s)
{
    s->n = 0;
}

/* 在第i个位置前插入一个数b */
void insert(struct data_container *s, int i, elemType b)
{
    int j;

    for(j = s->n-1; j >= (i-1); j--) {
        printf("j = %d\n", j);
        s->data[j+1] = s->data[j];
    }

    s->data[i-1] = b;
    s->n++;
}

/* 删除第i个整数 */
void del(struct data_container *s, int i)
{
    int j = 0;

    for(j = i; j <= s->n-1; j++)
        s->data[j-1] = s->data[j];

    s->n--;
}

/* 查找整数 b */
int search(struct data_container *s, elemType b)
{
    int j = 0;

    for(j = 0; j <= s->n-1; j++)
        if(b == s->data[j])
            break;

    return (j >= s->n ? -1: j+1);
}
