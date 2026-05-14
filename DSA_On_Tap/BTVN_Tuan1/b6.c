#include <stdio.h>

#define MAX_LEN 999

void multipleInsertionArray(float array[], float number[], int *length, int position[], int insertionNum) {
    (*length) += insertionNum;
    for (int i=0; i<insertionNum; i++) {
        int afterPosition = position[i] + i;
        for (int j = *length; j> position[i] + i; j--) {
            array[j] = array[j-1];
        }
        array[afterPosition] = number[i]; 
    }
}

int main() {
    float arr[MAX_LEN], number[MAX_LEN];
    int length, insertionNum, position[MAX_LEN];

    printf("Input the length of the array "); scanf("%d", &length);
    printf("Input the array: ");
    for (int i=0; i<length; i++) {
        scanf("%f", &arr[i]);
    }
    
    printf("Input how many position you want to insert: "); scanf("%d", &insertionNum);
    printf("Insert the info needed: (Number first, index second) ");
    for (int i=0; i<insertionNum; i++) {
        scanf("%f %d", &number[i], &position[i]);
    }

    multipleInsertionArray(arr, number, &length, position, insertionNum);
    for (int i=0; i<length; i++) {
        printf("%f", arr[i]);
    }
    
}