//Write C function to print maximum and minimum elements of a given BST.
#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *left, *right;
};
typedef struct node *NODE;

int minimumEleBst(NODE root)
{
    NODE cur = root;
    while(cur -> left != NULL)
        cur = cur -> left;
    return cur -> info;
}

int maximumEleBst(NODE root)
{
    NODE cur = root;
    while(cur -> right != NULL)
        cur = cur -> right;
    return cur -> info;
}

NODE createNode()
{
    NODE root = (NODE)malloc(sizeof(struct node));
    return root;
}

NODE insertBst(NODE root, int ele)
{
    NODE cur, prev;
    NODE temp = createNode();
    temp -> info = ele;
    temp -> left = temp -> right = NULL;
    if(root == NULL)
        return temp;
    cur = root, prev = NULL;
    while(cur != NULL)
    {
        prev = cur;
        if(ele < cur -> info)
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    if(ele < prev -> info)
        prev -> left = temp;
    else
        prev -> right = temp;
    return root;
}

void inorderBst(NODE root)
{
    if(root == NULL)
        return;
    inorderBst(root -> left);
    printf("%d ", root -> info);
    inorderBst(root -> right);
}

int main()
{
    NODE root = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Inorder print\t3.Minimum element\t4.Maximum element\t5.Exit\n");
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
                inorderBst(root);
                printf("\n");
                break;
            case 3:
                printf("The minimum element in bst is: %d\n", minimumEleBst(root));
                break;
            case 4:
                printf("The maximum element in bst is %d\n", maximumEleBst(root));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
