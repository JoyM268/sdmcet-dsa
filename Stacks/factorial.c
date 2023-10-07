//Write C program to find factorial of a given number recursively
#include<stdio.h>

int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return (n * fact(n - 1));
}

int main()
{
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, fact(n));
}