#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray (int a[], int n, int min, int max) {  
    for (int i = 0; i<n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
} 

int highest_product(int arr[], int length, int *steps, int *assign) {
    int highest_product = 1;
    (*steps) = 0;
    (*assign) = 0;
    for (int i=0; i<length; i++) {
        for (int j=i; j<length; j++) {
            int current_product = arr[i] * arr[j];
            (*steps) ++;
            if (current_product >= highest_product) {
                highest_product = current_product;
                (*assign) ++;
            }
        }
    }
    return highest_product;
}

void time_complexity_experiment() {
    int arr[] = {11,20,43,9,67,4,18,36,52,8};
    int n=10;
    int steps_for_experiment, assign_for_experiment;
    int result = highest_product(arr, n, &steps_for_experiment, &assign_for_experiment);
    printf("The highest product is %d and the steps needed to find it is %d\n", result, steps_for_experiment);
    
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[999];
    int n = 4;
    int runs = 10000;
    int min=1, max =100;
    // Cau 1:
    printf("Experiment for analyzing the time complexity:\n");
    time_complexity_experiment();
    printf("\n");
    // Cau 2:
    int steps;
    int assigns;
    int freqTable[17] = {0};
    int sum_assigns = 0;
    for (int i=0; i<runs; i++) {
        initializeArray(arr, n, min, max);
        highest_product(arr, n, &steps, &assigns);
        freqTable[assigns]++;
        sum_assigns+=assigns;
    }
    printf("With %d runs, we have:\n", runs);
    printf("---Frequency Table:\n");
    for (int i=0; i<17; i++) {
        if (freqTable[i] > 0) {
            printf("%d     |      %d\n", i, freqTable[i]);
        }
    }
    printf("The mean of the number of assignments is: %f", (float) sum_assigns/runs);
    
}

/*
 The highest product is 4489 and the steps needed to find it is 55 --> The time complexity is O(n^2) and the number of steps follow the formula of n(n+1)/2
 With 10000 runs, we have:
 ---Frequency Table:
 1     |      2462
 3     |      4539
 5     |      825
 6     |      1746
 7     |      70
 8     |      58
 9     |      169
 10     |      131
 The mean of the number of assignments is: 3.446500
 */