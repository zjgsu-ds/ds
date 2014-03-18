#include <stdio.h>

int akm(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return akm(m-1, 1);
    else
        return akm(m-1, akm(m, n-1));
}

int main()
{
    int m, n;

    scanf("%d%d", &m, &n);

    printf("%d\n", akm(m,n));

    return 0;
}