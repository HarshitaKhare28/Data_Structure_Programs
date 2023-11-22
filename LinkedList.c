// linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *temp;
node *ptr;
node *first = NULL;

void create(node *temp)
{
    int n;
    printf("enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        node *temp = (node*)malloc(sizeof(node));
        printf("enter value: \n");
        scanf("%d", &temp->data);
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

void display(node *ptr)
{
    if (first == NULL)
    {
        printf("list is empty");
    }
    else
    {
        ptr = first;
        printf("Elements are: \n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

void insert(node *temp,int pos,int elem){
    //insert at first
    if(pos == 1){
        temp->data = elem;
        temp->next = first;
        first = temp;
    }else{
        // insert in between and last
        int choice;
        printf("where do you want to insert?\n For Last enter: 0\n For In Between enter: 1\n");
        scanf("%d",&choice);
        if(choice == 1){//in between
            ptr = first;
        for(int i=0;i<pos -2;i++){
            ptr = ptr->next;
        }
        temp->data = elem;
        temp->next = ptr->next;
        ptr->next = temp;
        }else{
            ptr = first;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            temp->data = elem;
            ptr->next = temp;
            temp->next = NULL;
        }
    }
}

void delete(node *ptr,int pos){
    if(first->next == NULL){
        printf("List is empty: \n");
    }
    //delete 1st element
    if(pos == 1){
        ptr = first;
        first = first->next;
        free(ptr);
    }else{
        // at last and in between
        int choice;
        printf("where do you want to delete?\n For Last enter: 0\n For In Between enter: 1\n");
        scanf("%d",&choice);
        if(choice == 1){//in between
            ptr = first;
            for(int i = 0;i<pos -2;i++){
                ptr = ptr->next;
            }
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }else{// at last
            ptr = first;
            while(ptr->next->next != NULL){
                ptr = ptr->next;
            }
            temp = ptr->next;
            ptr->next = NULL;
            free(temp);
        }
    }
}

void update(node *ptr,int elem){
    int old_elem, i;
    printf("\nenter the element to be modified: \n By default 3000 will be updated: \n");
    scanf("%d", &old_elem);
    ptr = first;
    while(ptr->next != NULL){
        if(ptr->data == old_elem){
            ptr->data = elem;
            break;
        }
        ptr = ptr->next;
    }
}

void search(node *ptr,int elem){
    ptr = first;
    int count = 1;
    while(ptr->next != NULL){
        if(ptr->data == elem){
            break;
        }
        ptr = ptr->next;
        count++;
    }
    printf("\nelement found at Position: %d\n",count);
}
void reverse(node *temp){
    node* prev;
    node* now;
    prev = first;
    now = prev->next;
    temp = now->next;
    prev->next = NULL;
    now->next = prev;
    while(temp->next != NULL){
        prev = now;
        now = temp;
        temp = temp->next;
        now->next = prev;
    }
    temp->next = now;
    first = temp;
}
int main()
{
    node *l;
    int pos,elem;
    create(l);
    display(l);
    printf("\nenter position and element to insert: \n");
    scanf("%d%d",&pos,&elem);
    insert(l,pos,elem);
    display(l);

    printf("\nenter position to delete: \n");
    scanf("%d",&pos);
    delete(l,pos);
    printf("\narray after deleting: \n");
    display(l);

    update(l,3000);
    display(l);

    printf("\nenter element to search: \n");
    scanf("%d",&elem);
    search(l,elem);

    reverse(l);
    printf("\nreversed list: \n");
    display(l);
    return 0;
}