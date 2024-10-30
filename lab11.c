#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int levels[100] = { 0 };

struct node {
    int key;
    struct node* left;
    struct node* right;    
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    static int level = 0;
    if (node == NULL) {
        levels[level]++;
        level = 0;
        return newNode(key);
    }
    if (key < node->key) {
        level++;
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        level++;
        node->right = insert(node->right, key);
    }

    return node;
}

void print2D(struct node* cur, int count) {
    if (cur == NULL) {
        return;
    }
    count += 10;
    print2D(cur->right, count);
    printf("\n");
    for (int i = 10; i < count; i++) {
        printf(" ");
    }
    printf("%d", cur->key);
    printf("\n");
    print2D(cur->left, count);
}

int main() {

    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 100);
    insert(root, 150);

    print2D(root, 10);

    printf("\n");
    
    int i = 0;
    while (levels[i]) {
        printf("On level %d - %d nodes\n", i, levels[i]);
        i++;
    }

    return 0;
}