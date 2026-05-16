#include <stdio.h>

void insertOrderedArray(int *n, float array[], float value) {
    int i;
    for (i = *n - 1; i >= 0 && array[i] > value; i--) {
        array[i + 1] = array[i];
    }
    array[i + 1] = value;
    (*n)++; 
}

int orderedLinearSearch(int n, float array[], float value) {
    for (int i = 0; i < n; i++) {
        if (array[i] == value) {
            return i; 
        }
    }
    return -1;
}

int binarySearch(int n, float array[], float value) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        
        if (array[mid] < value) {
            left = mid + 1; 
        } else if (array[mid] > value) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1; 
}


int main() {
    // Bai 1:
    float arr1[100];
    int n1;
    printf("Input the length of the array: "); scanf("%d", &n1);
    printf("Input the array in order: ");
    for (int i=0; i<n1; i++) {
        scanf("%f", &arr1[i]);
    }
    float value1;
    printf("Tell me the value you want to insert: "); scanf("%f", &value1);
    insertOrderedArray(&n1, arr1, value1);

    printf("The array after inserting: ");
    for (int i=0; i<n1; i++) {
        printf("%f", arr1[i]);
    }

    // Bai 2:
    float arr2[100];
    int n2;
    printf("Input the length of the array: "); scanf("%d", &n2);
    printf("Input the array in order: ");
    for (int i=0; i<n2; i++) {
        scanf("%f", &arr2[i]);
    }
    float value2;
    printf("Tell me the value you want to find: "); scanf("%f", &value2);
    int result_index = orderedLinearSearch(n2, arr2, value2);
    printf("It's in index %d", result_index);

    // Bai 3:
    float arr3[100];
    int n3;
    printf("Input the length of the array: "); scanf("%d", &n3);
    printf("Input the array in order: ");
    for (int i=0; i<n3; i++) {
        scanf("%f", &arr3[i]);
    }
    float value3;
    printf("Tell me the value you want to find: "); scanf("%f", &value3);
    int result_index_binary = binarySearch(n3, arr3, value3); 
    printf("It's in index %d", result_index_binary);




}