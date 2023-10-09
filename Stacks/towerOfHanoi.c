//Write a C program to implement tower of hanoi using recurrsion
#include<stdio.h>

void towerOfHanoi(int n, char source, char temp, char destination)
{
    if(n == 1)
    {
        printf("Move disc %d from %c to %c\n", n, source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, temp);
    printf("Move disc %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, temp, source, destination);
}

int main()
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}