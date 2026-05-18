#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray (float a[], int n, int min, int max) {  
    for (int i = 0; i<n; i++) {
        a[i] = min + (float) rand() / (float) RAND_MAX * (max - min);
    }
} 

int minIndex(float arr[], int n, int *comps) {
    float min_value = arr[0];
    int min_index = 0;
    *comps = 0;
    for (int i=1; i<n; i++) {
        (*comps)++;
        if (arr[i] < min_value) {
            min_value = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    
    float arr[11];
    int n = 10;
    int runs[] = {100, 1000};
    int comps;

    for (int i=0; i<2; i++) {
        int freqTable[11] = {0};
        int sumComps  = 0;
        for (int j=0; j<runs[i]; j++) {
            initializeArray(arr, n, -2*n, 2*n);
            minIndex(arr, n, &comps);
            freqTable[comps]++;
            sumComps+=comps;
        }
        printf("With %d runs, we have:\n", runs[i]);
        printf("--Frequency Table--\n");
        for (int k=0; k<11;k++) {
            printf("%d  |   %d\n", k, freqTable[k]);
        }
        printf("--The mean of comps is: %f\n", (float) sumComps/runs[i]);
    }
}

/*
    With 100 runs, we have:
    --Frequency Table--
    0  |   0
    1  |   0
    2  |   0
    3  |   0
    4  |   0
    5  |   0
    6  |   0
    7  |   0
    8  |   0
    9  |   100
    10  |   0
    --The mean of comps is: 9.000000
    With 1000 runs, we have:
    --Frequency Table--
    0  |   0
    1  |   0
    2  |   0
    3  |   0
    4  |   0
    5  |   0
    6  |   0
    7  |   0
    8  |   0
    9  |   1000
    10  |   0
    --The mean of comps is: 9.000000
 */