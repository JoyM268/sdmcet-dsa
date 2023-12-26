/* Write a C program to construct BST for a given set of elements and perform the following operations on it: 
i. Search a given element 
ii. Insert the given element if not present  
iii. Delete an element */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE createNode(int data)
{
    NODE root = (NODE)malloc(sizeof(struct node));
    root -> data = data;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

int searchBST(NODE root, int item)
{
    NODE cur = root;
    while(cur != NULL)
    {
        if(cur -> data == item)
            break;
        else if(item < cur -> data)
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    if(cur == NULL) return 0;
    return 1;
}

NODE insertBST(NODE root, int item)
{
    if(searchBST(root, item))
    {
        printf("Element %d already present in the tree\n", item);
        return root;
    }
    NODE prev = NULL, cur = root, temp;
    temp = createNode(item);
    if(root == NULL) return temp;
    while(cur != NULL)
    {
        prev = cur;
        if(item  < cur -> data)
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    if(item < prev -> data)
        prev -> left = temp;
    else
        prev -> right = temp;
    return root;
}

NODE successor(NODE root)
{
    while(root -> left != NULL)
        root = root -> left;
    return root;
}

NODE deleteBST(NODE root, int item)
{
    NODE cur = root, prev;
    while(cur != NULL && cur -> data != item)
    {
        prev = cur;
        if(item < cur -> data)
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    if(cur == NULL)
    {
        printf("%d does not exist in tree\n", item);
        return root;
    }
    if(cur -> left == NULL && cur -> right == NULL)
    {
        if(cur == root)
        {
            root = NULL;
        }
        else
        {
            if(prev -> left == cur)
                prev -> left = NULL;
            else
                prev -> right = NULL;
        }
    }
    else if(cur -> left != NULL && cur -> right != NULL)
    {
        NODE temp = successor(cur -> right);
        cur -> data = temp -> data;
        cur -> right = deleteBST(cur -> right, temp -> data);
        return root;
    }
    else
    {
        NODE child;
        if(cur -> left == NULL) child = cur -> right;
        else child = cur -> left;
        if(cur != root)
        {
            if(cur == prev -> left)
                prev -> left = child;
            else
                prev -> right = child;
        }
        else
        {
            root = child;
        }
    }
    free(cur);
    return root;
}

void inorderPrint(NODE root)
{
    if(root == NULL) return;
    inorderPrint(root -> left);
    printf("%d ", root -> data);
    inorderPrint(root -> right);
}

int main()
{
    NODE root = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Search\t3.Delete\t4.Display\t5.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            root = insertBST(root, item);
            break;
        case 2:
            printf("Enter the element to be searched: ");
            scanf("%d", &item);
            if (searchBST(root, item))
                printf("%d found\n", item);
            else
                printf("%d not found\n", item);
            break;
        case 3:
            printf("Enter the element to be deleted: ");
            scanf("%d", &item);
            root = deleteBST(root, item);
            break;
        case 4:
            inorderPrint(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}