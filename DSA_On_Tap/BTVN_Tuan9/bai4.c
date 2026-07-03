#include <stdio.h>
#include <stdlib.h>

#define INITIAL_POSITION 0

typedef struct NodeType {
    int data;
    struct NodeType *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

void init_linked_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

Node *make_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_tail(int data, LinkedList* list) {
    Node *new_node = make_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void insert_recursive(Node *new_node, Node *prev_node, LinkedList *list, int position, int count, int *length) {
    if (position == 1) {
        new_node->next = prev_node->next;
        list->head = new_node;
        (*length)++;
        return;
    }

    /*if (position == *length) {
        list->tail->next = new_node;
        list->tail = new_node;
        (*length)++;
        return;
    }
    I dont know if the problem allows me to insert at the end or just before the end. For example, insert at position 4 in a list of 4 elements should be inserting before the end or at the end.
    */

    if (count == position - 1) {
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        (*length)++;
        return;
    }

    insert_recursive(new_node, prev_node->next, list, position, count+1, length);
}

/*
 * Analysis:
 * Base case: 1. position == 1.
 *            2. count == position - 1.
 * What happens in base case: 1. position == 1. We insert the new node before the head and update the head pointer.
 *                            2. count == position - 1. We insert the new node after the previous node and update the next pointer of the previous node.
 * Before base case: count != position - 1. We recursively call the function with the next node and increment the count and add one more ->next to the previous node.
 * Before before base case: count != position - 1. We recursively call the function with the next node and increment the count and add one more ->next to the previous node.
 *
 */

void delete_recursive(Node *prev_node, LinkedList *list, int position, int count, int *length) {
    if (position == 1) {
        Node *to_delete = list->head;
        list->head = list->head->next;
        free(to_delete);
        (*length)--;
        return;
    }
    /*
     *  if (count == position - 1) {
           prev_node->next = prev_node->next->next;
           free(prev_node->next);
           (*length)--;
           return;
       }
     * This way is wrong, because we are not freeing the node to delete, we are freeing the node after the one we want to delete. Notice we have change the prev_node->next to (the one u need to delete)->next
     */
    if (count == position - 1) {
        Node *to_delete = prev_node->next; // Get the node to delete
        prev_node->next = to_delete->next; // Set prev_node's next to the node after to_delete
        free(to_delete);
        (*length)--;
        return;
    }
    delete_recursive(prev_node->next, list, position, count+1, length);
}

/*
 * Analysis:
 * Base case: 1. count == position - 1.
 *            2. position == 1.
 * What happens at base case:  1. We delete the node at the given position and update the next pointer of the previous node.
 *                             2. We delete the node at the head of the list and update the head pointer of the list.
 * Before base case: count != position - 1. We recursively call the function with the next node and increment the count and add one more ->next to the previous node.
 * Before before base case: count != position - 1. We recursively call the function with the next node and increment the count and add one more ->next to the previous node.
 */

void insert_anywhere(int data, LinkedList* list, int position) {
    Node *new_node = make_node(data);
    Node *current_node = list->head;
    for (int i=1; i<position-1; i++) {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node; // We dont write current_node->next = new_node->next because new_node->next is already set to current_node->next
}

void delete_anywhere(LinkedList *list, int position) {
    Node *current_node = list->head;
    Node *prev_node =NULL;
    for (int i=1; i<position;i++) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    prev_node->next = current_node->next;
    current_node->next = NULL;
    free(current_node);
}

void print_list(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n", node->next);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    init_linked_list(&list);
    int arr[6] = {2,3,4,5,6,7};
    int length = 6;
    for (int i=0; i<6; i++) {
        insert_tail(arr[i], &list);
    }
    printf("Before insert: \n");
    print_list(&list);

    int new_data = 1;
    Node *new_node = make_node(new_data);
    insert_recursive(new_node, list.head, &list, 2, 1, &length);

    printf("After insert: \n");
    print_list(&list);

    delete_recursive(list.head, &list, 2, 1, &length);
    printf("After delete: \n");
    print_list(&list);

    return 0;
}

/*
 * Before insert:
 Node address: 0x562dc77a5010 | data = 2| next node address = 0x562dc77a5030
 Node address: 0x562dc77a5030 | data = 3| next node address = 0x562dc77a5050
 Node address: 0x562dc77a5050 | data = 4| next node address = 0x562dc77a5070
 Node address: 0x562dc77a5070 | data = 5| next node address = 0x562dc77a5090
 Node address: 0x562dc77a5090 | data = 6| next node address = 0x562dc77a50b0
 Node address: 0x562dc77a50b0 | data = 7| next node address = (nil)

 After insert:
 Node address: 0x562dc77a5010 | data = 2| next node address = 0x562dc77a54e0
 Node address: 0x562dc77a54e0 | data = 1| next node address = 0x562dc77a5030
 Node address: 0x562dc77a5030 | data = 3| next node address = 0x562dc77a5050
 Node address: 0x562dc77a5050 | data = 4| next node address = 0x562dc77a5070
 Node address: 0x562dc77a5070 | data = 5| next node address = 0x562dc77a5090
 Node address: 0x562dc77a5090 | data = 6| next node address = 0x562dc77a50b0
 Node address: 0x562dc77a50b0 | data = 7| next node address = (nil)

 After delete:
 Node address: 0x562dc77a5010 | data = 2| next node address = 0x562dc77a5030
 Node address: 0x562dc77a5030 | data = 3| next node address = 0x562dc77a5050
 Node address: 0x562dc77a5050 | data = 4| next node address = 0x562dc77a5070
 Node address: 0x562dc77a5070 | data = 5| next node address = 0x562dc77a5090
 Node address: 0x562dc77a5090 | data = 6| next node address = 0x562dc77a50b0
 Node address: 0x562dc77a50b0 | data = 7| next node address = (nil)
 */
