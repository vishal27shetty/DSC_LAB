#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
};
typedef struct node node;
node *head,*temp,*newnode,*prevnode,*run;
void createNode();
void InsertAtStart();
void InsertAtEnd();
void InsertAfterPosition();
void DeleteAtStart();
void DeleteAtEnd();
void DeleteAtPosition();
void display();
int main()  
{
    createNode();
    int ch;
    while(1)
    {
        printf("Select choice \n 1.Insert at start \n 2. Insert at end \n 3. Insert at position \n 4. Delete at star \n 5. Delete at end \n 6. Delete at position \n 7. Display \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: InsertAtStart();
                break;
            case 2: InsertAtEnd();
                break;
            case 3: InsertAfterPosition();
                break;
            case 4: DeleteAtStart();
                break;
            case 5:DeleteAtEnd();
                break;
            case 6: DeleteAtPosition();
                break;
            case 7: display();
                break;
            case 8: exit(0);
            default:printf("invalid entry\n");
        }
    }
    
}

void createNode() 
{
    int choice=1;
    head=0;
    int count=0;
    
    while(choice)
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=newnode;
            temp=newnode;
        }
        
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue enter 1/0 :\t");
        scanf("%d",&choice);
    }
}
 void InsertAtStart()
 {   
     newnode=(node*)malloc(sizeof(node));
     printf("Enter the data\n");
     scanf("%d",&newnode->data);
     newnode->next=head;
     head=newnode;
 }
 
 void InsertAtEnd()
 {  
    newnode=(node*)malloc(sizeof(node));
    temp=head;
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    while(temp->next!=0)
        temp=temp->next;
    temp->next=newnode;
 }
 
 void InsertAfterPosition()
 {  
    newnode=(node*)malloc(sizeof(node));
    int count=0;
    temp=head;
    while(temp!=0)
    {  
        count++;
        temp=temp->next;
    }
    int i=1;
    int pos;
    printf("Enter the position");
    scanf("%d",&pos);
    temp=head;
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    if(pos>count)
        printf("invalid position");
    else
    {
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
 }
 
 void DeleteAtStart()
 {
    temp=head;
    if(head==0)
        printf("list is empty");
    else
        head=head->next;
    free(temp);
 }
 
 void DeleteAtEnd()
 {
    temp=head;
    while(temp->next!=0)
    {   
        prevnode=temp;
        temp=temp->next;
        
    }
    if(temp==head)
        head=0;
    else
        prevnode->next=0;
    free(temp);
 }
 
 void DeleteAtPosition()
 {  node *nextnode;
    temp=head;
    int pos;
    int i=1;
    printf("Enter the position");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++)
        temp=temp->next;
    if (pos==1)
        DeleteAtStart();
    else
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
 }
 void display()
 {
    run=head;
    while(run!=0)
    { 
        printf("%d \n",run->data);
        run=run->next;
    }
 }
