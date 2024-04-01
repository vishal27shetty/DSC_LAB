#include <stdio.h>
#include <ctype.h>
#define MAX 5
char s[MAX];
int top=-1;

void push(char x)
{
    if(top>=MAX-1)
        printf("Stack overflow\n");
    else
    {  
        s[++top]=x;
    }
}

char pop()
{
    if(top<=-1)
    {
        printf("Underflow");
        return '\0';
    }
    else 
    {
        return s[top--];
    }
}

int priority(char opr)
{
    if(opr=='(' || opr == ')')
        return 0;
    else if(opr=='+' || opr == '-')
        return 1;
    else if(opr=='/' || opr == '*')
        return 2;
    
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else 
        return 0;
}

int main() {
    char exp[50];
    int i = 0;
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    while(exp[i]!='\0')
    {
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            char next;
            while((next=pop())!='(')
                printf("%c",next);
        }
        else 
        {
            while(!isEmpty() && priority(s[top])>=priority(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }
        i++;
    }
    while(!isEmpty())
        printf("%c",pop());
    return 0;
}
