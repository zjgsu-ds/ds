#include <stdio.h>

#define maxLen 100

int main()
{
    // 数据存储空间
    int data[maxLen] = {1, 2, 3};
    int n = 3;

    // 其它变量
    int j, i, b;

    // 在第i个位置前插入一个数b
    i = 1;
    b = 3;

    for(j = n-1; j >= (i-1); j --)
        data[j+1] = data[j];

    data[i-1] = b;
    n ++;

    // 删除第i个整数
    i = 1;

    for(j = i; j <= n-1; j ++)
        data[j-1] = data[j];

    n--;

    // 查找整数 b
    b = 3;

    for(j = 0; j <= n-1; j ++)
        if(b == data[j])
            break;

    if(j >= n)
        printf("no found of %d\n", b);
    else
        printf("found of %d\n", b);

    return 0;
}
