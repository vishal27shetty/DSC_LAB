#include <stdio.h>
#include <stdlib.h>
#define MAX 3
struct cq {
    int items[MAX];
    int front,rear;
};
struct cq cq;

void intialize();
void display();
void insert();
void delete();
int isFull();
int isEmpty();

int main()
{   
    intialize();
    int ch;
    while(1)
    {
        printf("\nEnter your choice \n 1. Add element \n 2. Remove element \n 3. Display elements \n 4. Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                break;
            case 2:delete();
                break;
            case 3:display();
                break;
            case 4: exit(0);
            default: printf("Invalid choice");
                break;
        }
    }
    
}
 void intialize()
 {
    cq.front=-1;
    cq.rear=-1;
 }

int isFull()
{
    if(cq.front==(cq.rear+1)%MAX)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(cq.front==-1)
        return 1;
    else
        return 0;
}

void insert()
{
    int value;
    if(isFull())
        printf("\nOVERFLOW\n");
    else
    {
        printf("\nEnter the value\n");
        scanf("%d",&value);
        if (cq.front==-1)
            cq.front=cq.rear=0;
        else
            cq.rear=(cq.rear+1)%MAX;
        cq.items[cq.rear]=value;
        printf("\nThe inserted element is %d", value);
        
    }
}

void delete() 
{
    if(isEmpty())
        printf("\nUNDERFLOW\n");
    else
    {
        printf("\nThe deleted element is %d", cq.items[cq.front]);
        if(cq.front==cq.rear)
            cq.front=cq.rear=-1;
        else
            cq.front=(cq.front+1)%MAX;
    }
}

void display()
{
    if (isEmpty())
        printf("\nThe list is empty\n");
    else
    {
        printf("\nThe list is\n");
        for (int i = cq.front; i != cq.rear; i = (i + 1) % MAX)
        {
            printf("%d\n", cq.items[i]);
        }
        printf("%d",cq.items[cq.rear]);
    }
}

