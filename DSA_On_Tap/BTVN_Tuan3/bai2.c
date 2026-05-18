#include <stdio.h>
#include <time.h>
#include<stdlib.h>

#define MAX 999

void initializeArray (int a[], int n, int min, int max) {  
    for (int i = 0; i<n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
} 

void sort(int arr[], int n, int *comps) {
    (*comps) = 0;
    for (int i = 0; i < n - 1; i++) { //Duyệt mảng từ i = 0 đến i = n - 1
        int min_index = i;
        
        for (int j = i + 1; j < n; j++) { //Trong các phần tử từ arr[i] đến arr[n-1], tìm minIndex
            (*comps)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        //Hoán đổi (swap) giá trị của arr[minIndex] và arr[i] rồi quay về bước 1
        int temp = arr[i]; 
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));

    int arr[MAX];
    int n=40;
    int runs = 1000;
    int freqTable[1601] = {0}, sumComps = 0;
    int comps;
    for (int i=0; i<1000; i++) {
        initializeArray(arr, n, 0, 10);
        sort(arr, n, &comps);
        freqTable[comps] ++;
        sumComps+=comps;
    }
    printf("With %d runs, we have:\n", runs);
    printf("--Frequency Table--\n");
    for (int i=0; i<1601;i++) {
        if (freqTable[i] != 0) printf("%d  |   %d\n", i, freqTable[i]);
    }
    printf("--The mean of comps is: %f\n", (float) sumComps/runs);
    
}

/*
    With 1000 runs, we have:
    --Frequency Table--
    780  |   1000
    --The mean of comps is: 780.000000

    The time complexity is O(n^2)
 */