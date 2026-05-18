#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LEN 999

void initializeArray (int arr[], int n, int min, int max) {  
    for (int i = 0; i<n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
} 

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

//Bai 1:
void bubbleSort(int arr[], int n, int *comps,int *swaps) {
    (*swaps) = 0;
    (*comps) = 0;
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            (*comps)++;
            if (arr[j-1] > arr[j]) {
                swap(arr+j-1, arr+j);
            }
        }
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[MAX_LEN];
    int n=20, comps, swaps;
    int runs[] = {10, 20, 50, 100, 1000, 10000};
    //Bai 2:
    printf("The number of runs varies: \n");
    for (int i=0; i<6; i++) {
        int freqTable[401] = {0};
        int sumComps = 0;
        for (int j=0; j<runs[i]; j++) {
            initializeArray(arr, n, -1000, 1000);
            bubbleSort(arr, n, &comps, &swaps);
            freqTable[comps]++;
            sumComps += comps;
        }
        printf("---With %d runs, we have:\n", runs[i]);
        printf("Freqency Table:\n");
        for (int k=0; k<401; k++) {
            if (freqTable[k] != 0) {
                printf("%d   |   %d\n", k, freqTable[k]);
            }
        }
        printf("The mean of comps is %f\n", (float) sumComps/runs[i]);
    }
    printf("\n \n");
    //Bai 3:
    printf("The number of runs and the array size varies: ");
    int n_vary[] = {10,20,30,40,50,60,70,80,90,100};
    for (int i=0; i<10; i++) {
        printf("------With array size being %d\n", n_vary[i]);
        for (int j=0; j<6; j++) {
            int freqTable[10000] = {0};
            int sumComps = 0;
            for (int k=0; k<runs[j]; k++) {
                initializeArray(arr, n_vary[i], -1000, 1000);
                bubbleSort(arr, n_vary[i], &comps, &swaps);
                freqTable[comps]++;
                sumComps += comps;
            }
            printf("---With %d runs, we have:\n", runs[j]);
            printf("Freqency Table:\n");
            for (int k=0; k<10000; k++) {
                if (freqTable[k] != 0) {
                    printf("%d   |   %d\n", k, freqTable[k]);
                }
            }
            printf("The mean of comps is %f\n", (float) sumComps/runs[j]);
        }
    }   
}

/*
    The number of runs varies: 
    ---With 10 runs, we have:
    Freqency Table:
    190   |   10
    The mean of comps is 190.000000
    ---With 20 runs, we have:
    Freqency Table:
    190   |   20
    The mean of comps is 190.000000
    ---With 50 runs, we have:
    Freqency Table:
    190   |   50
    The mean of comps is 190.000000
    ---With 100 runs, we have:
    Freqency Table:
    190   |   100
    The mean of comps is 190.000000
    ---With 1000 runs, we have:
    Freqency Table:
    190   |   1000
    The mean of comps is 190.000000
    ---With 10000 runs, we have:
    Freqency Table:
    190   |   10000
    The mean of comps is 190.000000

    -->The mean of comps doesnt change despite the number of runs changes
     
    The number of runs and the array size varies: ------With array size being 10
    ---With 10 runs, we have:
    Freqency Table:
    45   |   10
    The mean of comps is 45.000000
    ---With 20 runs, we have:
    Freqency Table:
    45   |   20
    The mean of comps is 45.000000
    ---With 50 runs, we have:
    Freqency Table:
    45   |   50
    The mean of comps is 45.000000
    ---With 100 runs, we have:
    Freqency Table:
    45   |   100
    The mean of comps is 45.000000
    ---With 1000 runs, we have:
    Freqency Table:
    45   |   1000
    The mean of comps is 45.000000
    ---With 10000 runs, we have:
    Freqency Table:
    45   |   10000
    The mean of comps is 45.000000
    ------With array size being 20
    ---With 10 runs, we have:
    Freqency Table:
    190   |   10
    The mean of comps is 190.000000
    ---With 20 runs, we have:
    Freqency Table:
    190   |   20
    The mean of comps is 190.000000
    ---With 50 runs, we have:
    Freqency Table:
    190   |   50
    The mean of comps is 190.000000
    ---With 100 runs, we have:
    Freqency Table:
    190   |   100
    The mean of comps is 190.000000
    ---With 1000 runs, we have:
    Freqency Table:
    190   |   1000
    The mean of comps is 190.000000
    ---With 10000 runs, we have:
    Freqency Table:
    190   |   10000
    The mean of comps is 190.000000
    ------With array size being 30
    ---With 10 runs, we have:
    Freqency Table:
    435   |   10
    The mean of comps is 435.000000
    ---With 20 runs, we have:
    Freqency Table:
    435   |   20
    The mean of comps is 435.000000
    ---With 50 runs, we have:
    Freqency Table:
    435   |   50
    The mean of comps is 435.000000
    ---With 100 runs, we have:
    Freqency Table:
    435   |   100
    The mean of comps is 435.000000
    ---With 1000 runs, we have:
    Freqency Table:
    435   |   1000
    The mean of comps is 435.000000
    ---With 10000 runs, we have:
    Freqency Table:
    435   |   10000
    The mean of comps is 435.000000
    ------With array size being 40
    ---With 10 runs, we have:
    Freqency Table:
    780   |   10
    The mean of comps is 780.000000
    ---With 20 runs, we have:
    Freqency Table:
    780   |   20
    The mean of comps is 780.000000
    ---With 50 runs, we have:
    Freqency Table:
    780   |   50
    The mean of comps is 780.000000
    ---With 100 runs, we have:
    Freqency Table:
    780   |   100
    The mean of comps is 780.000000
    ---With 1000 runs, we have:
    Freqency Table:
    780   |   1000
    The mean of comps is 780.000000
    ---With 10000 runs, we have:
    Freqency Table:
    780   |   10000
    The mean of comps is 780.000000
    ------With array size being 50
    ---With 10 runs, we have:
    Freqency Table:
    1225   |   10
    The mean of comps is 1225.000000
    ---With 20 runs, we have:
    Freqency Table:
    1225   |   20
    The mean of comps is 1225.000000
    ---With 50 runs, we have:
    Freqency Table:
    1225   |   50
    The mean of comps is 1225.000000
    ---With 100 runs, we have:
    Freqency Table:
    1225   |   100
    The mean of comps is 1225.000000
    ---With 1000 runs, we have:
    Freqency Table:
    1225   |   1000
    The mean of comps is 1225.000000
    ---With 10000 runs, we have:
    Freqency Table:
    1225   |   10000
    The mean of comps is 1225.000000
    ------With array size being 60
    ---With 10 runs, we have:
    Freqency Table:
    1770   |   10
    The mean of comps is 1770.000000
    ---With 20 runs, we have:
    Freqency Table:
    1770   |   20
    The mean of comps is 1770.000000
    ---With 50 runs, we have:
    Freqency Table:
    1770   |   50
    The mean of comps is 1770.000000
    ---With 100 runs, we have:
    Freqency Table:
    1770   |   100
    The mean of comps is 1770.000000
    ---With 1000 runs, we have:
    Freqency Table:
    1770   |   1000
    The mean of comps is 1770.000000
    ---With 10000 runs, we have:
    Freqency Table:
    1770   |   10000
    The mean of comps is 1770.000000
    ------With array size being 70
    ---With 10 runs, we have:
    Freqency Table:
    2415   |   10
    The mean of comps is 2415.000000
    ---With 20 runs, we have:
    Freqency Table:
    2415   |   20
    The mean of comps is 2415.000000
    ---With 50 runs, we have:
    Freqency Table:
    2415   |   50
    The mean of comps is 2415.000000
    ---With 100 runs, we have:
    Freqency Table:
    2415   |   100
    The mean of comps is 2415.000000
    ---With 1000 runs, we have:
    Freqency Table:
    2415   |   1000
    The mean of comps is 2415.000000
    ---With 10000 runs, we have:
    Freqency Table:
    2415   |   10000
    The mean of comps is 2415.000000
    ------With array size being 80
    ---With 10 runs, we have:
    Freqency Table:
    3160   |   10
    The mean of comps is 3160.000000
    ---With 20 runs, we have:
    Freqency Table:
    3160   |   20
    The mean of comps is 3160.000000
    ---With 50 runs, we have:
    Freqency Table:
    3160   |   50
    The mean of comps is 3160.000000
    ---With 100 runs, we have:
    Freqency Table:
    3160   |   100
    The mean of comps is 3160.000000
    ---With 1000 runs, we have:
    Freqency Table:
    3160   |   1000
    The mean of comps is 3160.000000
    ---With 10000 runs, we have:
    Freqency Table:
    3160   |   10000
    The mean of comps is 3160.000000
    ------With array size being 90
    ---With 10 runs, we have:
    Freqency Table:
    4005   |   10
    The mean of comps is 4005.000000
    ---With 20 runs, we have:
    Freqency Table:
    4005   |   20
    The mean of comps is 4005.000000
    ---With 50 runs, we have:
    Freqency Table:
    4005   |   50
    The mean of comps is 4005.000000
    ---With 100 runs, we have:
    Freqency Table:
    4005   |   100
    The mean of comps is 4005.000000
    ---With 1000 runs, we have:
    Freqency Table:
    4005   |   1000
    The mean of comps is 4005.000000
    ---With 10000 runs, we have:
    Freqency Table:
    4005   |   10000
    The mean of comps is 4005.000000
    ------With array size being 100
    ---With 10 runs, we have:
    Freqency Table:
    4950   |   10
    The mean of comps is 4950.000000
    ---With 20 runs, we have:
    Freqency Table:
    4950   |   20
    The mean of comps is 4950.000000
    ---With 50 runs, we have:
    Freqency Table:
    4950   |   50
    The mean of comps is 4950.000000
    ---With 100 runs, we have:
    Freqency Table:
    4950   |   100
    The mean of comps is 4950.000000
    ---With 1000 runs, we have:
    Freqency Table:
    4950   |   1000
    The mean of comps is 4950.000000
    ---With 10000 runs, we have:
    Freqency Table:
    4950   |   10000
    The mean of comps is 4950.000000

    
    -->The mean of comps doesnt change despite the number of runs changes within the same size
    Comp mean = n(n-1)/2, nen do phuc tap la O(n^2)
    Both algrothm have the same time complexity
 */