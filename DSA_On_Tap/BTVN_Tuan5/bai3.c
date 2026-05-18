#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray (int arr[], int length, int min, int max) {
    for (int i = 0; i<length; i++)
        arr[i] = min + rand()%(max - min + 1);
} 

void bubbleSort(int arr[], int n, int *steps) {
    *steps = 0;
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
    *steps = 0;
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
    *steps = 0;
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
    int n[] = {10,20,50,100};
    int runs = 10000;
    int steps1 = 0;
    int steps2 = 0;
    int steps3 = 0;

    for (int i = 0; i<4; i++) {
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int stepFreqB[10000] = {0};
        int stepFreqS[10000] = {0};
        int stepFreqI[10000] = {0};
        for (int r = 0; r<runs; r++) {
            initializeArray(arr1, n[i], 0, 100);
            copy_array(arr1, arr2, n[i]);
            copy_array(arr1, arr3, n[i]);
            
            bubbleSort(arr1, n[i], &steps1);
            selectionSort(arr2, n[i], &steps2);
            insertionSort(arr3, n[i], &steps3);
            
            stepFreqB[steps1]++;
            stepFreqS[steps2]++;
            stepFreqI[steps3]++;
            
            sum1 += steps1;
            sum2 += steps2;
            sum3 += steps3;
        }
        printf("\nWith n = %d, we have:\n", n[i]);
        printf("Selection sort steps mean is: %f\n",  (float) sum1/runs);
        printf("Bubble sort steps mean is: %f\n", (float) sum2/runs);
        printf("Insertion sort steps mean is: %f\n", (float) sum3/runs);
       
    }
    
    return 0;
}

/*
Ket qua:

With n = 10, we have:
Selection sort steps mean is: 67.295998
Bubble sort steps mean is: 67.760101
Insertion sort steps mean is: 31.296000

With n = 20, we have:
Selection sort steps mean is: 280.090698
Bubble sort steps mean is: 307.763794
Insertion sort steps mean is: 130.907196

With n = 50, we have:
Selection sort steps mean is: 1791.798828
Bubble sort steps mean is: 1630.153442
Insertion sort steps mean is: 376.090790

With n = 100, we have:
Selection sort steps mean is: 7217.831055
Bubble sort steps mean is: 5976.771973
Insertion sort steps mean is: 722.395325

--> Thuat toan Insertion Sort la hieu qua nhat, hieu qua hon khoang 2 den 10 lan cac thuat toan con lai, theo sau do la bubble sort va selection sort
*/