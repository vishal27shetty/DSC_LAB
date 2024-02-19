
      #include <stdio.h>
      #include <stdlib.h>

      struct Node {
          int data;
          struct Node* prev;
          struct Node* next;
      };

      struct Node* createNode(int data) {
          struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
          if (newNode == NULL) {
              printf("Memory allocation failed.\\n");
              exit(EXIT_FAILURE);
          }

          newNode->data = data;
          newNode->prev = NULL;
          newNode->next = NULL;

          return newNode;
      }

      void insertToLeft(struct Node** head, int key, int newData) {
          struct Node* newNode = createNode(newData);

          if (*head == NULL) {
              printf("List is empty. Cannot insert to the left.\\n");
              free(newNode);
              return;
          }

          struct Node* current = *head;

          while (current != NULL && current->data != key) {
              current = current->next;
          }

          if (current == NULL) {
              printf("Key not found. Cannot insert to the left.\\n");
              free(newNode);
              return;
          }

          if (current->prev == NULL) {
              // Insert at the beginning
              newNode->next = current;
              current->prev = newNode;
              *head = newNode;
          } else {
              newNode->prev = current->prev;
              newNode->next = current;
              current->prev->next = newNode;
              current->prev = newNode;
          }

          printf("Node with data %d inserted to the left of node with key %d.\\n", newData, key);
      }

      void deleteNode(struct Node** head, int data) {
          if (*head == NULL) {
              printf("List is empty. Cannot delete.\\n");
              return;
          }

          struct Node* current = *head;

          while (current != NULL && current->data != data) {
              current = current->next;
          }

          if (current == NULL) {
              printf("Node with data %d not found. Cannot delete.\\n", data);
              return;
          }

          if (current->prev == NULL) {
              // Deleting the first node
              *head = current->next;
              if (current->next != NULL) {
                  current->next->prev = NULL;
              }
          } else {
              current->prev->next = current->next;
              if (current->next != NULL) {
                  current->next->prev = current->prev;
              }
          }

          free(current);
          printf("Node with data %d deleted.\\n", data);
      }

      void displayList(struct Node* head) {
          if (head == NULL) {
              printf("List is empty.\\n");
          } else {
              printf("Doubly Linked List: ");
              while (head != NULL) {
                  printf("%d ", head->data);
                  head = head->next;
              }
              printf("\\n");
          }
      }

      int main() {
          struct Node* head = NULL;

          insertToLeft(&head, 20, 10);
          insertToLeft(&head, 20, 15);
          insertToLeft(&head, 15, 5);
          insertToLeft(&head, 10, 8);
          displayList(head);

          deleteNode(&head, 15);
          displayList(head);

          deleteNode(&head, 20);
          displayList(head);

          deleteNode(&head, 5);
          displayList(head);

          return 0;
      }
