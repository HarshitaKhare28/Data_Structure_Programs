//circular queue
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int *que;
    int f;
    int r;
    int max;
};

void enqueue(struct Queue *q,int elem){
    if((q->f == (q->r+1) % q->max) && (q->f == q->r)){
        printf("Queue is full!\n");
    }else{
        if(q->f == -1 && q->r == -1){
            q->f = 0;
            q->r = 0;
            q->que[q->r]  = elem;
        }else{
            // q->r = q->r + 1;
            // q->que[q->r] = elem;
            q->r = (q->r + 1)% q->max;
            q->que[q->r] = elem;
        }
    }
}

int dequeue(struct Queue *q){
    if(q->f == -1){
        printf("Queue is empty!");
        return -1;
    }else{
        if(q->f == q->r){
            int x = q->que[q->f];
            q->f = -1;
            q->r = -1;
            return x;
        }else{
            int x = q->que[q->f];
            q->f = (q->f + 1)%q->max;
            return x;
        }
    }
}

void display(struct Queue *q){
    if(q->f <= q->r){
        for(int i=q->f;i<=q->r;i++){
            printf("%d\n",q->que[i]);
        }
    }
    else if(q->f > q->r){
        for(int i =q->f;i<q->max;i++){
            printf("%d\n",q->que[i]);
        }
        for(int i =0;i<q->r;i++){
            printf("%d\n",q->que[i]);
        }
    }
    
}

int main(){
    struct Queue *q;
    int elem;
    q->max = 5;
    int n = q->max;
    q->f = -1;
    q->r = -1;
    // printf("Enter number of elements in Queue\n");
    // scanf("%d",&n);
    q->que = (int*)malloc(n*sizeof(int));
    // printf("enter the elements: \n");
    // for(int i =0;i<n;i++){
    //     enqueue(q,i);
    // }
    enqueue(q,1);
    enqueue(q,10);
    enqueue(q,6);
    enqueue(q,3);
    enqueue(q,9);
    printf("the elements entered are: \n");
    display(q);

    int x = dequeue(q);
    int y = dequeue(q);
    printf("deleted elements: \n%d %d\n",x,y);
    printf("after deletion elements left:\n");
    display(q);
    return 0;
}