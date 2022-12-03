#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode; 
    newNode = (struct Node *) malloc (sizeof(struct Node)); // Allocating memory
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void insert(struct Node *root, int key) {
    struct Node *prev = NULL;
    while(root != NULL) {
        prev = root;
        if(key == root->data) {
            printf("\nCannot Insert %d, Already in BST.", key);
            return;
        }
        else if(key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    struct Node *newNode = createNode(key);
    if(key < prev->data) {
        prev -> left = newNode;
    }
    else {
        prev -> right = newNode;
    }
}

void inOrder(struct Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    // Constructing the root node
    struct Node *p = createNode(4);

    // Constructing the second node
    struct Node *p1 = createNode(1);
    
    // Constructing the third node
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = NULL;
    p2->right = NULL;

    insert(p ,7);
    inOrder(p);
    insert(p, 1);
    return 0;
}