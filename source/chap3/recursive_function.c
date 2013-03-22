#include <stdio.h>

int Recursive_Fun(int n)
{
    return Recursive_Fun(n-1) + n;
}

int add_fun(int n)
{
    if(n == 1)
        return 1;
    else
        return add_fun(n-1) + n;
}


void Push(int n)
{
    if(n > 1) {
        Push(n-1);
    }

    printf("%d\n", n);
}

int main()
{
    Push(5);

    return 0;
}

