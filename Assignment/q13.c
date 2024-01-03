//Write a C program to construct BST and check whether it is height balanced tree (AVL) or not. If not convert it into AVL tree.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE createNode(int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

NODE insertInBST(NODE root, int item)
{
    NODE temp = createNode(item);
    if(root == NULL) return temp;
    NODE cur = root, prev = NULL;
    while(cur != NULL)
    {
        prev = cur;
        if(item < cur -> data)
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

void inorderPrint(NODE root)
{
    if(root == NULL) return;
    inorderPrint(root -> left);
    printf("%d ", root -> data);
    inorderPrint(root -> right);
}

void preorderPrint(NODE root)
{
    if(root == NULL) return;
    printf("%d ", root -> data);
    preorderPrint(root -> left);
    preorderPrint(root -> right);
}

void postorderPrint(NODE root)
{
    if(root == NULL) return;
    postorderPrint(root -> left);
    postorderPrint(root -> right);
    printf("%d ", root -> data);
}

int max(int num1, int num2)
{
    return (num1 > num2)? num1 : num2;
}

int heightOfTree(NODE root)
{
    if(root == NULL) return -1;
    return 1 + max(heightOfTree(root -> left), heightOfTree(root -> right));   
}

int isAvl(NODE root)
{
    if(root == NULL) return 1;
    int lh = heightOfTree(root -> left);
    int rh = heightOfTree(root -> right);
    if(abs(lh - rh) <= 1 && isAvl(root -> left) && isAvl(root -> right)) return 1;
    return 0;
}

void bstNodes(NODE root, int *arr, int *i)
{
    if(root == NULL) return;
    bstNodes(root -> left, arr, i);
    arr[(*i)++] = root -> data;
    bstNodes(root -> right, arr, i); 
}

NODE buildAvl(int *arr, int begin, int end)
{
    if(begin > end) return NULL;
    int mid = (begin + end)/2;
    NODE root = createNode(arr[mid]);
    root -> left = buildAvl(arr, begin, mid - 1);
    root -> right = buildAvl(arr, mid + 1, end);
    return root;
}

NODE convertToAvl(NODE root)
{
    int *arr = (int *)malloc(1000*sizeof(int));
    int n = 0;
    bstNodes(root, arr, &n);
    return buildAvl(arr, 0, n - 1);
}

int main()
{
    NODE root = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Print tree\t3.Check Avl\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insertInBST(root, item);
                break;
            case 2:
                printf("Inorder: ");
                inorderPrint(root);
                printf("\n");
                printf("preorder: ");
                preorderPrint(root);
                printf("\n");
                printf("Posorder: ");
                postorderPrint(root);
                printf("\n");
                break;
            case 3:
                if(isAvl(root))
                {
                    printf("The tree is AVL tree\n");
                }
                else
                {
                    printf("The tree is not a AVL tree\n");
                    root = convertToAvl(root);
                    printf("The tree was converted to AVL\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}