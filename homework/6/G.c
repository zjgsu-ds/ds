#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int knapsack(int n, int T, int weight[], int cost[])
{
    if (n == 0)
        return 0;

    if (weight[0] <= T)
        return max(cost[0] + knapsack(n-1, T-weight[0], weight+1, cost+1),
                knapsack(n-1, T, weight+1, cost+1));
    else
        return knapsack(n-1, T, weight+1, cost+1);
}

int main()
{
    int n, T, i;
    int weight[100];
    int cost[100];

    scanf("%d%d", &n, &T);

    for (i = 0; i < n; i++)
        scanf("%d%d", &weight[i], &cost[i]);

    printf("%d\n", knapsack(n, T, weight, cost));

    return 0;
}
