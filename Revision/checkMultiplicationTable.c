/* Write a C program that creates an iinteger array of size N dynamically, (N to be read from user) reads N elements into the array and checks whether the 
numbers read form the multiplication table of any given number. */
#include<stdio.h>
#include<stdlib.h>

void readArray(int *arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int isMultiple(int *arr, int n, int num)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] % num) return 0;
    }
    return 1;
}
 
int main()
{
    int n, *arr, num;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    printf("Enter %d elements: ", n); 
    readArray(arr, n);
    printf("Enter a number: ");
    scanf("%d", &num);
    if(isMultiple(arr, n, num))
    {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    return 0;
}