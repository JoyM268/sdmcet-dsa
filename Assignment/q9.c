/* Write a C program to store a given sparse matrix using linked lists and search for a given element in the matrix.
If it is present display row and column index of the element otherwise print appropriate error message. */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info, row, col;
    struct node *link;
};

typedef struct node *NODE;

NODE createNode(int element, int row, int column)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> info = element;
    temp -> row = row;
    temp -> col = column;
    temp -> link = NULL;
    return temp;
}

NODE insertNode(NODE first, int element, int row, int column)
{
    NODE temp = createNode(element, row, column);
    if(first == NULL)
    {
        return temp;
    }
    NODE cur = first, prev = NULL;
    while(cur != NULL && ((temp -> row > cur -> row) || (temp -> col > cur -> col && temp -> row == cur -> row)))
    {
        prev = cur;
        cur = cur -> link;
    }
    if(cur != NULL && temp -> row == cur -> row && temp -> col == cur -> col) return first;
    if(first == cur)
    {
        temp -> link = first;
        first = temp;
    }
    else
    {
        prev -> link = temp;
        temp -> link = cur;
    }
    return first;
}

void searchElement(NODE first, int ele)
{
    while(first != NULL && first -> info != ele)
    {
        first = first -> link;
    }
    if(first != NULL)
    {
        printf("Element %d found at row %d and column %d\n", first -> info, first -> row, first -> col);
        return;
    }
    printf("Element %d not found\n", ele);
}

void displayMatrix(NODE first, int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(first != NULL && first -> row == i && first -> col == j)
            {
                printf("%d ", first -> info);
                first = first -> link;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    NODE first = NULL;
    int m, n, choice, ele, row, column;
    printf("Enter the order of matrix: ");
    scanf("%d %d", &m, &n);
    for(;;)
    {
        printf("\n1.Insert Element\t2.Search Element\t3.Display Matrix\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element, row and column: ");
                scanf("%d %d %d", &ele, &row, &column);
                if(row >= m || column >= n) break;
                first = insertNode(first, ele, row, column);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &ele);
                searchElement(first, ele);
                break;
            case 3:
                displayMatrix(first, m, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}