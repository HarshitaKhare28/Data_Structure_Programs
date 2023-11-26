// Create a Traffic Management Application.
// Queues can be used to manage traffic flow in transportation systems, such as airport control
// systems or road networks.
// Scenario:
// You have to manage traffic at a Square which has 4 lanes: a, b, c, d.
// A vehicle can be enqueued in any of the lane by user’s choice. Consider the 4-digit vehicle number as
// an element for the queue.
// For dequeue operation the sequence to be followed is a-&gt; b-&gt; c-&gt; d-&gt; a -&gt;…… (in the circular
// manner). Maximum 5 vehicles can pass the square in the given duration.
// NOTE: if a particular lane is empty then automatically next lane vehicle should be dequeued.
// Display the Lane Number and Vehicle Number which are dequeued.
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *que;
    int f;
    int r;
    int max;
};
typedef struct Queue que;

void enqueue(que *q, int elem)
{
    if ((q->f == (q->r + 1) % q->max) && (q->f == q->r))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (q->f == -1 && q->r == -1)
        {
            q->f = 0;
            q->r = 0;
            q->que[q->r] = elem;
        }
        else
        {
            // q->r = q->r + 1;
            // q->que[q->r] = elem;
            q->r = (q->r + 1) % q->max;
            q->que[q->r] = elem;
        }
    }
}

int dequeue(que *q)
{
    if (q->f == -1)
    {
        printf("Queue is empty!");
        return -1;
    }
    else
    {
        if (q->f == q->r)
        {
            int x = q->que[q->f];
            q->f = -1;
            q->r = -1;
            return x;
        }
        else
        {
            int x = q->que[q->f];
            q->f = (q->f + 1) % q->max;
            return x;
        }
    }
}

void manageTraffic(que *a, que *b, que *c, que *d)
{
    // a-b-c-d-a-...
    int aEmpty = 0, bEmpty = 0, cEmpty = 0, dEmpty = 0;

    while (!aEmpty || !bEmpty || !cEmpty || !dEmpty)
    {
        for (int i = 0; i < 5; i++)
        {
            if (a->f == -1)
            {
                aEmpty = 1;
                break;
            }
            printf("Dequeued from A: %d\n", dequeue(a));
        }
        for (int i = 0; i < 5; i++)
        {
            if (b->f == -1)
            {
                bEmpty = 1;
                break;
            }
            printf("Dequeued from B: %d\n", dequeue(b));
        }
        for (int i = 0; i < 5; i++)
        {
            if (c->f == -1)
            {
                cEmpty = 1;
                break;
            }
            printf("Dequeued from C: %d\n", dequeue(c));
        }
        for (int i = 0; i < 5; i++)
        {
            if (d->f == -1)
            {
                dEmpty = 1;
                break;
            }
            printf("Dequeued from D: %d\n", dequeue(d));
        }
    }
}

void display(que *q)
{
    if (q->f <= q->r)
    {
        for (int i = q->f; i <= q->r; i++)
        {
            printf("%d\n", q->que[i]);
        }
    }
    else if (q->f > q->r)
    {
        for (int i = q->f; i < q->max; i++)
        {
            printf("%d\n", q->que[i]);
        }
        for (int i = 0; i < q->r; i++)
        {
            printf("%d\n", q->que[i]);
        }
    }
}

int main()
{
    que *a;
    que *b;
    que *c;
    que *d;
    a = (que *)malloc(sizeof(que));
    b = (que *)malloc(sizeof(que));
    c = (que *)malloc(sizeof(que));
    d = (que *)malloc(sizeof(que));
    a->max = 10;
    b->max = 10;
    c->max = 10;
    d->max = 10;
    a->f = -1;
    a->r = -1;
    b->f = -1;
    b->r = -1;
    c->f = -1;
    c->r = -1;
    d->f = -1;
    d->r = -1;
    a->que = (int *)malloc(a->max * sizeof(int));
    b->que = (int *)malloc(b->max * sizeof(int));
    c->que = (int *)malloc(c->max * sizeof(int));
    d->que = (int *)malloc(d->max * sizeof(int));
    int n, t;
    printf("Enter number of vehicles in a: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter number for car %d: ", i + 1);
        scanf("%d", &t);
        enqueue(a, t);
    }
    printf("Enter number of vehicles in b: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter number for car %d: ", i + 1);
        scanf("%d", &t);
        enqueue(b, t);
    }
    printf("Enter number of vehicles in c: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter number for car %d: ", i + 1);
        scanf("%d", &t);
        enqueue(c, t);
    }
    printf("Enter number of vehicles in d: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter number for car %d: ", i + 1);
        scanf("%d", &t);
        enqueue(d, t);
    }

    manageTraffic(a, b, c, d);
    return 0;
}