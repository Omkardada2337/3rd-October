#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack *createStack(unsigned cap)
{
    struct ArrayStack *stack;
    stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = (int *)malloc((sizeof(int) * cap));
    return stack;
}
int isFull(struct ArrayStack *stack)
{
    if (stack->top == stack->capacity - 1)
        return 1;
    else
        return 0;
}
int isEmpty(struct ArrayStack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}
void push(struct ArrayStack *stack, int item)
{
    if (!isFull(stack))
    {
        stack->top++;
        stack->array[stack->top] = item;
    }
    else
        printf("OVERFLOW\n");
}
int pop(struct ArrayStack *stack)
{
    int item;
    if (!isEmpty(stack))
    {
        item = stack->array[stack->top];
        stack->top--;
        return item;
    }
    return -1;
}
void display(struct ArrayStack *stack)
{
    for (int i = stack->top; i > -1; i--)
    {
        printf("  %d\n", stack->array[i]);
    }
}
int main()
{
    int choice, item;
    struct ArrayStack *stack;
    stack = createStack(4);
    system("cls");
    while (1)
    {
        printf("---------------------------------\n\nEnter your choice :\n1 .Push\n2 .Pop\n3 .Display\n4 .Exit\n");
        printf("\n--->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter a number : ");
            scanf("%d", &item);
            push(stack, item);
            break;
        case 2:
            item = pop(stack);
            if (item == -1)
                printf("Stack is empty\n");
            else
            {
                printf("%d is popped\n", item);
                break;
            }
        case 3:
            printf("\nElements in stack are : \n");
            display(stack);
            break;
        case 4:
            exit(0);
        }
    }
}