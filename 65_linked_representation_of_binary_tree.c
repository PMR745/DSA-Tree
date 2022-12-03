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

void preOrder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
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

    printf("This is PreOrder:  ");
    preOrder(p);
    printf("\nThis is PostOrder: ");
    postOrder(p);
    printf("\nThis is InOrder: ");
    inOrder(p);
    return 0;
}