#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"

#define MAX 100

typedef struct NodeType {
    char name;
    struct NodeType *next;
    int status;
    int group;
} node;

typedef struct {
    node *head;
    node *tail;
} linked_list;

void initialize_array(node hotel[][MAX], int preoccupied, int number_of_leaders, int floors, int rooms_per_floor) {
    for (int i=0; i<floors; i++) {
        for (int j=0; j<rooms_per_floor; j++) {
            hotel[i][j].status = 0;
            hotel[i][j].group = -1;
            hotel[i][j].name = '\0';
        }
    }

    int current_preoccupied = 0;
    for (int j=0; j<rooms_per_floor; j++) {
        int status = rand() % 2;
        if (status == 1) {
            current_preoccupied++;
        }
        hotel[0][j].status = status;
        if (current_preoccupied >= rooms_per_floor - number_of_leaders) { //Ensure that there are enough rooms for the leader at ground floor
            break;
        }
    }

    for (int i=1; i<floors; i++) {
        for (int j=0; j<rooms_per_floor; j++) {
            int status = rand() % 2;
            hotel[i][j].status = status;
            if (status == 1) {
                current_preoccupied++;
            }

            if (current_preoccupied == preoccupied) {
                break; //Ensure that there are the exact number of preoccupied rooms
            }
        }
        if (current_preoccupied == preoccupied) {
            break;
        }
    }
}

void initialize_list(linked_list *list) {
    list->head = NULL;
    list->tail = NULL;
}

void insert_at_tail(linked_list *list, node *new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(linked_list* list){
    node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->name));
        printf("Name = %c| ", node->name);
        printf("Group = %d| ", node->group + 1);
        printf("Next node address = %p\n", node->next);
        node = node->next;
    }
    printf("\n");
}

void remove_node(linked_list *list, node *target, node *checked_out_room) {
    if (target == list->head) {
        target->name = list->head->next->name;
        target->status = 1;

        list->head->next->status = 0;
        list->head->next->group = -1;
        checked_out_room = list->head->next;
        target->next = list->head->next->next;

        return;
    }

    node *prev_node = list->head;
    while (prev_node->next != target) {
        prev_node = prev_node->next;
    }

    if (target == list->tail) {
        list->tail = prev_node;
        return;
    }

    prev_node->next = target->next;
    target->next = NULL;
}

void hotel_availability(node hotel[MAX][MAX]) {
    for (int i=0; i<17; i++) {
        for (int j=0; j<12; j++) {
            if (j == 11) {
                printf("%d \n", hotel[i][j].status);
            } else {
                printf("%d ", hotel[i][j].status);
            }
        }
    }
}

void problem_1_fill_up(node hotel[MAX][MAX], char name, int leader, int group, linked_list *list) {
    if (leader == 1) {
        int room = 0 + rand() % (11-0+1);
        while (hotel[0][room].status == 1) {
            room = 0 + rand() % (11-0+1); //Room is already occupied, pick another
        }
        hotel[0][room].name = name;
        hotel[0][room].status = 1;
        hotel[0][room].group = group;
        insert_at_tail(list, &hotel[0][room]);
    } else {
        int floor = 1 + rand() % (16-1+1);
        int room = 0 + rand() % (11-0+1);
        while (hotel[floor][room].status == 1) {
            floor = 1 + rand() % (16-1+1);
            room = 0 + rand() % (11-0+1); //Room is already occupied, pick another
        }
        hotel[floor][room].name = name;
        hotel[floor][room].status = 1;
        hotel[floor][room].group = group;
        insert_at_tail(list, &hotel[floor][room]);
    }
}

void problem_2_check_group(linked_list *list, int n) {
    for (int i=0; i<n; i++) {
        printf("Group %d: \n", i+1);
        print_list(&list[i]);
        printf("\n");
    }
}

void problem_3_fill_back(linked_list *group,node *empty_room, char new_member_name) {
    group->tail->next = empty_room;
    group->tail = empty_room;
    group->tail->name = new_member_name;
    group->tail->status = 1;
    group->tail->group = group->head->group;
}

void problem_5_delete_tail(linked_list *list) {
    while (list->head != NULL) {
        list->head->status = 0;
        list->head->name = '\0';
        list->head->group = -1;
        list->head = list->head->next;
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    node hotel[MAX][MAX];

    int preoccupied;
    printf("Enter the number of preoccupied rooms: "); scanf("%d", &preoccupied);

    int n;
    printf("Enter the number of groups: "); scanf("%d", &n);

    initialize_array(hotel, preoccupied, n, 17, 12);

    hotel_availability(hotel);

    char *groups[] = {
            "ABSEFIKLSWQA",     // Đoàn 1: 12 người
            "TMKLJSAQCS",       // Đoàn 2: 10 người
            "HJSSASMQD",        // Đoàn 3: 9 người
            "SAQDASSAQDSQA",    // Đoàn 4: 13 người
            "QSAQEDFSSASXVBF",  // Đoàn 5: 15 người
            "HAVANTHAOTTHUS",   // Đoàn 6: 14 người
            "PHLAMDSATTHU",     // Đoàn 7: 12 người
            "PPNHUNGSVELEVEN",  // Đoàn 8: 15 người
            "LPTRUONGDS",       // Đoàn 9: 10 người
            "CHGIAOKDLH"        // Đoàn 10: 11 người
    };

    linked_list *leader_room = malloc(n * sizeof(linked_list));
    for (int i=0; i<n; i++) {
        initialize_list(&leader_room[i]);
    }

    for (int i=0; i<n; i++) {
        int j=0;
        while (groups[i][j] != '\0') {
            int leader_status;
            if (j == 0) {
                leader_status = 1;
            } else {
                leader_status = 0;
            }
            problem_1_fill_up(hotel, groups[i][j], leader_status, i, &leader_room[i]);
            j++;
        }
    }

    problem_2_check_group(leader_room, n);

    int checked_out_nums;
    printf("How many people have checked out? ");
    scanf("%d", &checked_out_nums);
    node **checked_out_rooms = malloc(checked_out_nums * sizeof(node*));

    for (int i=0; i<checked_out_nums; i++) {
        int floor, room;
        printf("Enter floor (1-17) and room (1-12) of that person %d: ", i+1);
        scanf("%d %d", &floor, &room);

        checked_out_rooms[i] = &hotel[floor][room];

        //Checking information
        hotel[floor][room].status = 0;
        printf("Checked out customer number %d: %c\n", i+1, hotel[floor][room].name);
        printf("+ Node address: %p\n", &hotel[floor][room]);
        if (checked_out_rooms[i]->group != -1) {
            printf("+ Belong to group %d\n", hotel[floor][room].group);
        } else {
            printf("+ No group\n");
        }
        printf("+ Check out room %d.%d\n", floor, room);

        if (hotel[floor][room].group != -1) {
            remove_node(&leader_room[hotel[floor][room].group], &hotel[floor][room], checked_out_rooms[i]);
        }
    }

    hotel_availability(hotel);

    printf("\n");
    printf("System notice: Some group want to add more people to their group.\n");
    int exceed_status = 0;
    int count = 0;

    while (exceed_status == 0) {
        int update_group;
        printf("Enter group number that wants to add more people: "); scanf("%d", &update_group);
        char new_member_name;
        printf("Enter name of new member: "); scanf(" %c", &new_member_name);
        problem_3_fill_back(&leader_room[update_group-1], checked_out_rooms[count], new_member_name);
        count++;
        if (count == checked_out_nums) {
            exceed_status = 1;
            printf("This is the final person you can add to the hotel.\n");
        }
    }

    hotel_availability(hotel);
    printf("\n");
    problem_2_check_group(leader_room, n);

    int checked_out_groups = 0;
    while (checked_out_groups != -1) {
        printf("Input the group number that wants to check out (0 by default, input -1 to exit): ");
        scanf("%d", &checked_out_groups);
        if (checked_out_groups == -1) {
            break;
        }
        problem_5_delete_tail(&leader_room[checked_out_groups+1]);
        printf("Group %d has been checked out.\n", checked_out_groups);
        printf("Recheck hotel availability.\n");
        hotel_availability(hotel);
    }
}

/*
* Enter the number of preoccupied rooms: 84
Enter the number of groups: 10
0 1 1 0 0 0 0 0 0 0 0 0
1 1 0 1 0 1 0 0 0 1 0 0
1 0 1 0 1 1 1 1 0 0 1 0
1 0 0 1 1 1 0 0 1 1 0 1
0 0 1 0 1 0 0 1 0 1 1 1
0 1 0 0 1 1 1 0 0 1 1 1
0 0 1 1 1 1 1 1 0 0 1 1
0 0 0 0 1 0 1 0 1 0 0 0
1 1 0 1 0 0 0 1 0 0 0 1
1 1 0 1 0 1 1 0 1 1 1 1
1 0 1 0 0 1 0 0 1 1 1 1
1 0 0 1 0 1 0 1 0 0 1 0
1 0 1 1 1 0 0 1 0 1 1 1
0 0 1 1 1 0 1 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
Group 1:
Node address: 0x7ffef8320000 | Name = A| Group = 1| Next node address = 0x7ffef8327050
Node address: 0x7ffef8327050 | Name = B| Group = 1| Next node address = 0x7ffef8324188
Node address: 0x7ffef8324188 | Name = S| Group = 1| Next node address = 0x7ffef8322e98
Node address: 0x7ffef8322e98 | Name = E| Group = 1| Next node address = 0x7ffef8329618
Node address: 0x7ffef8329618 | Name = F| Group = 1| Next node address = 0x7ffef83295b8
Node address: 0x7ffef83295b8 | Name = I| Group = 1| Next node address = 0x7ffef8322df0
Node address: 0x7ffef8322df0 | Name = K| Group = 1| Next node address = 0x7ffef8325ce8
Node address: 0x7ffef8325ce8 | Name = L| Group = 1| Next node address = 0x7ffef8328c88
Node address: 0x7ffef8328c88 | Name = S| Group = 1| Next node address = 0x7ffef83279e0
Node address: 0x7ffef83279e0 | Name = W| Group = 1| Next node address = 0x7ffef8327968
Node address: 0x7ffef8327968 | Name = Q| Group = 1| Next node address = 0x7ffef83282b0
Node address: 0x7ffef83282b0 | Name = A| Group = 1| Next node address = (nil)


Group 2:
Node address: 0x7ffef831ffb8 | Name = T| Group = 2| Next node address = 0x7ffef83211e8
Node address: 0x7ffef83211e8 | Name = M| Group = 2| Next node address = 0x7ffef8324b00
Node address: 0x7ffef8324b00 | Name = K| Group = 2| Next node address = 0x7ffef83282f8
Node address: 0x7ffef83282f8 | Name = L| Group = 2| Next node address = 0x7ffef8322eb0
Node address: 0x7ffef8322eb0 | Name = J| Group = 2| Next node address = 0x7ffef8324158
Node address: 0x7ffef8324158 | Name = S| Group = 2| Next node address = 0x7ffef8321bc0
Node address: 0x7ffef8321bc0 | Name = A| Group = 2| Next node address = 0x7ffef83208d0
Node address: 0x7ffef83208d0 | Name = Q| Group = 2| Next node address = 0x7ffef8328c10
Node address: 0x7ffef8328c10 | Name = C| Group = 2| Next node address = 0x7ffef8324aa0
Node address: 0x7ffef8324aa0 | Name = S| Group = 2| Next node address = (nil)


Group 3:
Node address: 0x7ffef831ffe8 | Name = H| Group = 3| Next node address = 0x7ffef83212a8
Node address: 0x7ffef83212a8 | Name = J| Group = 3| Next node address = 0x7ffef8321b60
Node address: 0x7ffef8321b60 | Name = S| Group = 3| Next node address = 0x7ffef8321b48
Node address: 0x7ffef8321b48 | Name = S| Group = 3| Next node address = 0x7ffef8327008
Node address: 0x7ffef8327008 | Name = A| Group = 3| Next node address = 0x7ffef83295d0
Node address: 0x7ffef83295d0 | Name = S| Group = 3| Next node address = 0x7ffef8328bc8
Node address: 0x7ffef8328bc8 | Name = M| Group = 3| Next node address = 0x7ffef8326690
Node address: 0x7ffef8326690 | Name = Q| Group = 3| Next node address = 0x7ffef83295a0
Node address: 0x7ffef83295a0 | Name = D| Group = 3| Next node address = (nil)


Group 4:
Node address: 0x7ffef831ff70 | Name = S| Group = 4| Next node address = 0x7ffef8328280
Node address: 0x7ffef8328280 | Name = A| Group = 4| Next node address = 0x7ffef8321290
Node address: 0x7ffef8321290 | Name = Q| Group = 4| Next node address = 0x7ffef8326660
Node address: 0x7ffef8326660 | Name = D| Group = 4| Next node address = 0x7ffef8325d30
Node address: 0x7ffef8325d30 | Name = A| Group = 4| Next node address = 0x7ffef8328c40
Node address: 0x7ffef8328c40 | Name = S| Group = 4| Next node address = 0x7ffef8322550
Node address: 0x7ffef8322550 | Name = S| Group = 4| Next node address = 0x7ffef83278f0
Node address: 0x7ffef83278f0 | Name = A| Group = 4| Next node address = 0x7ffef83240f8
Node address: 0x7ffef83240f8 | Name = Q| Group = 4| Next node address = 0x7ffef8325d60
Node address: 0x7ffef8325d60 | Name = D| Group = 4| Next node address = 0x7ffef8323750
Node address: 0x7ffef8323750 | Name = S| Group = 4| Next node address = 0x7ffef8324a70
Node address: 0x7ffef8324a70 | Name = Q| Group = 4| Next node address = 0x7ffef83212d8
Node address: 0x7ffef83212d8 | Name = A| Group = 4| Next node address = (nil)


Group 5:
Node address: 0x7ffef831ff10 | Name = Q| Group = 5| Next node address = 0x7ffef83295e8
Node address: 0x7ffef83295e8 | Name = S| Group = 5| Next node address = 0x7ffef8322490
Node address: 0x7ffef8322490 | Name = A| Group = 5| Next node address = 0x7ffef8328358
Node address: 0x7ffef8328358 | Name = Q| Group = 5| Next node address = 0x7ffef8329540
Node address: 0x7ffef8329540 | Name = E| Group = 5| Next node address = 0x7ffef8326fa8
Node address: 0x7ffef8326fa8 | Name = D| Group = 5| Next node address = 0x7ffef83241b8
Node address: 0x7ffef83241b8 | Name = F| Group = 5| Next node address = 0x7ffef83208a0
Node address: 0x7ffef83208a0 | Name = S| Group = 5| Next node address = 0x7ffef8326708
Node address: 0x7ffef8326708 | Name = S| Group = 5| Next node address = 0x7ffef8329570
Node address: 0x7ffef8329570 | Name = A| Group = 5| Next node address = 0x7ffef83282c8
Node address: 0x7ffef83282c8 | Name = S| Group = 5| Next node address = 0x7ffef8328cb8
Node address: 0x7ffef8328cb8 | Name = X| Group = 5| Next node address = 0x7ffef8325418
Node address: 0x7ffef8325418 | Name = V| Group = 5| Next node address = 0x7ffef8325d18
Node address: 0x7ffef8325d18 | Name = B| Group = 5| Next node address = 0x7ffef8329588
Node address: 0x7ffef8329588 | Name = F| Group = 5| Next node address = (nil)


Group 6:
Node address: 0x7ffef831ff58 | Name = H| Group = 6| Next node address = 0x7ffef8327020
Node address: 0x7ffef8327020 | Name = A| Group = 6| Next node address = 0x7ffef8320930
Node address: 0x7ffef8320930 | Name = V| Group = 6| Next node address = 0x7ffef8328250
Node address: 0x7ffef8328250 | Name = A| Group = 6| Next node address = 0x7ffef83266f0
Node address: 0x7ffef83266f0 | Name = N| Group = 6| Next node address = 0x7ffef8328c28
Node address: 0x7ffef8328c28 | Name = T| Group = 6| Next node address = 0x7ffef8327908
Node address: 0x7ffef8327908 | Name = H| Group = 6| Next node address = 0x7ffef8328bf8
Node address: 0x7ffef8328bf8 | Name = A| Group = 6| Next node address = 0x7ffef83224d8
Node address: 0x7ffef83224d8 | Name = O| Group = 6| Next node address = 0x7ffef8325d78
Node address: 0x7ffef8325d78 | Name = T| Group = 6| Next node address = 0x7ffef83279f8
Node address: 0x7ffef83279f8 | Name = T| Group = 6| Next node address = 0x7ffef83241a0
Node address: 0x7ffef83241a0 | Name = H| Group = 6| Next node address = 0x7ffef8324128
Node address: 0x7ffef8324128 | Name = U| Group = 6| Next node address = 0x7ffef8328298
Node address: 0x7ffef8328298 | Name = S| Group = 6| Next node address = (nil)


Group 7:
Node address: 0x7ffef831ffa0 | Name = P| Group = 7| Next node address = 0x7ffef83253d0
Node address: 0x7ffef83253d0 | Name = H| Group = 7| Next node address = 0x7ffef8320900
Node address: 0x7ffef8320900 | Name = L| Group = 7| Next node address = 0x7ffef8322508
Node address: 0x7ffef8322508 | Name = A| Group = 7| Next node address = 0x7ffef8329510
Node address: 0x7ffef8329510 | Name = M| Group = 7| Next node address = 0x7ffef8320978
Node address: 0x7ffef8320978 | Name = D| Group = 7| Next node address = 0x7ffef8323768
Node address: 0x7ffef8323768 | Name = S| Group = 7| Next node address = 0x7ffef83282e0
Node address: 0x7ffef83282e0 | Name = A| Group = 7| Next node address = 0x7ffef8328328
Node address: 0x7ffef8328328 | Name = T| Group = 7| Next node address = 0x7ffef8322e20
Node address: 0x7ffef8322e20 | Name = T| Group = 7| Next node address = 0x7ffef8324a88
Node address: 0x7ffef8324a88 | Name = H| Group = 7| Next node address = 0x7ffef83240e0
Node address: 0x7ffef83240e0 | Name = U| Group = 7| Next node address = (nil)


Group 8:
Node address: 0x7ffef831ff88 | Name = P| Group = 8| Next node address = 0x7ffef8326648
Node address: 0x7ffef8326648 | Name = P| Group = 8| Next node address = 0x7ffef83279b0
Node address: 0x7ffef83279b0 | Name = N| Group = 8| Next node address = 0x7ffef8329600
Node address: 0x7ffef8329600 | Name = H| Group = 8| Next node address = 0x7ffef83240c8
Node address: 0x7ffef83240c8 | Name = U| Group = 8| Next node address = 0x7ffef8320918
Node address: 0x7ffef8320918 | Name = N| Group = 8| Next node address = 0x7ffef8321c20
Node address: 0x7ffef8321c20 | Name = G| Group = 8| Next node address = 0x7ffef8328310
Node address: 0x7ffef8328310 | Name = S| Group = 8| Next node address = 0x7ffef8323810
Node address: 0x7ffef8323810 | Name = V| Group = 8| Next node address = 0x7ffef83266c0
Node address: 0x7ffef83266c0 | Name = E| Group = 8| Next node address = 0x7ffef83224a8
Node address: 0x7ffef83224a8 | Name = L| Group = 8| Next node address = 0x7ffef8326738
Node address: 0x7ffef8326738 | Name = E| Group = 8| Next node address = 0x7ffef8324ad0
Node address: 0x7ffef8324ad0 | Name = V| Group = 8| Next node address = 0x7ffef8328ca0
Node address: 0x7ffef8328ca0 | Name = E| Group = 8| Next node address = 0x7ffef8321218
Node address: 0x7ffef8321218 | Name = N| Group = 8| Next node address = (nil)


Group 9:
Node address: 0x7ffef831ffd0 | Name = L| Group = 9| Next node address = 0x7ffef8329528
Node address: 0x7ffef8329528 | Name = P| Group = 9| Next node address = 0x7ffef8322e38
Node address: 0x7ffef8322e38 | Name = T| Group = 9| Next node address = 0x7ffef8324ae8
Node address: 0x7ffef8324ae8 | Name = R| Group = 9| Next node address = 0x7ffef8321bd8
Node address: 0x7ffef8321bd8 | Name = U| Group = 9| Next node address = 0x7ffef8323828
Node address: 0x7ffef8323828 | Name = O| Group = 9| Next node address = 0x7ffef8327998
Node address: 0x7ffef8327998 | Name = N| Group = 9| Next node address = 0x7ffef8328268
Node address: 0x7ffef8328268 | Name = G| Group = 9| Next node address = 0x7ffef8320960
Node address: 0x7ffef8320960 | Name = D| Group = 9| Next node address = 0x7ffef8322520
Node address: 0x7ffef8322520 | Name = S| Group = 9| Next node address = (nil)


Group 10:
Node address: 0x7ffef8320018 | Name = C| Group = 10| Next node address = 0x7ffef8329558
Node address: 0x7ffef8329558 | Name = H| Group = 10| Next node address = 0x7ffef83240b0
Node address: 0x7ffef83240b0 | Name = G| Group = 10| Next node address = 0x7ffef8328c58
Node address: 0x7ffef8328c58 | Name = I| Group = 10| Next node address = 0x7ffef8328bb0
Node address: 0x7ffef8328bb0 | Name = A| Group = 10| Next node address = 0x7ffef8324a40
Node address: 0x7ffef8324a40 | Name = O| Group = 10| Next node address = 0x7ffef8328340
Node address: 0x7ffef8328340 | Name = K| Group = 10| Next node address = 0x7ffef83253a0
Node address: 0x7ffef83253a0 | Name = D| Group = 10| Next node address = 0x7ffef8328c70
Node address: 0x7ffef8328c70 | Name = L| Group = 10| Next node address = 0x7ffef8328be0
Node address: 0x7ffef8328be0 | Name = H| Group = 10| Next node address = (nil)


How many people have checked out? 3
Enter floor (1-17) and room (1-12) of that person 1: 12 4
Checked out customer number 1:
+ Node address: 0x7ffef8326ff0
+ No group
+ Check out room 12.4
Enter floor (1-17) and room (1-12) of that person 2: 11 3
Checked out customer number 2:
+ Node address: 0x7ffef8326678
+ No group
+ Check out room 11.3
Enter floor (1-17) and room (1-12) of that person 3: 15 6
Checked out customer number 3: S
+ Node address: 0x7ffef8328c40
+ Belong to group 3
+ Check out room 15.6
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1

System notice: Some group want to add more people to their group.
Enter group number that wants to add more people: 3
Enter name of new member: A
Enter group number that wants to add more people: 5
Enter name of new member: B
Enter group number that wants to add more people: 7
Enter name of new member: C
This is the final person you can add to the hotel.
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1

Group 1:
Node address: 0x7ffef8320000 | Name = A| Group = 1| Next node address = 0x7ffef8327050
Node address: 0x7ffef8327050 | Name = B| Group = 1| Next node address = 0x7ffef8324188
Node address: 0x7ffef8324188 | Name = S| Group = 1| Next node address = 0x7ffef8322e98
Node address: 0x7ffef8322e98 | Name = E| Group = 1| Next node address = 0x7ffef8329618
Node address: 0x7ffef8329618 | Name = F| Group = 1| Next node address = 0x7ffef83295b8
Node address: 0x7ffef83295b8 | Name = I| Group = 1| Next node address = 0x7ffef8322df0
Node address: 0x7ffef8322df0 | Name = K| Group = 1| Next node address = 0x7ffef8325ce8
Node address: 0x7ffef8325ce8 | Name = L| Group = 1| Next node address = 0x7ffef8328c88
Node address: 0x7ffef8328c88 | Name = S| Group = 1| Next node address = 0x7ffef83279e0
Node address: 0x7ffef83279e0 | Name = W| Group = 1| Next node address = 0x7ffef8327968
Node address: 0x7ffef8327968 | Name = Q| Group = 1| Next node address = 0x7ffef83282b0
Node address: 0x7ffef83282b0 | Name = A| Group = 1| Next node address = (nil)


Group 2:
Node address: 0x7ffef831ffb8 | Name = T| Group = 2| Next node address = 0x7ffef83211e8
Node address: 0x7ffef83211e8 | Name = M| Group = 2| Next node address = 0x7ffef8324b00
Node address: 0x7ffef8324b00 | Name = K| Group = 2| Next node address = 0x7ffef83282f8
Node address: 0x7ffef83282f8 | Name = L| Group = 2| Next node address = 0x7ffef8322eb0
Node address: 0x7ffef8322eb0 | Name = J| Group = 2| Next node address = 0x7ffef8324158
Node address: 0x7ffef8324158 | Name = S| Group = 2| Next node address = 0x7ffef8321bc0
Node address: 0x7ffef8321bc0 | Name = A| Group = 2| Next node address = 0x7ffef83208d0
Node address: 0x7ffef83208d0 | Name = Q| Group = 2| Next node address = 0x7ffef8328c10
Node address: 0x7ffef8328c10 | Name = C| Group = 2| Next node address = 0x7ffef8324aa0
Node address: 0x7ffef8324aa0 | Name = S| Group = 2| Next node address = (nil)


Group 3:
Node address: 0x7ffef831ffe8 | Name = H| Group = 3| Next node address = 0x7ffef83212a8
Node address: 0x7ffef83212a8 | Name = J| Group = 3| Next node address = 0x7ffef8321b60
Node address: 0x7ffef8321b60 | Name = S| Group = 3| Next node address = 0x7ffef8321b48
Node address: 0x7ffef8321b48 | Name = S| Group = 3| Next node address = 0x7ffef8327008
Node address: 0x7ffef8327008 | Name = A| Group = 3| Next node address = 0x7ffef83295d0
Node address: 0x7ffef83295d0 | Name = S| Group = 3| Next node address = 0x7ffef8328bc8
Node address: 0x7ffef8328bc8 | Name = M| Group = 3| Next node address = 0x7ffef8326690
Node address: 0x7ffef8326690 | Name = Q| Group = 3| Next node address = 0x7ffef83295a0
Node address: 0x7ffef83295a0 | Name = D| Group = 3| Next node address = 0x7ffef8326ff0
Node address: 0x7ffef8326ff0 | Name = A| Group = 3| Next node address = (nil)


Group 4:
Node address: 0x7ffef831ff70 | Name = S| Group = 4| Next node address = 0x7ffef8328280
Node address: 0x7ffef8328280 | Name = A| Group = 4| Next node address = 0x7ffef8321290
Node address: 0x7ffef8321290 | Name = Q| Group = 4| Next node address = 0x7ffef8326660
Node address: 0x7ffef8326660 | Name = D| Group = 4| Next node address = 0x7ffef8325d30
Node address: 0x7ffef8325d30 | Name = A| Group = 4| Next node address = 0x7ffef8322550
Node address: 0x7ffef8322550 | Name = S| Group = 4| Next node address = 0x7ffef83278f0
Node address: 0x7ffef83278f0 | Name = A| Group = 4| Next node address = 0x7ffef83240f8
Node address: 0x7ffef83240f8 | Name = Q| Group = 4| Next node address = 0x7ffef8325d60
Node address: 0x7ffef8325d60 | Name = D| Group = 4| Next node address = 0x7ffef8323750
Node address: 0x7ffef8323750 | Name = S| Group = 4| Next node address = 0x7ffef8324a70
Node address: 0x7ffef8324a70 | Name = Q| Group = 4| Next node address = 0x7ffef83212d8
Node address: 0x7ffef83212d8 | Name = A| Group = 4| Next node address = (nil)


Group 5:
Node address: 0x7ffef831ff10 | Name = Q| Group = 5| Next node address = 0x7ffef83295e8
Node address: 0x7ffef83295e8 | Name = S| Group = 5| Next node address = 0x7ffef8322490
Node address: 0x7ffef8322490 | Name = A| Group = 5| Next node address = 0x7ffef8328358
Node address: 0x7ffef8328358 | Name = Q| Group = 5| Next node address = 0x7ffef8329540
Node address: 0x7ffef8329540 | Name = E| Group = 5| Next node address = 0x7ffef8326fa8
Node address: 0x7ffef8326fa8 | Name = D| Group = 5| Next node address = 0x7ffef83241b8
Node address: 0x7ffef83241b8 | Name = F| Group = 5| Next node address = 0x7ffef83208a0
Node address: 0x7ffef83208a0 | Name = S| Group = 5| Next node address = 0x7ffef8326708
Node address: 0x7ffef8326708 | Name = S| Group = 5| Next node address = 0x7ffef8329570
Node address: 0x7ffef8329570 | Name = A| Group = 5| Next node address = 0x7ffef83282c8
Node address: 0x7ffef83282c8 | Name = S| Group = 5| Next node address = 0x7ffef8328cb8
Node address: 0x7ffef8328cb8 | Name = X| Group = 5| Next node address = 0x7ffef8325418
Node address: 0x7ffef8325418 | Name = V| Group = 5| Next node address = 0x7ffef8325d18
Node address: 0x7ffef8325d18 | Name = B| Group = 5| Next node address = 0x7ffef8329588
Node address: 0x7ffef8329588 | Name = F| Group = 5| Next node address = 0x7ffef8326678
Node address: 0x7ffef8326678 | Name = B| Group = 5| Next node address = (nil)


Group 6:
Node address: 0x7ffef831ff58 | Name = H| Group = 6| Next node address = 0x7ffef8327020
Node address: 0x7ffef8327020 | Name = A| Group = 6| Next node address = 0x7ffef8320930
Node address: 0x7ffef8320930 | Name = V| Group = 6| Next node address = 0x7ffef8328250
Node address: 0x7ffef8328250 | Name = A| Group = 6| Next node address = 0x7ffef83266f0
Node address: 0x7ffef83266f0 | Name = N| Group = 6| Next node address = 0x7ffef8328c28
Node address: 0x7ffef8328c28 | Name = T| Group = 6| Next node address = 0x7ffef8327908
Node address: 0x7ffef8327908 | Name = H| Group = 6| Next node address = 0x7ffef8328bf8
Node address: 0x7ffef8328bf8 | Name = A| Group = 6| Next node address = 0x7ffef83224d8
Node address: 0x7ffef83224d8 | Name = O| Group = 6| Next node address = 0x7ffef8325d78
Node address: 0x7ffef8325d78 | Name = T| Group = 6| Next node address = 0x7ffef83279f8
Node address: 0x7ffef83279f8 | Name = T| Group = 6| Next node address = 0x7ffef83241a0
Node address: 0x7ffef83241a0 | Name = H| Group = 6| Next node address = 0x7ffef8324128
Node address: 0x7ffef8324128 | Name = U| Group = 6| Next node address = 0x7ffef8328298
Node address: 0x7ffef8328298 | Name = S| Group = 6| Next node address = (nil)


Group 7:
Node address: 0x7ffef831ffa0 | Name = P| Group = 7| Next node address = 0x7ffef83253d0
Node address: 0x7ffef83253d0 | Name = H| Group = 7| Next node address = 0x7ffef8320900
Node address: 0x7ffef8320900 | Name = L| Group = 7| Next node address = 0x7ffef8322508
Node address: 0x7ffef8322508 | Name = A| Group = 7| Next node address = 0x7ffef8329510
Node address: 0x7ffef8329510 | Name = M| Group = 7| Next node address = 0x7ffef8320978
Node address: 0x7ffef8320978 | Name = D| Group = 7| Next node address = 0x7ffef8323768
Node address: 0x7ffef8323768 | Name = S| Group = 7| Next node address = 0x7ffef83282e0
Node address: 0x7ffef83282e0 | Name = A| Group = 7| Next node address = 0x7ffef8328328
Node address: 0x7ffef8328328 | Name = T| Group = 7| Next node address = 0x7ffef8322e20
Node address: 0x7ffef8322e20 | Name = T| Group = 7| Next node address = 0x7ffef8324a88
Node address: 0x7ffef8324a88 | Name = H| Group = 7| Next node address = 0x7ffef83240e0
Node address: 0x7ffef83240e0 | Name = U| Group = 7| Next node address = 0x7ffef8328c40
Node address: 0x7ffef8328c40 | Name = C| Group = 7| Next node address = (nil)


Group 8:
Node address: 0x7ffef831ff88 | Name = P| Group = 8| Next node address = 0x7ffef8326648
Node address: 0x7ffef8326648 | Name = P| Group = 8| Next node address = 0x7ffef83279b0
Node address: 0x7ffef83279b0 | Name = N| Group = 8| Next node address = 0x7ffef8329600
Node address: 0x7ffef8329600 | Name = H| Group = 8| Next node address = 0x7ffef83240c8
Node address: 0x7ffef83240c8 | Name = U| Group = 8| Next node address = 0x7ffef8320918
Node address: 0x7ffef8320918 | Name = N| Group = 8| Next node address = 0x7ffef8321c20
Node address: 0x7ffef8321c20 | Name = G| Group = 8| Next node address = 0x7ffef8328310
Node address: 0x7ffef8328310 | Name = S| Group = 8| Next node address = 0x7ffef8323810
Node address: 0x7ffef8323810 | Name = V| Group = 8| Next node address = 0x7ffef83266c0
Node address: 0x7ffef83266c0 | Name = E| Group = 8| Next node address = 0x7ffef83224a8
Node address: 0x7ffef83224a8 | Name = L| Group = 8| Next node address = 0x7ffef8326738
Node address: 0x7ffef8326738 | Name = E| Group = 8| Next node address = 0x7ffef8324ad0
Node address: 0x7ffef8324ad0 | Name = V| Group = 8| Next node address = 0x7ffef8328ca0
Node address: 0x7ffef8328ca0 | Name = E| Group = 8| Next node address = 0x7ffef8321218
Node address: 0x7ffef8321218 | Name = N| Group = 8| Next node address = (nil)


Group 9:
Node address: 0x7ffef831ffd0 | Name = L| Group = 9| Next node address = 0x7ffef8329528
Node address: 0x7ffef8329528 | Name = P| Group = 9| Next node address = 0x7ffef8322e38
Node address: 0x7ffef8322e38 | Name = T| Group = 9| Next node address = 0x7ffef8324ae8
Node address: 0x7ffef8324ae8 | Name = R| Group = 9| Next node address = 0x7ffef8321bd8
Node address: 0x7ffef8321bd8 | Name = U| Group = 9| Next node address = 0x7ffef8323828
Node address: 0x7ffef8323828 | Name = O| Group = 9| Next node address = 0x7ffef8327998
Node address: 0x7ffef8327998 | Name = N| Group = 9| Next node address = 0x7ffef8328268
Node address: 0x7ffef8328268 | Name = G| Group = 9| Next node address = 0x7ffef8320960
Node address: 0x7ffef8320960 | Name = D| Group = 9| Next node address = 0x7ffef8322520
Node address: 0x7ffef8322520 | Name = S| Group = 9| Next node address = (nil)


Group 10:
Node address: 0x7ffef8320018 | Name = C| Group = 10| Next node address = 0x7ffef8329558
Node address: 0x7ffef8329558 | Name = H| Group = 10| Next node address = 0x7ffef83240b0
Node address: 0x7ffef83240b0 | Name = G| Group = 10| Next node address = 0x7ffef8328c58
Node address: 0x7ffef8328c58 | Name = I| Group = 10| Next node address = 0x7ffef8328bb0
Node address: 0x7ffef8328bb0 | Name = A| Group = 10| Next node address = 0x7ffef8324a40
Node address: 0x7ffef8324a40 | Name = O| Group = 10| Next node address = 0x7ffef8328340
Node address: 0x7ffef8328340 | Name = K| Group = 10| Next node address = 0x7ffef83253a0
Node address: 0x7ffef83253a0 | Name = D| Group = 10| Next node address = 0x7ffef8328c70
Node address: 0x7ffef8328c70 | Name = L| Group = 10| Next node address = 0x7ffef8328be0
Node address: 0x7ffef8328be0 | Name = H| Group = 10| Next node address = (nil)


Input the group number that wants to check out (0 by default, input -1 to exit): 7
Group 7 has been checked out.
Recheck hotel availability.
1 1 1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 0 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1
Input the group number that wants to check out (0 by default, input -1 to exit): 2
Group 2 has been checked out.
Recheck hotel availability.
1 1 1 1 0 1 1 1 0 1 1 1
1 1 1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 0 1 0 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 1 1 0 1 1
1 1 1 0 1 1 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 0 1 1 1 1
1 0 0 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1
Input the group number that wants to check out (0 by default, input -1 to exit): -1
 */
