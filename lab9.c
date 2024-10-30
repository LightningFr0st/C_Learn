#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    struct node* prv;
    int data;
};

struct node* head = NULL;
struct node* end = NULL;

void add(int p_d) {
    if (head == NULL) {
        head = malloc(sizeof(*head));
        head->data = p_d;
        head->next = NULL;
        head->prv = NULL;
        end = head;
    }
    else {
        end->next = malloc(sizeof(*end));
        end->next->prv = end;
        end = end->next;
        end->data = p_d;
        end->next = NULL;
    }
}

void output() {
    struct node* cp = head;
    while (cp != NULL) {
        printf("%d ", cp->data);
        cp = cp->next;
    }
    printf("\n");
}

void delete(int p_d) {
    struct node* cp = head;
    while (cp != NULL) {
        if (cp->data == p_d) {
            struct node* del = cp;
            if (cp->prv != NULL) {
                cp->prv->next = cp->next;
                cp->next->prv = cp->prv;
            }
            else {
                head = cp->next;
                head->prv = NULL;
            }
            cp = cp->next;
            if (end == del) {
                end = del->prv;
            }
            free(del);
        }else
            cp = cp->next;
    }
}

int main() {
    int run = 1;
    while (run) {
        int req,n;
        scanf("%d", &req);
        switch (req) {
        case 1:
            printf("N: ");
            scanf("%d", &n);
            add(n);
            break;
        case 2:
            output();
            break;
        case 3:
            printf("Delete: ");
            scanf("%d", &n);
            delete(n);
            break;
        case 4:
            run = 0;
            break;
        }
    }
    return 0;
}