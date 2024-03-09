#include <stdio.h>
#include <string.h>

#define MAX 10

int top = -1;
char stk[MAX];

void push(char);
char pop();

void main() {
    char exp[MAX], temp;
    int i, flag = 1;

    printf("Enter an expression: ");
    gets(exp);

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                flag = 0;
                break;
            } else {
                temp = pop();
                if ((exp[i] == ')' && (temp == '{' || temp == '[')) ||
                    (exp[i] == '}' && (temp == '(' || temp == '[')) ||
                    (exp[i] == ']' && (temp == '(' || temp == '{'))) {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (top >= 0)
        flag = 0;

    if (flag == 1)
        printf("\nValid expression\n");
    else
        printf("\nInvalid expression\n");
}

void push(char c) {
    if (top == (MAX - 1))
        printf("Stack Overflow\n");
    else {
        top++;
        stk[top] = c;
    }
}

char pop() {
    if (top == -1)
        printf("\nStack Underflow\n");
    else
        return stk[top--];
}

