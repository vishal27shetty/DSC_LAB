#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int items[MAX];
int front=-1;
int rear=-1;
void insert();
void delete();
void display();

int main()
{   
    int ch;
    while(1)
    {
        printf("Enter your choice \n 1. Add call \n 2. Remove call \n 3. Display call list \n 4. Exit \n");
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

void insert()
{
    int value;
    printf("\nEnter the element \n");
    scanf("%d",&value);
    if (rear==MAX-1)
        printf("\nOVERFLOW\n");
    else
    {
        if(front==-1)
            front=0;
        rear=rear+1;
        items[rear]=value;
        printf("\nCaller id add is = %d \n",value);
    }
}

void delete()
{
    if (front==-1)
        printf("\nUNDERFLOW\n");
    else
    {
        printf("\nCaller id deleted is : %d\n",items[front]);
        front++;
        
        if(front>rear)
            front=rear=-1;
    }
}

void display()
{
    if (rear==-1)
        printf("\nCall queue is empty\n");
    else
    {
        printf("\n Calls held in the queue are \n");
        for(int i=front;i<=rear;i++)
            printf("%d\n",items[i]);
    }
}
