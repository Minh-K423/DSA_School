#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray (int arr[], int length, int min, int max) {
    for (int i = 0; i<length; i++)
        arr[i] = min + rand()%(max - min + 1);
} 

void bubbleSort(int arr[], int n, int *steps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*steps)++;
            if (arr[j] > arr[j + 1]) {
                (*steps)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int n, int *steps) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            (*steps)++;
            if (arr[j] <= arr[i]) {
                (*steps)++;
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void insertionSort(int array[], int n, int *steps) {
    for (int i=1; i<n; i++) {
        (*steps)++;
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

void copy_array(int arr1[], int arr2[], int length) {
    for (int i = 0; i<length; i++) {
        arr2[i] = arr1[i];
    }
}


int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int arr1[10];
    int arr2[10];
    int arr3[10];
    int n = 10;
    initializeArray(arr1, n, 0, 100);
    copy_array(arr1, arr2, n);
    copy_array(arr1, arr3, n);
    
    int steps1 = 0;
    int steps2 = 0;
    int steps3 = 0;
    bubbleSort(arr1, n, &steps1);
    selectionSort(arr2, n, &steps2);
    insertionSort(arr3, n, &steps3);

    printf("Selection sort steps is: %d\n", steps1);
    printf("Bubble sort steps is: %d\n", steps2);
    printf("Insertion sort steps is: %d\n", steps3);
    
    return 0;
}


/*
    Selection sort steps is: 64
    Bubble sort steps is: 64
    Insertion sort steps is: 28

    --> Insertion Sort la thuat toan hieu qua nhat trong khi do doi voi bubble sort va insertion sort lai ton gan gap 3 lan luong steps. Do ban 
   Do hien tai ham Insertion Sort da duoc chinh sua va chay bang while,thay vi chay double loop nhu truoc kia 
 */