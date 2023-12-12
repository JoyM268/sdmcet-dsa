// Write a c program to evaluate given polynomial for given values of x and y
#include<stdio.h>
#include<stdlib.h>

struct node{
    float coeff;
    int exp;
    struct node *link;
};
typedef struct node *NODE;

NODE createNode(float coefficient, int exponent)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> coeff = coefficient;
    temp -> exp = exponent;
    temp -> link = NULL; 
    return temp;
}

NODE insertTerm(NODE head, float coefficient, int exponent)
{
    NODE temp = createNode(coefficient, exponent);
    if(head == NULL || head -> exp < exponent)
    {   temp -> link = head;
        return temp;
    }
    NODE cur = head;
    while(cur -> link != NULL && cur -> link -> exp > exponent)
    {
        cur = cur -> link;
    }
    temp -> link = cur -> link;
    cur -> link = temp;
    return head;
}

NODE createPolynomial(NODE head)
{
    int n, i, exponent;
    float coefficient;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the coefficient and exponent of the term %d: ", i + 1);
        scanf("%f %d", &coefficient, &exponent);
        head = insertTerm(head, coefficient, exponent);
    }
    return head;
}

void displayPolynomial(NODE head)
{
    if(head == NULL) 
    {
        printf("Zero polynomial\n");
        return;
    }
    struct node *temp = head;
    while(temp -> link != NULL)
    {
        printf("(%.1fx^%d)+", temp -> coeff, temp -> exp);
        temp = temp -> link;
    }
    printf("(%.1fx^%d)\n", temp -> coeff, temp -> exp);
}

void addPolynomial(NODE head1, NODE head2)
{
    NODE head3 = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if(head1 -> exp > head2 -> exp)
        {
            head3 = insertTerm(head3, head1 -> coeff, head1 -> exp);
            head1 = head1 -> link;
        }
        else if(head1 -> exp < head2 -> exp)
        {
            head3 = insertTerm(head3, head2 -> coeff, head2 -> exp);
            head2 = head2 -> link;
        }
        else
        {
            head3 = insertTerm(head3, head1 -> coeff + head2 -> coeff, head1 -> exp);
            head1 = head1 -> link;
            head2 = head2 -> link;
        }
    }
    while(head1 != NULL)
    {
        head3 = insertTerm(head3, head1 -> coeff, head1 -> exp);
        head1 = head1 -> link;
    }
    while(head2 != NULL)
    {
        head3 = insertTerm(head3, head2 -> coeff, head2 -> exp);
        head2 = head2 -> link;
    }
    printf("\nAdded polynomial is:\n");
    displayPolynomial(head3);
}

void multiplyPolynomial(NODE head1, NODE head2)
{
    NODE head3 = NULL, ptr1 = head1, ptr2 = head2;
    if(head1 == NULL || head2 == NULL) 
    {
        printf("\nZero polynomial\n");
        return;
    }
    while(ptr1 != NULL)
    {
        while(ptr2 != NULL)
        {
            head3 = insertTerm(head3, ptr1 -> coeff * ptr2 -> coeff, ptr1 -> exp + ptr2 -> exp);
            ptr2 = ptr2 -> link;
        }
        ptr1 = ptr1 -> link;
        ptr2 = head2;
    }
    printf("\nMultiplied polynomial is:\n");
    displayPolynomial(head3);
}

int main()
{
    NODE head1 = NULL, head2 = NULL;
    printf("Enter 1st polynomial:\n");
    head1 = createPolynomial(head1);
    printf("\nEnter 2nd Polynomail:\n");
    head2 = createPolynomial(head2);
    addPolynomial(head1, head2);
    multiplyPolynomial(head1, head2);
    return 0;
}