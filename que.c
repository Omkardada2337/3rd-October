#include <stdio.h>
#include <stdlib.h>
typedef struct que
{
    int t;
    int r;
    int *a;
    int size;

} qu;

int isFull(qu *q)
{
    if (q->r >= q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(qu *q)
{
    if (q->t >= q->r)
    {
        return 1;
    }
    return 0;
}
void enq(qu *q, int e)
{
    q->r++;
    if (isFull(q))
    {
        printf("QEUE IS FULL.\n");
    }
    else
    {
        q->a[q->r] = e;
    }
}

int deq(qu *q)
{

    if (q->t >= q->r)
    {
        printf("QEUE IS EMPTY: ");
    }
    else
    {
        int x = q->a[q->t];
        q->t++;
        return x;
    }
    return -1;
}

void display(qu *q)
{
    for (int i = q->t; i <= q->r; i++)
    {
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

int main()
{
    qu *q = malloc(sizeof(qu));
    q->t = 0;
    q->r = -1;
    printf("ENTER SIZE OF QEUE: \n");
    scanf("%d", &q->size);
    q->a = malloc(q->size * sizeof(int));
    int flag = 0;
    while (1)
    {
        int n;
        printf("1.ENQEUE\n");
        printf("2.DEQEUE\n");
        printf("3.DISPLAY\n");
        printf("4.OEUE IS FULL OR EMPTY\n");
        printf("5.EXIT\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("ENTER ELEMENT: \n");
            int x;
            scanf("%d", &x);
            enq(q, x);
            break;
        case 2:
            int y = deq(q);
            if (y>=0)
            {
                printf("YOUR DEQUED ELEMENT IS %d\n", y);
            }
            break;
        case 3:
            display(q);
            break;
        case 4:
            if (isEmpty(q))
            {
                printf("QUE IS EMPTY.\n");
            }
            if (isFull(q))
            {
                printf("QUE IS FULL\n");
            }
            break;
        case 5:
            flag = 1;
            break;

        default:
            break;
        }
        if (flag == 1)
        {
            break;
        }
    }

    return 0;
}