#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

void inOrder(struct Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
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


// Insert in BST
void insert(struct Node *root, int key) {
    struct Node *prev = root;
    while(root != NULL) {
        prev = root;
        if(key == root->data) {
            printf("%d already present, cannot Insert!\n", key);
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
        prev->left = newNode;
    }
    else {
        prev->right = newNode;
    }
}

struct Node *inOrderPredecessor(struct Node *root) {
    root = root -> left;
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct Node *delete(struct Node *root, int value) {
    struct Node *iPre;
    if(root == NULL) {
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL) { // Deleting Leaf Node
        free(root);
        return NULL;
    }
    else if(value < root->data) {
        root->left = delete(root->left, value);
    }
    else if(value > root->data) {
        root->right = delete(root->right, value);
    }
    else {
        iPre = inOrderPredecessor(root);
        printf("\nRoot Data is %d\n", root->data);
        root->data = iPre->data;
        root->left = delete(root->left, iPre->data);
    }
    return root;
}

int main() {
    struct Node *p = createNode(7);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(11);
    struct Node *p3 = createNode(3);
    struct Node *p4 = createNode(6);
    struct Node *p5 = createNode(10);
    struct Node *p6 = createNode(12);
    struct Node *p7 = createNode(2);

    // Linking the Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p3->left = p7;

    printf("\nInOrder: ");
    inOrder(p);
    printf("\nPreOrder: ");
    preOrder(p);
    printf("\nPostOrder: ");
    postOrder(p);
    printf("\nInserting 5...\n");
    insert(p, 5);
    printf("\nInOrder: ");
    inOrder(p);
    printf("\nPredecessor: %d\n", inOrderPredecessor(p2)->data);

    delete(p, 7);
    inOrder(p);
    return 0;
}