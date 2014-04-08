#include <stdio.h>

int main()
{
    int m, n, i, j;
    char s[100];
    char t[100];

    scanf("%d%d", &m, &n);

    scanf("%s%s", s, t);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            if (s[i+j] != t[j])
                break;

        if (j == n)
            break;
    }

    if (j == n)
        printf("%d\n", i+1);
    else
        printf("%d\n", 0);

    return 0;
}
