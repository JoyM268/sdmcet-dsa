//Write a C program to reverse a number using recursion
#include<stdio.h>

void reverse(int n)
{
    printf("%d", n % 10);
    if(n / 10 == 0)
        return;
    reverse(n / 10);
}

int main()
{
    int n;
    printf("Enter the no. to be reversed: ");
    scanf("%d", &n);
    reverse(n);
    printf("\n");
    return 0;
}