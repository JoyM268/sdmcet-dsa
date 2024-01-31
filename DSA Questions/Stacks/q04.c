/*For the following definition of f(n) write C recursive function and compute how many additions are done to evaluate f(6). 
f(n)=n if n=0 or n=1 
f(n)=f(n-2)+f(n-1) if n>=2 */

//Answer: 12 additions are done to evaluate f(6)
#include<stdio.h>
#include<stdlib.h>

int addCount;
int f(int n)
{
    if(n == 0 || n == 1) return n;
    if(n >= 2)
    {
        addCount++;
        return f(n - 2) + f(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("f(%d) = %d\n", n, f(n));
    printf("The count of additions is: %d\n", addCount);
    return 0;
}

