/* Let A and B are two lists representing the two polynomials with single variable. Write a C program to implement the following operation. 
C=A+B; where C is also a list representing a polynomial and is obtained by adding A and B. */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff, exp;
    struct node *link;
};
typedef struct node *NODE;

NODE createTerm(int coeff, int exp)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> link = NULL;
    temp -> coeff = coeff;
    temp -> exp = exp;
    return temp;
}

NODE insertTerm(NODE first, int coeff, int exp)
{
    NODE temp = createTerm(coeff, exp); 
    if(first == NULL)
    {
        return temp;
    }
    NODE cur = first;
    while(cur -> link != NULL)
    {
        cur = cur -> link;
    }
    cur -> link = temp;
    return first;
}

NODE addPolynomial(NODE A, NODE B)
{
    if(A == NULL) return B;
    if(B == NULL) return A;
    NODE dummy = createTerm(0, 0), prev = dummy;
    while(A != NULL && B != NULL)
    {
        if(A -> exp > B -> exp)
        {
            prev -> link = A;
            prev = A;
            A = A -> link;
        }
        else if(A -> exp < B -> exp)
        {
            prev -> link = B;
            prev = B;
            B = B -> link;
        }
        else
        {
            A -> coeff += B -> coeff;
            prev -> link = A;
            prev = A;
            A = A -> link;
            B = B -> link;
        }
    }
    if(A != NULL)
    {
        prev -> link = A;
    }
    if(B != NULL)
    {
        prev -> link = B;
    }
    return dummy -> link;
}

void displayPolynomial(NODE first)
{
    if(first == NULL) return;
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
        printf("\n1.Insert term in A\t2.Insert term in B\t3.Display A\t4.Display B\t5.Add Polynomials\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the coefficient and exponent of the term: ");
                scanf("%d %d", &coefficient, &exponent);
                A = insertTerm(A, coefficient, exponent);
                break;
            case 2:
                printf("Enter the coefficient and exponent of the term: ");
                scanf("%d %d", &coefficient, &exponent);
                B = insertTerm(B, coefficient, exponent);
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