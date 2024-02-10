/* The Greatest Common Divisor of two integers x and y is defined as follows, 
gcd(x,y) = y                    if (y < = x && x % y = 0) 
gcd(x,y) = gcd(y,x)             if (x < y) 
gcd(x,y) = gcd (y, x % y)       otherwise 
Write a recursive C function to compute gcd (x, y). Also find for how many times the recursive function is called for the values of gcd (20,75). */

//Answer: the recursive function is called 4 times for the values gcd(20, 75)
#include<stdio.h>
#include<stdlib.h>

int gcd(int x, int y)
{
    if(y <= x && x % y == 0) 
        return y;
    if(x < y)
        return gcd(y, x);
    else
        return gcd(y, x % y);
}

int main()
{
    int x, y;
    printf("Enter the two integers: ");
    scanf("%d %d", &x, &y);
    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    return 0;
}