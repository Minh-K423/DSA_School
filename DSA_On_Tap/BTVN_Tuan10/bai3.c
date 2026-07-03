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

TreeNode *search_helper(TreeNode *root, int data, int *found) {
    if (root == NULL) {
        *found = 0;
        return root;
    }
    if (root->data == data) {
        *found = 1;
        return root;
    }
    if (data < root->data) return search_helper(root->left, data, found);
    return search_helper(root->right, data, found);
}

TreeNode *searchNode(TreeNode *root, int data) {
    int found;
    TreeNode *node = search_helper(root, data, &found);
    if (found) {
        printf("Found: %d at %p\n", data, node);
        return node;
    } else {
        printf("Not found: %d\n", data);
        return NULL;
    }
}

void print_level(TreeNode *root, int initial_level, int target_level) {
    if (root == NULL) return;
    if (initial_level == target_level) printf("%d ", root->data);
    else {
        print_level(root->left, initial_level + 1, target_level);
        print_level(root->right, initial_level + 1, target_level);
    }
}

int count_level(TreeNode *root) {
    if (root == NULL) return 0;
    int left_level = count_level(root->left);
    int right_level = count_level(root->right);
    if (left_level > right_level) return left_level + 1;
    return right_level + 1;
}

void count_node_each_level(TreeNode *root, int initial_level, int target_level, int *count) {
    if (root == NULL) return;
    if (initial_level == target_level) (*count)++;
    if (initial_level > target_level) return;
    else {
        count_node_each_level(root->left, initial_level + 1, target_level, count);
        count_node_each_level(root->right, initial_level + 1, target_level, count);
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

void mass_insertion(int arr[], int start, int end, TreeNode **root) {
    if (start > end) return;

    int mid = start + (end - start) / 2;

    *root = insertNode(*root, arr[mid]);

    mass_insertion(arr, start, mid - 1, root);
    mass_insertion(arr, mid + 1, end, root);
}

// 2 layer pointer cuz you are  modifying the pointer itself:))

void calc_total_node_with_one_child(TreeNode* root, int* total) {
    if (root == NULL) return;

    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
        (*total) += root->data;
    }

    calc_total_node_with_one_child(root->left, total);
    calc_total_node_with_one_child(root->right, total);
}

void calc_total_node_with_one_child_on_left(TreeNode* root, int* total) {
    if (root == NULL) return;

    if (root->left != NULL && root->right == NULL) {
        (*total) += root->data;
    }

    calc_total_node_with_one_child_on_left(root->left, total);
    calc_total_node_with_one_child_on_left(root->right, total);
}

void node_with_closest_value(TreeNode* root, int target, int* closest) {
    if (root == NULL) return;

    if (abs(root->data - target) < abs(*closest - target)) {
        *closest = root->data;
    }

    node_with_closest_value(root->left, target, closest);
    node_with_closest_value(root->right, target, closest);
}

int main() {
    BinaryTree tree;
    init(&tree);
    int arr[100];
    for (int i=0; i<100; i++) {
        arr[i] = i + 1;
    }
    mass_insertion(arr, 0, 99, &tree.root);
    print(tree.root);
    printf("\n");
    int number_of_levels = count_level(tree.root);
    printf("The number of levels: %d\n", number_of_levels);
    int nodes_each_level[number_of_levels];
    for (int i=1; i<=number_of_levels; i++) {
        int count = 0;
        count_node_each_level(tree.root, 1, i, &count);
        printf("Level %d: %d\n", i, count);
        nodes_each_level[i-1] = count;
    }
    int highest_node_number = nodes_each_level[0];
    int level_of_highest_node = 1;
    for (int i=1; i<number_of_levels; i++) {
        if (nodes_each_level[i] > highest_node_number) {
            highest_node_number = nodes_each_level[i];
            level_of_highest_node = i + 1;
        }
    }
    printf("The highest node number is %d of level %d\n", highest_node_number, level_of_highest_node);

    int total = 0;
    calc_total_node_with_one_child(tree.root, &total);
    printf("The total of all node with one child: %d\n", total);

    int total_on_left = 0;
    calc_total_node_with_one_child_on_left(tree.root, &total_on_left);
    printf("The total of all node with one child on left: %d\n", total_on_left);

    int gap_between = total - total_on_left;
    printf("The gap between total on left and total: %d\n", gap_between);

    int closest = tree.root->data;
    node_with_closest_value(tree.root, gap_between, &closest);
    printf("The closest node to target: %d\n", closest);

    return 0;
}

/*
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
 The number of levels: 7
 Level 1: 1
 Level 2: 2
 Level 3: 4
 Level 4: 8
 Level 5: 16
 Level 6: 32
 Level 7: 37
 The highest node number is 37 of level 7
 The total of all node with one child: 1248
 The total of all node with one child on left: 0
 The gap between total on left and total: 1248
 The closest node to target: 100
 */
