#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 999

void initializeArray (int a[], int n, int min, int max) {  
    for (int i = 0; i<n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
} 

int sum_negative(int a[], int n, int *assign) {
    int sum = 0;
    *assign = 1; // sum = 0 means 1 assignment already
    
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            sum += a[i]; 
            (*assign)++;
        }
    }
    return sum;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    
    int freqTable[11] = {0}; 
    int assign, n=10, arr[MAX_LEN];
    for (int k = 0; k < 1000; k++) {
        int a[10];
        initializeArray(arr, n, -100, 100);
        sum_negative(arr, n, &assign);
        freqTable[assign]++;
    }
    
    printf("With 1000 runs, we have: \n");
    for (int i = 0; i < 11; i++) {
        if (freqTable[i] > 0) {
            printf("%d     |     %d\n", i, freqTable[i]);
        }
    }
    return 0;
}

/*
    With 1000 runs, we have:
    1     |     5
    2     |     11
    3     |     43
    4     |     127
    5     |     199
    6     |     236
    7     |     213
    8     |     105
    9     |     49
    10     |     10
 */