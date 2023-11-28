/* Write a C program to store a given sparse matrix using linked lists and search for a given element in the matrix. If it is present display row and 
column index of the element otherwise print appropriate error message. */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int row, col, data;
    struct node *rowLink, *colLink;
}node;

node *createNode(int data, int row, int col)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> row = row;
    temp -> col = col;
    temp -> rowLink = NULL;
    temp -> colLink = NULL;
    return temp;
}

node *headerNodes(int row, int col)
{
    int i;
    node *header = createNode(-1, row, col), *tailRow, *tailCol;
    tailRow = tailCol = header;
    header -> rowLink = header;
    header -> colLink = header;
    for(i = 1; i <= col; i++)
    {
        node *temp = createNode(-1, 0, i);
        temp -> colLink = temp;
        temp -> rowLink = tailRow -> rowLink;
        tailRow -> rowLink = temp;
        tailRow = temp;
    }
    for(i = 1; i <= row; i++)
    {
        node *temp = createNode(-1, i, 0);
        temp -> rowLink = temp;
        temp -> colLink = tailCol -> colLink;
        tailCol -> colLink = temp;
        tailCol = temp;
    }
    return header;
}

void insertNode(node *header, int data, int row, int col)
{
    node *temp = createNode(data, row, col);
    node *curCol = header, *curRow = header;
    while(curCol -> rowLink != header)
    {
        if(curCol -> row == 0 && curCol -> col == col)
        {
            break;
        }
        curCol = curCol -> rowLink;
    }
    node *ptr1 = curCol;
    while(ptr1 -> colLink != curCol && ptr1 -> colLink -> row < row)
    {
        ptr1 = ptr1 -> colLink;
    }
    temp -> colLink = ptr1 -> colLink;
    ptr1 -> colLink = temp;
    while(curRow -> colLink != header)
    {
        if(curRow -> col == 0 && curRow -> row == row)
        {
            break;
        }
        curRow = curRow -> colLink;
    }
    node *ptr2 = curRow;
    while(ptr2 -> rowLink != curRow && ptr2 -> rowLink -> col < col)
    {
        ptr2 = ptr2 -> rowLink;
    }
    temp -> rowLink = ptr2 -> rowLink;
    ptr2 -> rowLink = temp;
}

void display(node *header, int row, int col)
{
    int i, j;
    node *rowptr = header -> colLink, *colptr;
    for(i = 1; i <= row; i++)
    {
        colptr = rowptr -> rowLink;
        for(j = 1; j <= col; j++)
        {
            if(colptr != rowptr && colptr -> col == j)
            {
                printf("%d ", colptr -> data);
                colptr = colptr -> rowLink;
            }
            else
            {
                printf("0 ");
            }
        }
        rowptr = rowptr -> colLink;
        printf("\n");
    }    
}

void searchElement(node *header, int key)
{
    node *rowPtr = header -> colLink, *colPtr; 
    while(rowPtr != header)
    {
        colPtr = rowPtr -> rowLink;
        while(colPtr != rowPtr)
        {
            if(colPtr -> data == key)
            {
                printf("Element %d found at row %d and column %d\n", colPtr -> data, colPtr -> row, colPtr -> col);
                return;
            }
            colPtr = colPtr -> rowLink;
        }
        rowPtr = rowPtr -> colLink;
    }
    printf("Element %d not found\n", key);
}

int main()
{
    node *header;
    int m, n, nonZero, i, row, col, data, key;
    printf("Enter the order of matrix: ");
    scanf("%d %d", &m, &n);
    header = headerNodes(m, n);
    printf("\nEnter the number of non-zero elements: ");
    scanf("%d", &nonZero);
    printf("\n");
    for(i = 0; i < nonZero; i++)
    {
        printf("Enter the non - zero element and its row and column: ");
        scanf("%d %d %d", &data, &row, &col);
        if(row <= 0 || col <= 0 || row > m || col > n) 
        {
            printf("Invalid row and column. Try again\n");
            i--;
            continue;
        }
        insertNode(header, data, row, col);
    }
    printf("\nThe sparse matrix is:\n");
    display(header, m, n);
    printf("\n");
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    searchElement(header, key);
    return 0;
}