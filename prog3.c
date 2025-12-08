#include<stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    printf("Enter the element to insert: ");
    scanf("%d", &item);

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\nQueue Overflow! Cannot insert %d.\n", item);
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = item;
    printf("%d inserted into the circular queue.\n", item);
}

void delete() {
    if (front == -1) {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d deleted from the circular queue.\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCircular Queue elements are:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Circular Queue Operations using Array\n");
    printf("------------------------------------\n");

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
