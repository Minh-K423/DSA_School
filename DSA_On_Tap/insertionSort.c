#include <stdio.h>

#define MAX 999

void insertionSort(int array[], int n) {
    for (int i=1; i<n; i++) {

        /*
        int j = i;

        while (j>=0 && array[j-1] > array[j]) {
            int temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
            j = j-1;
        }
        */

        int key = array[i];
        int j = i-1;

        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
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
    insertionSort(arr, n);

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}
