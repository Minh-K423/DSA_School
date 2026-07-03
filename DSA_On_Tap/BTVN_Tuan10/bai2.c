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

TreeNode *search(TreeNode *root, int data, int *found) {
    if (root == NULL) {
        *found = 0;
        return root;
    }
    if (root->data == data) {
        *found = 1;
        return root;
    }
    if (data < root->data) return search(root->left, data, found);
    return search(root->right, data, found);
}

void print_level(TreeNode *root, int initial_level, int target_level) {
    if (root == NULL) return;
    if (initial_level == target_level) printf("%d ", root->data);
    else {
        print_level(root->left, initial_level + 1, target_level);
        print_level(root->right, initial_level + 1, target_level);
    }
}

TreeNode *insertNode(TreeNode *root, int data) {
    if (root == NULL) return makeNode(data);
    if (data < root->data) root->left = insertNode(root->left, data);
    else if (data > root->data) root->right = insertNode(root->right, data);
    return root;
}

TreeNode *findMin(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMin(root->left);
    return root;
}

TreeNode *delete_helper(TreeNode *root, int data, int *found) {
    if (root == NULL)
        return NULL;
    if (data > root->data)
        root->right = delete_helper(root->right, data, found);
    else if (data < root->data)
        root->left = delete_helper(root->left, data, found);
    else {
        *found = 1;
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            TreeNode *temp;
            if (root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp;
        } else {
            TreeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete_helper(root->right, temp->data, found);
        }
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int data) {
    int found = 0;
    root = delete_helper(root, data, &found);

    if (found == 0) {
        printf("Not found %d\n", data);
    } else {
        printf("Successfully delete %d\n", data);
    }
    return root;
}

void experiment(TreeNode* root, int search_value, int delete_value, int insert_value) {
    int found_result ;
    TreeNode *result = search(root, search_value, &found_result);
    if (found_result == 0) {
        printf("Search %d: Not found\n", search_value);
    } else {
        printf("Search %d: Found at %p\n", search_value, result);
    }
    root = deleteNode(root, delete_value);
    root = insertNode(root, insert_value);
    print(root);
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
    printf("\n");
    experiment(tree1.root, 25, 12, 23);
    printf("\n");
    printf("Level 3:\n");
    print_level(tree1.root, 1, 3);
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
    printf("\n");
    experiment(tree2.root, 25, 12, 23);
    printf("\n");
    printf("Level 3:\n");
    print_level(tree2.root, 1, 3);
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
    printf("\n");
    experiment(tree3.root, 25, 12, 23);
    printf("\n");
    printf("Level 3:\n");
    print_level(tree3.root, 1, 3);
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
    experiment(tree4.root, 25, 12, 23);
    printf("\n");
    printf("Level 3:\n");
    print_level(tree4.root, 1, 3);
    printf("\n");

    return 0;
}

/*
 *
 * Cay 1.1
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 Search 25: Not found
 Successfully delete 12
 1 2 3 4 5 6 7 8 9 10 11 13 14 15 23
 Level 3:
 3

 Cay 1.2
 9 12 14 17 19 23 50 54 67 72 76
 Search 25: Not found
 Successfully delete 12
 9 14 17 19 23 50 54 67 72 76
 Level 3:
 9 23 54

 Cay 1.3
 6 8 9 11 12 14 15 20 26 30 35
 Search 25: Not found
 Successfully delete 12
 6 8 9 11 14 15 20 23 26 30 35
 Level 3:
 8 14 20 30

 Cay 1.4
 1 2 3 4 5 6 9 10 11 13 15 16
 Search 25: Not found
 Not found 12
 1 2 3 4 5 6 9 10 11 13 15 16 23
 Level 3:
 2 5 13
 */
