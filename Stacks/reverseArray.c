//Write a C program to print an array of elements in reverse order using recursive call
#include<stdio.h>

void reverse(int n, int a[])
{
    if(n == -1)
        return;
    printf("%d ", a[n]);
    reverse(n - 1, a);
}

int main()
{
    int i, n, a[10];
    printf("Enter the n value: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The reverse array is:\n");
    reverse(n - 1, a);
    return 0;
}