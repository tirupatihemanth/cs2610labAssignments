#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

typedef struct Node_ Node;
struct Node_ {
    int data;
    Node* left;
    Node* right;
};

Node* new_node(int data) {
    Node* n = (Node *) malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert_node(Node* root, int val) {
    if(root == NULL) {
        root = new_node(val);
    }
    else {
        if(val < root->data) {
            root->left = insert_node(root->left, val);
        }
        else {
            root->right = insert_node(root->right, val);
        }
    }
    return root;
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    else return 1 + max(height(root->left), height(root->right));
}

int diameter(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(max(ldiameter, rdiameter), 1+lheight+rheight);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int T, N;
    scanf("%d", &T);
    while(T--) {
        Node* root = NULL;
        scanf("%d", &N);
        while(N--) {
            int val;
            scanf("%d", &val);
            root = insert_node(root, val);
        }
        printf("%d\n", diameter(root));
    }
    return 0;
}

