#include <ctype.h>

// Minimalistic integer stack to be used by the algorithm
char stack[20];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int isEmpty()
{
    return top == -1; // 1 if 0 or 0 returned
}

int priority(char opr)
{
    if(opr == '(' || opr == ')')
        return 0; // lowest
    if(opr == '+' || opr == '-')
        return 1;
    if(opr == '*' || opr == '/')
        return 2; // highest
    return 0;
}

int main()
{
    char exp[20], x;
    printf("Enter the expression: ");
    scanf("%s", exp);
    
    printf("Postfix expression is:");
    
    // Algorithm implementation
    int i = 0;

    while(exp[i] != '\0')
    {
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] =='(')
            push(exp[i]);
        else if(exp[i] ==')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else 
        { 
            while(!isEmpty() && priority(stack[top]) >= priority(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }
        i++; // Take the next character from exp[]
    }
    // Pop out all operators left on stack and add to postfix expression 
    while(!isEmpty())
        printf("%c",pop());

    return 0;
}

