#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push(int x) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = top;
    top = p;
    printf("Pushed %d into stack\n", x);
}

int pop() {
    if (top == NULL) return -1;
    int x = top->data;
    struct node *t = top;
    top = top->next;
    free(t);
    return x;
}

void enqueue(int x) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if (rear == NULL)
        front = rear = p;
    else {
        rear->next = p;
        rear = p;
    }
    printf("Enqueued %d into queue\n", x);
}

int dequeue() {
    if (front == NULL) return -1;
    int x = front->data;
    struct node *t = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
    return x;
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Stack pop: %d\n", pop());
    printf("Stack pop: %d\n", pop());

    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("Queue dequeue: %d\n", dequeue());
    printf("Queue dequeue: %d\n", dequeue());

    return 0;
}
