#include <stdio.h>

#define MAX_LEN 999

typedef struct {
    float x;
    float y;
} coordinations;

void removeCoordinate(coordinations coordinate[], int *length, int position) {
    for (int i = position; i < *length - 1; i++) {
        coordinate[i].x = coordinate[i + 1].x;
        coordinate[i].y = coordinate[i + 1].y;
    }
    (*length)--;
}

int main() {
    coordinations coordinate[MAX_LEN];
    int length;
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%f %f", &coordinate[i].x, &coordinate[i].y);
    }
    
    coordinations removedCoordinated;
    scanf("%f %f", &removedCoordinated.x, &removedCoordinated.y);

    int deleted_indices[MAX_LEN];
    int del_count = 0;

    for (int i = 0; i < length; i++) {
        if (coordinate[i].x == removedCoordinated.x && coordinate[i].y == removedCoordinated.y) {
            deleted_indices[del_count] = i + del_count;
            del_count++;
            removeCoordinate(coordinate, &length, i);
            i--; 
        }
    }
    
    for (int i = 0; i < length; i++) {
        printf("%g %g\n", coordinate[i].x, coordinate[i].y);
    }
    if (del_count > 0) {
        printf("Delete %g %g at ", removedCoordinated.x, removedCoordinated.y);
        for (int i = 0; i < del_count; i++) {
            if (i == 0) {
                printf("%d", deleted_indices[i]);
            } else {
                printf(", %d", deleted_indices[i]); 
            }
        }
        printf("\n");
    } else {
        printf("Can not delete %g %g from the array!\n", removedCoordinated.x, removedCoordinated.y);
    }

    return 0;
}

/*
TEST CASE 1:
3
1.4 2.74
-2.3 9.2
0.5 -0.5
-2.3 9.2
1.4 2.74
0.5 -0.5
Delete -2.3 9.2 at 1

TEST CASE 2:
5
-0.87878 1.274
76.498 -10.938793
8237.20 3873.2
76.34 9.676
8237.20 3873.2
8237.20 3873.2
-0.87878 1.274
76.498 -10.9388
76.34 9.676
Delete 8237.2 3873.2 at 2, 4

TEST CASE 3:
4
1 1
2 2
3 3
4 4
5 5 
1 1
2 2
3 3
4 4
Can not delete 5 5 from the array!
 */