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
} LinkedList;

void init(LinkedList* list) {
    list->head = NULL;
}

//Hàm tạo node mới
Node* makeNode(int data){
    Node* node =  (Node*) malloc(sizeof(Node)); //The (Node*) is optional, C automatically casts to Node*
    node->data = data;
    node->next = NULL;
    return node;
}

//Hàm chèn node mới vào đầu danh sách
void insertHead(int data, LinkedList* list){
    Node* new_node = makeNode(data);
    new_node->next = list->head;
    list->head = new_node;
}

void deleteHead(LinkedList *list, Node *node) {
    if (node == NULL) return;
    Node *temp = node->next;
    free(node);
    list->head = temp;
}

//Hàm in linked list
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}

void insert_anywhere(int data, LinkedList* list, int position) {
    Node *new_node = makeNode(data);
    Node *current_node = list->head;
    for (int i=0; i<position; i++) {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node; // We dont write current_node->next = new_node->next because new_node->next is already set to current_node->next
}


//Hàm main
int main(){
    LinkedList list;
    init(&list);
    //Tạo danh sách tự động
    for(int i = 0; i < 10; i++)
       insertHead(i, &list);
    //In danh sách
    printList(&list);
    return 0;
}
