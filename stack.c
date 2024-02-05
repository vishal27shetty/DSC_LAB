#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int s[MAX],top,x;
void push();
void pop();
void palin();
void display();

int main() {
    int ch;
    top=-1;
    while(1)
    {
        printf("Enter appropriate choice\n 1.Push\n 2.Pop \n 3.Check if palindrom\n 4.display\n 5.exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: palin();
                break;
            case 4: display();
                break;
            case 5: exit(0);
            default:printf("invalid entry\n");
        }
    }
    return 0;
}
void push()
{
    if(top>=MAX-1)
        printf("Stack overflow\n");
    else
    {   
        printf("Enter value to be pushed\n");
        scanf("%d",&x);
        s[++top]=x;
    }
}

void pop()
{
    if(top<=-1)
        printf("Underflow");
    else 
    {
        printf("the popped element is %d \n",s[top--]);
    }
}

void display()
{
    if(top<=-1)
        printf("stack is empty");
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",s[i]);
        }
    }
}

void palin()
{
    int floor=0,ceil=top,flag=0;
        while(floor<ceil)
        {
            if(s[floor]!=s[ceil])
            {
                flag=1;
                break;
            }
            floor++;
            ceil--;
        }
        if(flag==1)
            printf("The stack is not a palindrome\n");
        else
            printf("The stack is a palindrome\n");
}
