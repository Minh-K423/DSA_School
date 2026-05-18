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
        printf("%f ", arr[i]);
    }
    
}

/*
TEST CASE 1:
Input the length of the array 5
Input the array: 2.2 -3.0 19.12 -10.22 9.0
Input how many position you want to insert: 3
Insert the info needed: (Number first, index second) 3.0 1
-2.5 3
0.0 4
2.200000 3.000000 -3.000000 19.120001 -2.500000 -10.220000 0.000000 9.000000

TEST CASE 2:
Input the length of the array 10
Input the array: 0.2 0.3 0.5 0.7 0.8 1.0 1.2 1.3 1.4 1.6
Input how many position you want to insert: 7
Insert the info needed: (Number first, index second) 0.1 0
0.4 2
0.6 3
0.9 5
1.1 6
1.5 9
1.7 10
0.100000 0.200000 0.300000 0.400000 0.500000 0.600000 0.700000 0.800000 0.900000 1.000000 1.100000 1.200000 1.300000 1.400000 1.500000 1.600000 1.700000
 */