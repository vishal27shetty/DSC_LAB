#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *top = NULL;
void push(int value);
int pop();
int peek();
void display();

int main() {
  int choice, item;
  while (1) {
    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5.Exit");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the value to be inserted: ");
      scanf("%d", &item);
      push(item);
      break;
    case 2:
      item = pop();
      if (item != -1) {
        printf("%d deleted from the stack", item);
      }
      break;
    case 3:
      item = peek();
      if (item != -1) {
        printf("Top element is %d", item);
      }
      break;
    case 4:
      display();
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice");
    }
  }
  return 0;
}

void push(int item) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = item;
  temp->next = top;
  top = temp;
}

int pop() {
  if (top == NULL) {
    printf("Stack is empty");
  }
  Node *temp = top;
  top = top->next;
  int item = temp->data;
  free(temp);
  return item;
}

int peek() {
  if (top == NULL) {
    printf("Stack is empty");
  }
  return top->data;
}

void display() {
  if (top == NULL) {
    printf("Stack is empty");
  }
  Node *temp = top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
