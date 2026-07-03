#include <stdio.h>
#include <stdlib.h>

//Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
} Node;

//Định nghĩa Linked list
typedef struct LinkedListType {
    Node* head;
    Node *tail;
} LinkedList;

void init(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

//Hàm tạo node mới
Node* makeNode(int data){
    Node* node =  (Node*) malloc(sizeof(Node)); //The (Node*) is optional, C automatically casts to Node*
    node->data = data;
    node->next = NULL;
    return node;
}

//Hàm in linked list
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

void insert_anywhere(int data, LinkedList* list, int position) {
    Node *new_node = makeNode(data);
    if (position == 1) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

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


void insertTail(int data, LinkedList* list) {
    Node *new_node = makeNode(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

//Hàm main
int main(){
    LinkedList list;
    init(&list);
    int array[6] = {2,3,4,5,6,7};
    for(int i = 0; i < 6; i++) {
        insertTail(array[i], &list);
    }
    insert_anywhere(1, &list, 1);
    printList(&list);
    return 0;
}

/*
 * 1.1
 Node address: 0x55c0b40a6010 | data = 2| next node address = 0x55c0b40a60d0
 Node address: 0x55c0b40a60d0 | data = 1| next node address = 0x55c0b40a6030
 Node address: 0x55c0b40a6030 | data = 3| next node address = 0x55c0b40a6050
 Node address: 0x55c0b40a6050 | data = 4| next node address = 0x55c0b40a6070
 Node address: 0x55c0b40a6070 | data = 5| next node address = 0x55c0b40a6090
 Node address: 0x55c0b40a6090 | data = 6| next node address = 0x55c0b40a60b0
 Node address: 0x55c0b40a60b0 | data = 7| next node address = (nil)
 * 1.2
 Node address: 0x557f17376010 | data = 2| next node address = 0x557f17376050
 Node address: 0x557f17376050 | data = 4| next node address = 0x557f17376070
 Node address: 0x557f17376070 | data = 5| next node address = 0x557f17376090
 Node address: 0x557f17376090 | data = 6| next node address = 0x557f173760b0
 Node address: 0x557f173760b0 | data = 7| next node address = (nil)
 */
