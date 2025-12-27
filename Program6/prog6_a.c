#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

void dis(struct node *start) {
    struct node *t = start;
    while (t != NULL) {
        printf("%d ", t->info);
        t = t->next;
    }
    printf("\n");
}

struct node* create_sll() {
    struct node *start = NULL, *p, *last = NULL;
    int item;

    printf("\nEnter items to insert (-999 to stop): ");
    scanf("%d", &item);

    while (item != -999) {
        p = (struct node *) malloc(sizeof(struct node));
        p->info = item;
        p->next = NULL;

        if (start == NULL) {
            start = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }

        scanf("%d", &item);
    }

    return start;
}

void sort(struct node *start) {
    struct node *t1, *t2;
    int temp;

    for (t1 = start; t1 != NULL; t1 = t1->next) {
        for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
            if (t1->info > t2->info) {
                temp = t1->info;
                t1->info = t2->info;
                t2->info = temp;
            }
        }
    }
}

struct node* reverse(struct node *start) {
    struct node *prev = NULL, *cur = start, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

struct node* cat(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;

    struct node *t = head1;
    while (t->next != NULL)
        t = t->next;

    t->next = head2;
    return head1;
}

int main() {
    struct node *s, *t;

    s = create_sll();
    t = create_sll();

    printf("\nBefore sort: ");
    dis(s);

    sort(s);
    printf("After sort: ");
    dis(s);

    printf("\nBefore reverse: ");
    dis(s);

    s = reverse(s);
    printf("After reverse: ");
    dis(s);

    printf("\nBefore concatenation:\n");
    dis(s);
    dis(t);

    s = cat(s, t);
    printf("\nAfter concatenation: ");
    dis(s);

    return 0;
}
