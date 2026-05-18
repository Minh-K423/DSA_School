#include <stdio.h>

#define LEN 999


void removal(int arr[], int position, int *length, int *steps) {
    for (int i=position; i<*length-1; i++) {
        (*steps)++;
        arr[i] = arr[i+1];
    }
    (*length)--;
    arr[*length] = 0;
}

//Phuong phap 1
int remove_duplicate_1(int arr[], int *length, int *steps) {
    int remove = -1;
    for (int i=0; i<*length; i++) {
        for (int j=0; j<*length; j++) {
            if (arr[j] == arr[i] && i != j) {
                (*steps) ++;
                remove = 1;
                removal(arr, j, length, steps);
                j--;
            } 
        }
    }

    return remove;
}

//Phuong phap 2
void bubbleSort(int arr[], int n, int *steps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                (*steps) ++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int remove_duplicate_2(int arr[], int *length, int *steps) {
    bubbleSort(arr, *length, steps);
    int remove = -1;
    for (int i=0; i<*length; i++) {
        for (int j=i+1; j<*length; j++) {
            if (arr[j] == arr[i]) {
                (*steps) ++;
                remove = 1;
                removal(arr, j, length, steps);
                j--;
            }
        }
    }
    return remove;
}

int main() {
    int arr1[LEN], arr2[LEN];
    int n1, n2;
    int steps1 = 0;
    int steps2 = 0;

    printf("Input the length of the array 1: "); scanf("%d", &n1);
    printf("Input the length of the array 2: "); scanf("%d", &n2);

    printf("Input the array 1: ");
    for (int i=0; i<n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Input the array 2: ");
    for (int i=0; i<n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int result_1 = remove_duplicate_1(arr1, &n1, &steps1);
    if (result_1 == 1) {
        for (int i=0; i<n1; i++) {
            printf("%d ", arr1[i]);
        }
    } else { printf("Nothing was duplicated!"); }
    printf("The steps are: %d", steps1);
    
    printf("\n");
    int result_2 = remove_duplicate_2(arr2, &n2, &steps2);
    if (result_2 == 1) {
        for (int i=0; i<n2; i++) {
            printf("%d ", arr2[i]);
        }
    } else { printf("Nothing was duplicated!"); }
    printf("The steps are: %d", steps2);
} 


/*
    Input the length of the array 1: 5
    Input the length of the array 2: 5
    Input the array 1: 3 1 4 3 2
    Input the array 2: 3 1 4 3 2
    3 1 4 2 The steps are: 1
    1 2 3 4 The steps are: 11
 */