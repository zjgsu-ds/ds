
#include "stdio.h"

int Recursive_Fun(int n)
{
    return Recursive_Fun(n-1) + n;
}

int add_fun(int n)
{
    if(n == 1) {
        return 1;
    } else
        return add_fun(n-1) + n;
}


void Push(int n)
{
    if(n > 1) {
        Push(n-1);
    }

    printf("%d\n", n);
}

void main()
{
    Push(5);
}

void move(char X, int disk, char Y)
{
    printf("Move the disk: %d from the tower '%c' to the tower '%c'\n", disk, X, Y);
}

void hanoi(int n, char X, char Y, char Z)
{
    if(n == 1) {
        move(X, n, Z);
    } else {
        hanoi(n-1, X, Z, Y);
        move(X, n, Z);
        hanoi(n-1, Y, X, Z);
    }
}

void main()
{
    hanoi(3, 'X', 'Y', 'Z');

    getch();
}
