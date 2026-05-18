#include <stdio.h>

void selectionSort(int arr[], int n, int *steps) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            (*steps)++;
            if (arr[j] <= arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void insertionSort(int array[], int n, int *steps) {
    for (int i=1; i<n; i++) {
        int key = array[i];
        int j = i-1;

        while (j >= 0 && array[j] > key) {
            (*steps)++;
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void bubbleSort(int arr[], int n, int *steps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*steps)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr1[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int arr2[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int arr3[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    
    int length = 10;
    int steps1 = 0;
    int steps2 = 0;
    int steps3 = 0;

    selectionSort(arr1, length, &steps1);
    printf("Selection sort steps is: %d\n", steps1);
    bubbleSort(arr2, length, &steps2);
    printf("Bubble sort steps is:%d\n", steps2);
    insertionSort(arr3, length, &steps3);
    printf("Insertion sort steps is:%d\n", steps3);
}

/*
    Selection sort steps is: 45
    Bubble sort steps is:45
    Insertion sort steps is:25
 */