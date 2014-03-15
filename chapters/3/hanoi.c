#include <stdio.h>

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

int main()
{
    hanoi(3, 'X', 'Y', 'Z');

    return 0;
}
