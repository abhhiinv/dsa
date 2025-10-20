#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;
int count = 0;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertBeginning(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
    count--;
}

// Delete from end
void deleteEnd() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
    count--;
}

// Traversal from beginning
void traverseFromBeginning() {
    Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traversal from end
void traverseFromEnd() {
    Node* temp = tail;
    printf("List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Count elements
void countElements() {
    printf("Number of elements: %d\n", count);
}

// Main menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Traverse from beginning\n");
        printf("6. Traverse from end\n");
        printf("7. Count elements\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                deleteBeginning();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                traverseFromBeginning();
                break;
            case 6:
                traverseFromEnd();
                break;
            case 7:
                countElements();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
