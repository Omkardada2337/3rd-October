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
    if (q->r+1 >= q->size)
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
    if (isFull(q))
    {
        printf("QEUE IS FULL.\n");
    }
    else
    {
        q->r++;
        q->a[q->r] = e;
    }
}

void enq_t(qu *q, int e)
{
    
    if (isFull(q))
    {
        printf("QEUE IS FULL.\n");
    }
    else
    {
        q->r++;
        for (int i = q->r-1; i>=q->t ; i--)
        {
            q->a[i+1] = q->a[i];
        }
        q->a[q->t] = e;
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

int deq_r(qu *q)
{

    if (q->t >= q->r)
    {
        printf("QEUE IS EMPTY: ");
    }
    else
    {
        int x = q->a[q->r];
        q->r--;
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
        printf("1.ENQEUE\n\n");
        printf("2.DEQEUE\n\n");
        printf("3.DISPLAY\n\n");
        printf("4.OEUE IS FULL OR EMPTY\n\n");
        printf("5.ENQEUE FROM FRONT\n\n");
        printf("6.DEQEUE FROM REAR\n\n");
        printf("7.EXIT\n\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("ENTER ELEMENT: \n\n");
            int x;
            scanf("%d", &x);
            enq(q, x);
            printf("\n");
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
            printf("ENTER ELEMENT: \n");
            int x1;
            scanf("%d", &x1);
            enq_t(q, x1);
            break;
        case 6:
            int y1 = deq_r(q);
            if (y1>=0)
            {
                printf("YOUR DEQUED ELEMENT IS %d\n", y1);
            }
            break;
        case 7:
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