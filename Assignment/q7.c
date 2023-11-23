/* Let A and B are two lists representing the two polynomials with single variable. Write a C program to implement the following operation. 
C=A+B; where C is also a list representing a polynomial and is obtained by adding A and B. */
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

NODE addPolynomial(NODE A, NODE B)
{
    NODE C = NULL;
    if(A == NULL) return B;
    if(B == NULL) return A;
    while(A != NULL && B != NULL)
    {
        if(A -> exp > B -> exp)
        {
            C = insertTerm(C, A -> coeff, A -> exp);
            A = A -> link;
        }
        else if(A -> exp < B -> exp)
        {
            C = insertTerm(C, B -> coeff, B -> exp);
            B = B -> link;
        }
        else
        {
            C = insertTerm(C, A -> coeff + B -> coeff, A -> exp);
            A = A -> link;
            B = B -> link;
        }
    }
    while(A != NULL)
    {
        C = insertTerm(C, A -> coeff, A -> exp);
        A = A -> link;
    }
    while(B != NULL)
    {
        C = insertTerm(C, B -> coeff, B -> exp);
        B = B -> link;
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
        printf("\n1.Create polynomial A\t2.Create polynomial B\t3.Display A\t4.Display B\t5.Add Polynomials\t6.Exit\n");
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
                C = addPolynomial(A, B);
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

//Method 2
/*
NODE addPolynomial(NODE A, NODE B)
{
    if(A == NULL) return B;
    if(B == NULL) return A;
    NODE C;
    if(A -> exp == B -> exp)
    {
        C = createNode(A -> coeff + B -> coeff, A -> exp);
        C -> link = addPolynomial(A -> link, B -> link);
    }
    else if(A -> exp > B -> exp)
    {
        C = createNode(A -> coeff, A -> exp);
        C -> link = addPolynomial(A -> link, B);
    }
    else
    {
        C = createNode(B -> coeff, B -> exp);
        C -> link = addPolynomial(A, B -> link);    
    }
    return C;
}
*/