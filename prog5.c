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

void createList(int n) {
    int x;
    struct Node *t, *last;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node *newNode = createNode(x);

        if (head == NULL) {
            head = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) return;
    struct Node *t = head;
    head = head->next;
    free(t);
    printf("First element deleted.\n");
}

void deleteLast() {
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last element deleted.\n");
        return;
    }

    struct Node *t = head;
    while (t->next->next != NULL)
        t = t->next;

    free(t->next);
    t->next = NULL;
    printf("Last element deleted.\n");
}

void deleteElement(int x) {
    if (head == NULL) return;

    if (head->data == x) {
        deleteFirst();
        return;
    }

    struct Node *t = head;
    while (t->next != NULL && t->next->data != x)
        t = t->next;

    if (t->next == NULL) {
        printf("Element %d not found.\n",x);
        return;
    }

    struct Node *del = t->next;
    t->next = del->next;
    free(del);
    printf("Element %d deleted.\n", x);
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
    int n;
    printf("How many nodes? ");
    scanf("%d", &n);

    createList(n);
    display();

    deleteFirst();
    deleteElement(5);
    deleteLast();

    display();

    return 0;
}
