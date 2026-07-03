#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print(TreeNode* node) {
    if (node == NULL) return;
    print(node->left);
    printf("%d ", node->data);
    print(node->right);
}

void init(BinaryTree* tree) {
    tree->root = NULL;
}

TreeNode *search(TreeNode *root, int data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

TreeNode *insertNode(TreeNode *root, int data) {
    if (root == NULL) return makeNode(data);
    if (data < root->data) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

int main() {
    printf("Cay 1.1\n");
    BinaryTree tree1;
    init(&tree1);

    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n1 = sizeof(data1) / sizeof(data1[0]);

    for (int i = 0; i < n1; i++) {
        tree1.root = insertNode(tree1.root, data1[i]);
    }
    print(tree1.root);
    printf("\n\n");



    printf("Cay 1.2\n");
    BinaryTree tree2;
    init(&tree2);

    int data2[] = {50, 17, 76, 9, 23, 54, 14, 19, 72, 12, 67};
    int n2 = sizeof(data2) / sizeof(data2[0]);

    for (int i = 0; i < n2; i++) {
        tree2.root = insertNode(tree2.root, data2[i]);
    }
    print(tree2.root);
    printf("\n\n");


    printf("Cay 1.3\n");
    BinaryTree tree3;
    init(&tree3);

    int data3[] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 35};
    int n3 = sizeof(data3) / sizeof(data3[0]);

    for (int i = 0; i < n3; i++) {
        tree3.root = insertNode(tree3.root, data3[i]);
    }
    print(tree3.root);
    printf("\n\n");

    printf("Cay 1.4\n");
    BinaryTree tree4;
    init(&tree4);

    int data4[] = {3, 1, 10, 13, 5, 11, 16, 6, 15, 2, 9, 4};
    int n4 = sizeof(data4) / sizeof(data4[0]);

    for (int i = 0; i < n4; i++) {
        tree4.root = insertNode(tree4.root, data4[i]);
    }
    print(tree4.root);
    printf("\n");

    return 0;
}
