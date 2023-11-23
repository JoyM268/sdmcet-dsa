/* Let A and B are two lists representing the two polynomials with single variable. Write a C program to implement the following operation. 
C=A*B. where C is also a list representing a polynomial and is obtained by multiplying A and B. */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff, exp;
    struct node *link;
};
typedef struct node *NODE;

NODE createNode(int coefficient, int exponent)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> coeff = coefficient;
    temp -> exp = exponent;
    temp -> link = NULL; 
    return temp;
}

NODE insertTerm(NODE first, int coefficient, int exponent)
{
    NODE temp = createNode(coefficient, exponent);
    if(first == NULL || first -> exp < exponent)
    {   temp -> link = first;
        return temp;
    }
    NODE cur = first;
    while(cur -> link != NULL && cur -> link -> exp > exponent)
    {
        cur = cur -> link;
    }
    temp -> link = cur -> link;
    cur -> link = temp;
    return first;
}

NODE createPolynomial(NODE first)
{
    int n, i, exponent, coefficient;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter the coefficient and exponent of the term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        first = insertTerm(first, coefficient, exponent);
    }
    return first;
}

NODE multiplyPolynomial(NODE A, NODE B)
{
    if(A == NULL || B == NULL) return NULL;
    NODE C = NULL;
    while(A != NULL)
    {
        NODE temp = B;
        while(temp != NULL)
        {
            C = insertTerm(C, A -> coeff * temp -> coeff, A -> exp + temp -> exp);
            temp = temp -> link;
        }
        A = A -> link;
    }
    return C;
}

void displayPolynomial(NODE first)
{
    if(first == NULL) 
    {
        printf("0\n");
        return;
    }
    while(first -> link != NULL)
    {
        printf("%dx^%d + ", first -> coeff, first -> exp);
        first = first -> link;
    }
    printf("%dx^%d\n", first -> coeff, first -> exp);
}

int main()
{
    NODE A = NULL, B = NULL, C = NULL;
    int choice, coefficient, exponent;
    for(;;)
    {
        printf("\n1.Create polynomial A\t2.Create polynomial B\t3.Display A\t4.Display B\t5.Multipy Polynomials\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                A = createPolynomial(A);
                break;
            case 2:
                B = createPolynomial(B);
                break;
            case 3:
                printf("A = ");
                displayPolynomial(A);
                break;
            case 4:
                printf("B = ");
                displayPolynomial(B);
                break;
            case 5:
                C = multiplyPolynomial(A, B);
                printf("C = ");
                displayPolynomial(C);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}