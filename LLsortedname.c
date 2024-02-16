#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    struct node * next;
} Node;

Node * head=NULL;

void insert(char *name);
void delete(char *name);
void display();

int main()
{
    int choice;
    char name[100];
    while(1)
    {
        printf("\n1. Insert a name \n 2. Delete a name \n 3. Display \n 4. Exit \n Enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("\nEnter the name to be inserted\n");
                scanf("%s",name);
                insert(name);
                break;
            case 2: 
                printf("\nEnter the name to be deleted\n");
                scanf("%s",name);
                delete(name);
                break;
            case 3: display();
                break;
            case 4: exit(0);
            default: printf("\nInvalid");
        }
    }
}

void insert(char * name)
{
    Node * newnode = (Node *)malloc(sizeof(Node));
    strcpy(newnode->name,name);
    newnode->next=NULL;
    if(head==NULL || strcmp(head->name,name)>=0)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        Node * current = head;
        while(current->next!=NULL && strcmp(current->next->name,name)<0)
        {
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
}

void delete(char * name)
{
    Node * temp = head;
    Node * prev;
    if(temp!=NULL && strcmp(temp->name,name)==0)
    {
        head=head->next;
        free(temp);
        return;
    }
    
    while(temp!=NULL && strcmp(temp->name,name)!=0)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Given name is not found");
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void display()
{
    Node * ptr=head;
    while(ptr!=NULL)
    {
        printf("%s\n",ptr->name);
        ptr=ptr->next;
    }
}
