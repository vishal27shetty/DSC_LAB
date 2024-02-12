#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluateExpression(char exp[]) {
    int i, op1, op2, result;
    char ch;

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    int res = evaluateExpression(exp);
    printf("Result: %d\n", res);
    return 0;
}

