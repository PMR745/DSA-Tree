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

void inOrder(struct Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct Node *inOrderPredecessor(struct Node *root) {
    root = root->left;
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}
struct Node *deleteNode(struct Node *root, int value) {
    struct Node * iPre;
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    if(value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // When node if found to be deleted
    else {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main() {
    // Constructing the root node
    struct Node *p = createNode(5);

    // Constructing the second node
    struct Node *p1 = createNode(3);
    
    // Constructing the third node
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = NULL;
    p2->right = NULL;

    inOrder(p);
    deleteNode(p, 3);
    printf("\n");
    printf("\nData is %d\n", p->data);
    inOrder(p);
    return 0;
}