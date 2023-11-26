// Create a Single Linked List which can Store Employee data as Employee Name,
// Employee ID and Salary. Perform the following operations on Single Linked List.
// 1) Calculate Average Salary
// 2) Create a new Linked List which stores the data in sorted order. The Linked List
// should be sorted on Employee ID in Descending Order.
// 3) Update the Employee Name, take the old name from the user and update it with new name.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char name[20];
    int id;
    double sal;
    struct Employee *next;
};
typedef struct Employee emp;
emp *first = NULL;

void create_data(emp *temp)
{
    int n;
    emp *ptr;
    printf("enter the number of employees: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        emp *temp = (emp *)malloc(sizeof(emp));
        printf("enter name: ");
        scanf("%s", &temp->name);
        printf("enter employee id: ");
        scanf("%d", &temp->id);
        printf("enter employee salary: ");
        scanf("%lf", &temp->sal);
        temp->next = NULL;
        if (first == NULL)
        {
            first = temp;
        }
        else
        {
            ptr = first;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}

void avg_sal(emp *temp)
{
    double sum = 0, count = 0;
    if (first == NULL)
    {
        printf("list is empty!\n");
    }
    else
    {
        temp = first;
        while (temp != NULL)
        {
            sum = sum + temp->sal;
            count++;
            temp = temp->next;
        }
        double avg = (sum / count);
        printf("\nAverage salary is: %lf\n", avg);
    }
}

void sort(emp *temp)
{
    temp = first;
    emp *ptr = NULL;
    emp *current = NULL;

    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL)
    {
        current = temp->next;
        while (current != NULL)
        {
            if (current->id > temp->id)
            {
                // Swap the IDs
                int tempID = temp->id;
                temp->id = current->id;
                current->id = tempID;

                // Swap the names
                char tempName[20];
                strcpy(tempName, temp->name);
                strcpy(temp->name, current->name);
                strcpy(current->name, tempName);

                // Swap the salaries
                double tempSal = temp->sal;
                temp->sal = current->sal;
                current->sal = tempSal;
            }
            current = current->next;
        }
        temp = temp->next;
    }
}

void update_name(emp *temp)
{
    if (first == NULL)
    {
        printf("list is empty!\n");
    }
    else
    {
        char old_name[20], name[20];
        printf("enter old name: \n");
        scanf("%s", old_name);
        printf("enter updated name: \n");
        scanf("%s", name);
        temp = first;
        while (temp != NULL)
        {
            if ((strcmp(temp->name, old_name)) == 0)
            {
                strcpy(temp->name, name);
            }
            temp = temp->next;
        }
    }
}

void display_list(emp *temp)
{
    if (first == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = first;
        printf("----List is: ----\n");
        while (temp != NULL)
        {
            printf("Name: %s\n", temp->name);
            printf("Employee id: %d\n", temp->id);
            printf("Employee salary: %lf\n", temp->sal);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    emp *employee;
    employee = NULL;
    create_data(employee);
    display_list(employee);
    avg_sal(employee);
    printf("\n----------------\n");
    sort(employee);
    printf("\nsorted list is: \n");
    display_list(employee);
    printf("\n----------------\n");
    update_name(employee);
    printf("Updated list is: \n");
    display_list(employee);
    free(employee);
    return 0;
}