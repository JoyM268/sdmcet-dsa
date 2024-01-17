/* Write a C program to construct a binary search tree and perform the following operations. 
i. Search an element 
ii. Inorder traversal
iii. postorder traversal 
iv. preorder traversal */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE create(int ele)
{
    NODE root = (NODE)malloc(sizeof(struct node));
    root -> data = ele;
    root -> left = root -> right = NULL;   
    return root;
}

NODE insertBst(NODE root, int ele)
{
    NODE cur = root, prev = NULL, temp;
    temp = create(ele);
    if(root == NULL)
        return temp;
    while(cur != NULL)
    {
        prev = cur;
        if(ele < cur -> data)
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    if(ele < prev -> data)
        prev -> left = temp;
    else
        prev -> right = temp;
    return root;
}

void searchElement(NODE root, int key)
{
    NODE temp = root;
    while(temp != NULL && temp -> data != key)
    {
        if(key < temp -> data)
            temp = temp -> left;
        else    
            temp = temp -> right;
    }   
    if(temp == NULL)
        printf("Element %d not found\n", key);
    else
        printf("Element %d found\n", temp -> data);
}

void inorder(NODE root)
{
    if(root == NULL) return;
    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);
}

void postorder(NODE root)
{
    if(root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> data);
}

void preorder(NODE root)
{
    if(root == NULL) return;
    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

int main()
{
    NODE root = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert in bst\t2.Inorder\t3.Postorder\t4.Preorder\t5.Search an element\t6.Exit\n");
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
                printf("\n");
                break;
            case 3:
                postorder(root);
                printf("\n");
                break;
            case 4:
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the element to be searched: ");
                scanf("%d", &item);
                searchElement(root, item);
                break;
            case 6: 
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}