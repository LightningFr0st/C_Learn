#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(x,y) (x)^=(y)^=(x)^=(y)


struct node {
    struct node* next;
    struct node* prv;
    int data;
};

void add(int p_d, struct node** p_head, struct node** p_end) {
    if (*p_head == NULL) {
        *p_head = malloc(sizeof(**p_head));
        (*p_head)->data = p_d;
        (*p_head)->next = NULL;
        (*p_head)->prv = NULL;
        *p_end = *p_head;
    }
    else {
        (*p_end)->next = malloc(sizeof(**p_end));
        (*p_end)->next->prv = (*p_end);
        *p_end = (*p_end)->next;
        (*p_end)->data = p_d;
        (*p_end)->next = NULL;
    }
}

void output(struct node* end) {
    struct node* cp = end;
    while (cp != NULL) {
        printf("%d ", cp->data);
        cp = cp->prv;
    }
    printf("\n");
}

//void delete(int p_d) {
//    struct node* cp = head;
//    while (cp != NULL) {
//        if (cp->data == p_d) {
//            struct node* del = cp;
//            if (cp->prv != NULL) {
//                cp->prv->next = cp->next;
//                cp->next->prv = cp->prv;
//            }
//            else {
//                head = cp->next;
//                head->prv = NULL;
//            }
//            cp = cp->next;
//            if (end == del) {
//                end = del->prv;
//            }
//            free(del);
//        }
//        else
//            cp = cp->next;
//    }
//}


void sort(struct node* head, struct node* end) {
    struct node* endptr = end;
    while (endptr != head) {
        struct node* cp = head;
        while (cp->next != NULL) {
            if (cp->data > cp->next->data) {
                swap(cp->data, cp->next->data);
            }
            cp = cp->next;
        }
        endptr = endptr->prv;
    }
}

int main() {

    struct node* head1 = NULL;
    struct node* end1 = NULL;
    struct node* head2 = NULL;
    struct node* end2 = NULL;

    int run = 1;
    printf("First stack : ");
    while (run) {
        char n[64];
        scanf("%s", n);
        if (!strcmp(n, "end"))
            break;
        add(atoi(n), &head1, &end1);
    }
    output(end1);
    printf("Second stack : ");
    while (run) {
        char n[64];
        scanf("%s", n);
        if (!strcmp(n, "end"))
            break;
        add(atoi(n), &head2, &end2);
    }
    output(end2);
    head2->prv = end1;
    end1->next = head2;
    sort(head1, end2);
    output(end2);
    return 0;
}