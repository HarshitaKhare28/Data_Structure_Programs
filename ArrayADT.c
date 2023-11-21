//array adt
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *arr;
    int size;
};
// display function
void display(struct Array *a)
{
    for (int i = 0; i < a->size; i++)
    {
        printf("%d\n", a->arr[i]);
    }
}
// insert function
void insert(struct Array *a, int elem)
{
    int pos;
    printf("enter position to insert: \n");
    scanf("%d", &pos);
    for (int i = a->size - 1; i >= pos - 1; i--)
    {
        a->arr[i + 1] = a->arr[i];
    }
    a->arr[pos - 1] = elem;
    a->size = a->size + 1;
    printf("after insertion: \n");
    display(a);
}
// delete function
void delete(struct Array *a)
{
    int pos;
    printf("enter position to delete: \n");
    scanf("%d", &pos);
    for (int i = pos - 1; i < a->size; i++)
    {
        a->arr[i] = a->arr[i + 1];
    }
    a->size = a->size - 1;
    printf("After deletion: \n");
    display(a);
}
// modify
void modify(struct Array *a, int elem)
{
    int old_elem, i;
    printf("enter the element to be modified: \n");
    scanf("%d", &old_elem);
    for (i = 0; i < a->size; i++)
    {
        if (a->arr[i] == old_elem)
        {
            a->arr[i] = elem;
            printf("After modification: \n");
            display(a);
            break;
        }
    }
    // isme doubt hai ki agar user ne jo element dala vo array me nahi huya to ek print statement show karni hai vo kaha pe karu??loop ke andar vo bar bar print hori hai aur bahar by default har bar aarahi hai..
}
// sort
void sort(struct Array *a)
{
    for (int i = 0; i < a->size - 1; i++)
    {
        for (int j = i; j < a->size; j++)
        {
            if (a->arr[j] < a->arr[i])
            {
                int temp = a->arr[i];
                a->arr[i] = a->arr[j];
                a->arr[j] = temp;
            }
        }
    }
    printf("sorted array: \n");
    display(a);
}
// search
void search(struct Array *a)
{
    int elem;
    printf("enter element to search: \n");
    scanf("%d", &elem);
    for (int i = 0; i < a->size; i++)
    {
        if (a->arr[i] == elem)
        {
            printf("element found at index: %d and position: %d\n", i, i + 1);
            break;
        }
    }
}
int main()
{
    struct Array a;
    printf("enter the number of elements: \n");
    scanf("%d", &a.size);
    a.arr = (int *)malloc(a.size * sizeof(int));
    printf("enter the elements: \n");
    for (int i = 0; i < a.size; i++)
    {
        scanf("%d", &a.arr[i]);
    }
    printf("the array is: \n");
    display(&a);

    insert(&a, 100);

    delete (&a);

    modify(&a, 3000);

    sort(&a);

    search(&a);

    return 0;
}