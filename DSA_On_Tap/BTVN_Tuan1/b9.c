#include <stdio.h>

#define MAX_LEN 999

typedef struct {
    float x;
    float y;
} coordinations ;

int searchCoordinate(coordinations coordinate1[], coordinations coordinate2, int length) {
    for (int i=0; i<length; i++) {
        if (coordinate1[i].x == coordinate2.x && coordinate1[i].y == coordinate2.y) {
            return i;
        }
    }
    return -1;
}

void removeCoordinate(coordinations coordinate[], int *length, int position) {
    for (int i=position; i<*length-1; i++) {
        coordinate[i].x = coordinate[i+1].x;
        coordinate[i].y = coordinate[i+1].y;
    }
    (*length)--;
    coordinate[*length].x = 0;
    coordinate[*length].y = 0;

 
}

int main() {
    coordinations coordinate[MAX_LEN];
    int length;

    printf("Input the length of the list of coordinates: "); scanf("%d", &length);
    for (int i=0; i<length; i++) {
        printf("Input coordinate x and y of coordinate %d: ", i); scanf("%f %f", &coordinate[i].x, &coordinate[i].y);
    }
    coordinations removedCoordinated;
    printf("Input the x and y of the coordinate you want to delete"); scanf("%f %f", &removedCoordinated.x, &removedCoordinated.y);

    int searchResult = searchCoordinate(coordinate, removedCoordinated, length);

    if (searchResult != -1) {
        removeCoordinate(coordinate, &length, searchResult);
        printf("Delete %f %f at %d\n", removedCoordinated.x, removedCoordinated.y, searchResult);
        printf("The list after removal:\n");
        for (int i=0; i<length; i++) {
            printf("%f %f\n", coordinate[i].x, coordinate[i].y);
        }
    } else {
        printf("Not found! Can't delete!\n");
    }
}