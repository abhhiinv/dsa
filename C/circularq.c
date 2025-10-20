#include <stdio.h>
#include <stdlib.h>
#define SIZE 15   // You can change size of queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert element
void insert() {
    int val;
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("\nQueue Overflow! Cannot insert.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = val;
    printf("%d inserted successfully.\n", val);
}

// Function to delete element
void delete() {
    if (front == -1) {
        printf("\nQueue Underflow! Nothing to delete.\n");
        return;
    }
    int val = queue[front];
    if (front == rear) {  // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("Deleted element: %d\n", val);
}

// Function to display elements
void display() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Function to count elements
void count() {
    if (front == -1) {
        printf("\nQueue is Empty. Count = 0\n");
        return;
    }
    int cnt = (rear - front + SIZE) % SIZE + 1;
    printf("\nNumber of elements in queue: %d\n", cnt);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: count(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
