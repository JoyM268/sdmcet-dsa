/* Two binary trees are similar if they are both empty or if they are both nonempty, their left subtrees are similar, and right subtrees are similar.
Write an algorithm to determine if two binary tress are similar or not. */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE createTree()
{
    int data;
    printf("Enter the element(-1 if no node): ");
    scanf("%d", &data);
    if(data == -1) return NULL;
    NODE root = (NODE)malloc(sizeof(struct node));
    root -> data = data;
    printf("Enter left child of %d:\n", data);
    root -> left = createTree();
    printf("Enter right child of %d:\n", data);
    root -> right = createTree();
    return root;
}

int isSimilar(NODE root1, NODE root2)
{
    if(root1 == NULL && root2 == NULL) return 1;
    if(root1 == NULL || root2 == NULL) return 0;
    int leftSubtree = isSimilar(root1 -> left, root2 -> left);
    int rightSubtree = isSimilar(root1 -> right, root2 -> right);
    return (root1 -> data == root2 -> data && leftSubtree && rightSubtree);
}

int main()
{
    NODE root1, root2;
    printf("Enter the elements of Tree 1:\n");
    root1 = createTree();
    printf("\nEnter the elements of Tree 2:\n");
    root2 = createTree();
    if(isSimilar(root1, root2))
        printf("The trees are similar\n");
    else
        printf("The trees are not similar\n");
    return 0;
}