//Write a C program for contruction and evaluation of expression tree for a given postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    char info;
    struct node *lLink, *rLink;
};

struct node *createNode(char ele)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> info = ele;
    newNode -> lLink = newNode -> rLink = NULL;
    return newNode;
}

struct node *constructBinaryExpTree(char postfix[])
{
    struct node *stack[100];
    int top = -1, i = 0;
    while(postfix[i] != '\0')
    {
        char ch = postfix[i];
        if(isalnum(ch))
        {
            struct node *newNode = createNode(ch);
            stack[++top] = newNode;
        }
        else
        {
            struct node *newNode = createNode(ch);
            newNode -> rLink = stack[top--];
            newNode -> lLink = stack[top--];
            stack[++top] = newNode;
        }
        i++;
    }
    return (stack[top--]);
}

float evaluateBinaryExpTree(struct node *root)
{
    if(root == NULL) return 0;
    float num;
    switch (root -> info)
    {
        case '+': return evaluateBinaryExpTree(root -> lLink) + evaluateBinaryExpTree(root -> rLink); 
        case '-': return evaluateBinaryExpTree(root -> lLink) - evaluateBinaryExpTree(root -> rLink);
        case '*': return evaluateBinaryExpTree(root -> lLink) * evaluateBinaryExpTree(root -> rLink);
        case '/': return evaluateBinaryExpTree(root -> lLink) / evaluateBinaryExpTree(root -> rLink);
        default:
            if(isalpha(root -> info))
            {
                printf("%c: ", root -> info);
                scanf("%f", &num);
                return num;
            }
            else
                return root -> info - '0';
    }
}

void inorderPrint(struct node *root)
{
    if(root == NULL) return;
    inorderPrint(root -> lLink);
    printf("%c", root -> info);
    inorderPrint(root -> rLink);
}


void preorderPrint(struct node *root)
{
    if(root == NULL) return;
    printf("%c", root -> info);
    preorderPrint(root -> lLink);
    preorderPrint(root -> rLink);
}


void postorderPrint(struct node *root)
{
    if(root == NULL) return;
    postorderPrint(root -> lLink);
    postorderPrint(root -> rLink);
    printf("%c", root -> info);
}

int main()
{
    char postfix[100];
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    struct node *root = constructBinaryExpTree(postfix);
    printf("\nInorder:\n");
    inorderPrint(root);
    printf("\nPreorder:\n");
    preorderPrint(root);
    printf("\nPostorder:\n");
    postorderPrint(root);
    printf("\n");
    printf("The result of the expression is: %.2f\n", evaluateBinaryExpTree(root));
}