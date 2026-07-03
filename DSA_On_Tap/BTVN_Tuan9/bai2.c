#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* next;
} Node;

typedef struct LinkedListType {
    Node* head;
    Node *tail;
} LinkedList;

void list_init(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

Node *make_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertTail(int data, LinkedList* list) {
    Node *new_node = make_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void insert_node(LinkedList *list, int data) {
    Node *new_node = make_node(data);
    Node *current_node = list->head;

    if (list->head->next == NULL) {
        insertTail(data, list);
        return;
    }

    Node *after_node = current_node->next;

    while (current_node->next != NULL) {
        if (current_node->data >= new_node->data && after_node->data <= new_node->data) {
            new_node->next = current_node->next;
            current_node->next = new_node;
            break;
        } else {
            current_node = current_node->next;
            after_node = current_node->next;
        }
    }
}

void delete_node(LinkedList *list, int value) {
    Node *current_node = list->head;
    Node *prev_node = NULL;
    while (current_node != NULL && current_node->data != value) {
        prev_node=current_node;
        current_node = current_node->next;
    }
    prev_node->next = current_node->next;
    current_node->next = NULL;
    free(current_node);
}

void printList(LinkedList* list){
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
    list_init(&list);
    int array[5] = {0,1,3,4,6}; //Doi voi 2.1, list se la {6,4,3,1,0}
    for (int i=0; i<5; i++) {
        insertTail(array[i], &list);
    }
    insert_node(&list, 5);
    delete_node(&list, 4);
    printList(&list);
    return 0;
}

/* 2.1
 * Node address: 0x55b8e00b0010 | data = 6| next node address = 0x55b8e00b00b0
 Node address: 0x55b8e00b00b0 | data = 5| next node address = 0x55b8e00b0030
 Node address: 0x55b8e00b0030 | data = 4| next node address = 0x55b8e00b0050
 Node address: 0x55b8e00b0050 | data = 3| next node address = 0x55b8e00b0070
 Node address: 0x55b8e00b0070 | data = 1| next node address = 0x55b8e00b0090
 Node address: 0x55b8e00b0090 | data = 0| next node address = (nil)
 */

/*2.2
 * Node address: 0x55adcd2e4010 | data = 0| next node address = 0x55adcd2e4030
Node address: 0x55adcd2e4030 | data = 1| next node address = 0x55adcd2e4050
Node address: 0x55adcd2e4050 | data = 3| next node address = 0x55adcd2e4090
Node address: 0x55adcd2e4090 | data = 6| next node address = (nil) */
