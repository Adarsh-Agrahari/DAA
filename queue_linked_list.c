#include<stdio.h>
#include<stdlib.h>

struct node *f=NULL;        //global declaration of f
struct node *r=NULL;        //global declaration of r

struct node
{
    int data;
    struct node* next;
};

// display

void traversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

// check Full

int isFull()
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if(n==NULL)
        return 1;
    return 0;
}

// check empty

int isEmpty()
{
    struct node *n = f;
    if(f==NULL)
        return 1;
    return 0;
}

// insertion

void enqueue(int val)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if(isFull())
        printf("Queue overflow\n");
    else
    {
    n->data=val;
    n->next = NULL;
    if(f==NULL)
        f=r=n;
    else
        r->next=n;
        r=n;
    }
}

// deletion

int dequeue()
{
    struct node *n = f;
    int val=-1;
    if(isEmpty())
        printf("Queue underflow\n");
    else
    {
    f=f->next;
    val = n->data;
    free(n);
    }
    return val;
}