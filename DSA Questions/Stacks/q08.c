//Write a recursive call to move ‘n’ discs from peg A to peg C using B as auxiliary peg to solve the Tower of Hanoi problem.
#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int n, char source, char aux, char dest)
{
    if(n == 1)
    {
        printf("Move disc %d from %c to %c\n", n, source, dest);
        return;
    }
    towerOfHanoi(n - 1, source, dest, aux);
    printf("Move disc %d from %c to %c\n", n, source, dest);
    towerOfHanoi(n - 1, aux, source, dest);
}

int main()
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
}