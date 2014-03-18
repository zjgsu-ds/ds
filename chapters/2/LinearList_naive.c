#include <stdio.h>

#define maxLen 100

int main()
{
    int data[maxLen] = {1, 2, 3};
    int n = 3;
    int j, i, b;

    /* 在第i个位置插入一个数b */
    i = 1;
    b = 5;

    for(j = n-1; j >= (i-1); j--)
        data[j+1] = data[j];

    data[i-1] = b;
    n++;

    /* 删除第i个整数 */
    i = 1;

    for(j = i; j <= n-1; j++)
        data[j-1] = data[j];

    n--;

    /* 查找整数 b */
    b = 3;

    for(j = 0; j <= n-1; j++)
        if(b == data[j])
            break;

    if(j >= n)
        printf("%d not found\n", b);
    else
        printf("%d found\n", b);

    return 0;
}
