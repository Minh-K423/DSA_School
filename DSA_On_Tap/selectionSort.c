#include <stdio.h>

#define MAX 999

void selectionSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[j] <= arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void manualInitializeArray(int array[], int *n) {
    printf("Input the length of  the array: \n"); 
    scanf("%d", n);
    
    printf("Input the array: \n");
    for (int i=0; i<*n; i++) {
        scanf("%d",&array[i]);
    }

}


int main() {
    int arr[MAX];
    int n;
    manualInitializeArray(arr, &n);
    selectionSort(arr, n);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}