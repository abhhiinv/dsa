#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

int main() {
    Node *head = NULL, *temp, *newNode, *prev;
    int choice, value, count;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a Node\n");
        printf("3. Traverse List\n");
        printf("4. Count Nodes\n");
        printf(". Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Insert at End
            printf("Enter value: ");
            scanf("%d", &value);
            newNode = (Node*)malloc(sizeof(Node));
            newNode->data = value;
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
            } else {
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
            printf("%d inserted at end.\n", value);
            break;

        case 2: // Delete a Node
            if (head == NULL) {
                printf("List is empty.\n");
                break;
            }
            printf("Enter value to delete: ");
            scanf("%d", &value);

            temp = head;
            prev = NULL;

            // If head needs to be deleted
            if (temp != NULL && temp->data == value) {
                head = temp->next;
                free(temp);
                printf("%d deleted.\n", value);
                break;
            }

            // Search for the node
            while (temp != NULL && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) {
                printf("%d not found.\n", value);
            } else {
                prev->next = temp->next;
                free(temp);
                printf("%d deleted.\n", value);
            }
            break;

        case 3: // Traverse
            if (head == NULL) {
                printf("List is empty.\n");
            } else {
                temp = head;
                printf("List: ");
                while (temp != NULL) {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
            }
            break;

        case 4: // Count
            count = 0;
            temp = head;
            while (temp != NULL) {
                count++;
                temp = temp->next;
            }
            printf("Number of nodes: %d\n", count);
            break;

        case 5: // Exit
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
