//Write a C program to find nth element of fibonacci series
#include<stdio.h>

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return (fibonacci(n - 1) + fibonacci(n - 2));    
}

main()
{
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Fib(%d) is %d\n", n, fibonacci(n));
}