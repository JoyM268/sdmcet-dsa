//Write a C program to remove duplicates from a given list of ‘n’ elements using BST.
#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE createNode(int data)
{
    NODE root = (NODE)malloc(sizeof(struct node));
    root -> info = data;
    root -> left = root -> right = NULL;
    return root;
}

NODE insertBst(NODE root, int ele)
{
    if(root == NULL) return createNode(ele);
    if(ele < root -> info)
        root -> left = insertBst(root -> left, ele);
    else if(ele > root -> info)
        root -> right = insertBst(root -> right, ele);
    else
        printf("%d already exists in BST\n", root -> info);
    return root;
}

void inorder(NODE root)
{
    if(root == NULL) return;
    inorder(root -> left);
    printf("%d ", root -> info);
    inorder(root -> right);
}

int main()
{
    NODE root = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Print Inorder\t3.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insertBst(root, item);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
