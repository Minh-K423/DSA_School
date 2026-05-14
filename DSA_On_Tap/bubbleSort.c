#include <stdio.h>

#define MAX 999

void bubbleSort(int arr[], int n) {
    
}

void manualInitializeArray(int array[], int *n) {
    printf("Input the length of  the array: \n"); 
    scanf("%d", n);
    
    printf("Input the array: \n");
    for (int i=0; i<*n; i++) {
        scanf("%d ",&array[i]);
    }

}


int main() {
    int arr[MAX];
    int n;
    manualInitializeArray(arr, &n);
    
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}