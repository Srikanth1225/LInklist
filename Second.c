#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node nd;

void insertAtPosition(nd **head, int value, int position) {
    nd *newNode = (nd *)malloc(sizeof(nd));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    nd *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
  printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(nd **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    nd *temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    nd *prev = NULL;
    for (int i = 1; temp != NULL  && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void displayList(nd *head) {
    nd *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

int main() {
    nd *head = NULL;
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                printf("Updated List: ");
                displayList(head);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                printf("Updated List: ");
                displayList(head);
                break;

            case 3:
                  printf("Current List: ");
                displayList(head);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}




