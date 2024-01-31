/* Write a C recursive function to compute a+b where a and b are nonnegative integers using the following function : 
int succ(int x) 
{ 
  return (x++);  
} */

#include<stdio.h>
#include<stdlib.h>

int succ(int x)
{
    return (++x);
}

int addIntegers(int a, int b)
{
    if(b == 0) return a;
    a = succ(a);
    return addIntegers(a, b - 1);
}

int main()
{
    int a,b;
    printf("Enter the two non negative integers: ");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, addIntegers(a, b));
    return 0;
}
