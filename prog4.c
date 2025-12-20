#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insertAtBeginning(int x) {
    struct Node *n = createNode(x);
    n->next = head;
    head = n;
    printf("%d inserted at Beginning.\n",x);
}

void insertAtEnd(int x) {
    struct Node *n = createNode(x);

    if (head == NULL) {
        head = n;
        printf("%d inserted at End.\n",x);
        return;
    }

    struct Node *t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
    printf("%d inserted at End.\n",x);
}

void insertAtPosition(int x, int pos) {
    if (pos == 1) {
        insertAtBeginning(x);
        return;
    }

    struct Node *n = createNode(x);
    struct Node *t = head;

    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL) {
        printf("Position out of range.\n");
        return;
    }

    n->next = t->next;
    t->next = n;
    printf("%d inserted at Position %d.\n",x, pos);
}

void display() {
    struct Node *t = head;
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    insertAtBeginning(5);
    insertAtPosition(25, 4);

    display();
    return 0;
}
