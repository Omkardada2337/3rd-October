#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *ptr = NULL;

void insertf(int val)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = ptr;
    ptr = newnode;
}
int deletefirst()
{
    int x;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = ptr;
    ptr = ptr->next;
    temp->next = NULL;
    x = temp->data;
    free(temp);
    return x;
}
void display(struct node *head)
{
    if (ptr == NULL)
        printf("LIST IS EMPTY");
    else
    {
        while (head)
        {
            printf("%d ", head->data);
            head = head->next;
        }
    }
}
int main()
{
    int choice = 1, val;
    system("cls");
    while (choice != 4)
    {
        printf("\n-----------------------------\n\n");
        printf("Enter your choice : \n");
        printf("\n  1. Insert to first\n  2. Delete first\n  3. Display\n  4. Exit\n");
        printf("\n  ---> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value : ");
            scanf("%d", &val);
            insertf(val);
            break;
        case 2:
            val = deletefirst();
            printf("\n%d is deleted successfully", val);
            break;
        case 3:
            printf("\n");
            display(ptr);
            break;
        case 4:
            exit(0);
        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
    free(ptr);
    getch();
    return 0;
}