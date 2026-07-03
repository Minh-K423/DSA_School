#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* next;
} node;

typedef struct ListType {
    node* head;
    node* tail;
} linked_list;


void init_linked_list(linked_list* list) {
    list->head = NULL;
    list->tail = NULL;
}

node *make_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_head(linked_list* list, node* new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

void delete_head(linked_list* list) {
    if (list->head == NULL) {
        free(list->head);
        return;
    }
    node *new_head = list->head->next;
    free(list->head);
    list->head = new_head;
}

void delete_tail(linked_list  *list) {
    if (list->head == NULL) {
        free(list->head);
        return;
    }
    node *current_node = list->head;
    while (current_node->next != list->tail) {
        current_node = current_node->next;
    }
    current_node->next = NULL;
    free(list->tail);
    list->tail = current_node;
}

typedef struct {
    linked_list *list;
    int head;
    int size;
} stack; // Stack, exercise 3.1

void init_stack(stack* s, int length) {
    s->list = malloc(sizeof(linked_list));
    init_linked_list(s->list);
    s->head = -1;
    s->size = length;
}

int is_empty(stack* s) {
    return s->head == -1;
}

int is_full(stack* s) {
    return s->head == s->size - 1;
}

void push(stack* s, int data) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->head++;
    node *new_node = make_node(data);
    insert_head(s->list, new_node);
}

void pop(stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return;
    }
    delete_head(s->list);
    s->head--;
}

void printList(linked_list* list){
    node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n", node->next);
        node = node->next;
    }
    printf("\n");
}

typedef struct {
    linked_list *list;
    int front;
    int rear;
    int size;
} queue;

void init_queue(queue* q, int length) {
    q->list = malloc(sizeof(linked_list));
    init_linked_list(q->list);
    q->front = -1;
    q->rear = 0;
    q->size = length;
}

int queue_empty(queue* q) {
    return q->front == q->rear-1;
}

int queue_full(queue* q) {
    return q->rear == q->size;
}

void enqueue(queue* q, int data) {
    if (queue_full(q)) {
        printf("Queue overflow\n");
        return;
    }
    q->rear++;
    node *new_node = make_node(data);
    insert_head(q->list, new_node);
}

void dequeue(queue* q) {
    if (queue_empty(q)) {
        printf("Queue underflow\n");
        return;
    }
    delete_tail(q->list);
    q->front++;
}


int main() {
    stack s;
    init_stack(&s, 10);

    for (int i=0; i<10; i++) {
        push(&s, i);
    }
    printf("Head element: %d\n", s.list->head->data);
    printf("Stack contents:\n");
    printList(s.list);

    printf("Pop the first 5 elements\n");
    for (int i=0; i<5; i++) {
        pop(&s);
    }
    printf("Head element: %d\n", s.list->head->data);
    printf("Stack contents:\n");
    printList(s.list);

    queue q;
    init_queue(&q, 10);

    for (int i=0; i<10; i++) {
        enqueue(&q, i);
    }
    printf("Rear element: %d\n", q.list->tail->data);
    printf("Front element: %d\n", q.list->head->data);
    printf("Queue contents:\n");
    printList(q.list);

    printf("Dequeue the first 5 elements:\n");
    for (int i=0; i<5; i++) {
        dequeue(&q);
    }
    printf("Rear element: %d\n", q.list->tail->data);
    printf("Front element: %d\n", q.list->head->data);
    printf("Queue contents:\n");
    printList(q.list);

    printf("\n");

    return 0;
}

/*  3.1
    Head element: 9
    Stack contents:
    Node address: 0x56262d42b150 | data = 9| next node address = 0x56262d42b130
    Node address: 0x56262d42b130 | data = 8| next node address = 0x56262d42b110
    Node address: 0x56262d42b110 | data = 7| next node address = 0x56262d42b0f0
    Node address: 0x56262d42b0f0 | data = 6| next node address = 0x56262d42b0d0
    Node address: 0x56262d42b0d0 | data = 5| next node address = 0x56262d42b0b0
    Node address: 0x56262d42b0b0 | data = 4| next node address = 0x56262d42b090
    Node address: 0x56262d42b090 | data = 3| next node address = 0x56262d42b070
    Node address: 0x56262d42b070 | data = 2| next node address = 0x56262d42b050
    Node address: 0x56262d42b050 | data = 1| next node address = 0x56262d42b030
    Node address: 0x56262d42b030 | data = 0| next node address = (nil)

    Pop the first 5 elements
    Head element: 4
    Stack contents:
    Node address: 0x56262d42b0b0 | data = 4| next node address = 0x56262d42b090
    Node address: 0x56262d42b090 | data = 3| next node address = 0x56262d42b070
    Node address: 0x56262d42b070 | data = 2| next node address = 0x56262d42b050
    Node address: 0x56262d42b050 | data = 1| next node address = 0x56262d42b030
    Node address: 0x56262d42b030 | data = 0| next node address = (nil)

    3.2
    Rear element: 0
    Front element: 9
    Queue contents:
    Node address: 0x56262d42b920 | data = 9| next node address = 0x56262d42b900
    Node address: 0x56262d42b900 | data = 8| next node address = 0x56262d42b8e0
    Node address: 0x56262d42b8e0 | data = 7| next node address = 0x56262d42b8c0
    Node address: 0x56262d42b8c0 | data = 6| next node address = 0x56262d42b8a0
    Node address: 0x56262d42b8a0 | data = 5| next node address = 0x56262d42b880
    Node address: 0x56262d42b880 | data = 4| next node address = 0x56262d42b150
    Node address: 0x56262d42b150 | data = 3| next node address = 0x56262d42b130
    Node address: 0x56262d42b130 | data = 2| next node address = 0x56262d42b110
    Node address: 0x56262d42b110 | data = 1| next node address = 0x56262d42b0f0
    Node address: 0x56262d42b0f0 | data = 0| next node address = (nil)

    Dequeue the first 5 elements:
    Rear element: 5
    Front element: 9
    Queue contents:
    Node address: 0x56262d42b920 | data = 9| next node address = 0x56262d42b900
    Node address: 0x56262d42b900 | data = 8| next node address = 0x56262d42b8e0
    Node address: 0x56262d42b8e0 | data = 7| next node address = 0x56262d42b8c0
    Node address: 0x56262d42b8c0 | data = 6| next node address = 0x56262d42b8a0
    Node address: 0x56262d42b8a0 | data = 5| next node address = (nil)
 */
