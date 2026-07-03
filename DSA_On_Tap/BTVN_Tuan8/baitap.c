#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX_SIZE 999

void initializeArray (int arr[], int length, int min, int max) {
    for (int i = 0; i<length; i++)
        arr[i] = min + rand()%(max - min + 1);
}

int partition(int arr[], int left, int right, int *partition_count, int *swap_count) {
    (*partition_count)++;

    int pivot_index = left + rand() % (right - left + 1);
    int pivot = arr[pivot_index];

    int temp = arr[pivot_index];
    arr[pivot_index] = arr[right];
    arr[right] = temp;
    (*swap_count)++;

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            (*swap_count)++;
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    (*swap_count)++;

    return i + 1;
}

void quicksort(int arr[], int left, int right, int *partition_count, int *swap_count) {
    if (left >= right) return;

    int pivot = partition(arr, left, right, partition_count, swap_count);

    quicksort(arr, left, pivot - 1, partition_count, swap_count);
    quicksort(arr, pivot + 1, right, partition_count, swap_count);
}

void bubble_sort(int arr[], int n, int *swap_count) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                (*swap_count)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n, int *swap_count) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            (*swap_count)++;
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void insertion_sort(int arr[], int n, int *swap_count) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*swap_count)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    /*
    int quicksort_arr[MAX_SIZE];
    int total_partition = 0;
    int k[3] = {100,1000,10000};
    for (int i = 0; i < 3; i++) {
        printf("k = %d\n", k[i]);
        int freqTable[100] = {0};
        for (int j = 0; j < k[i]; j++) {
            initializeArray(quicksort_arr, 10, -1000, 1000);
            quicksort(quicksort_arr, 0, 9, &partition_count, &swap_count);
            freqTable[partition_count]++;
            total_partition += partition_count;
            partition_count = 0;
        }
        for (int j = 0; j < 100; j++) {
            if (freqTable[j] != 0) {
                printf("%d: %d\n", j, freqTable[j]);
            }
        }
        printf("\n");
        printf("Average partition: %d\n", total_partition / k[i]);
        total_partition = 0;
    }
    */

    int arr1_quick[5] = {3, 2, 9, 7, 5};
    int arr2_quick[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3_quick[20] = {4, 3, 2, 6, 5, -3, 5, 7, -3, 1, -3, 5, 7, 9, 7, -5, 3, 2, 1, 2};
    int arr4_quick[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};

    int arr1_bubble[5] = {3, 2, 9, 7, 5};
    int arr2_bubble[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3_bubble[20] = {4, 3, 2, 6, 5, -3, 5, 7, -3, 1, -3, 5, 7, 9, 7, -5, 3, 2, 1, 2};
    int arr4_bubble[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};

    int arr1_insertion[5] = {3, 2, 9, 7, 5};
    int arr2_insertion[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3_insertion[20] = {4, 3, 2, 6, 5, -3, 5, 7, -3, 1, -3, 5, 7, 9, 7, -5, 3, 2, 1, 2};
    int arr4_insertion[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};

    int arr1_selection[5] = {3, 2, 9, 7, 5};
    int arr2_selection[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3_selection[20] = {4, 3, 2, 6, 5, -3, 5, 7, -3, 1, -3, 5, 7, 9, 7, -5, 3, 2, 1, 2};
    int arr4_selection[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};

    int partition_count_quick = 0;
    int swap_count_quick = 0;
    int swap_count_bubble = 0;
    int swap_count_insertion = 0;
    int swap_count_selection = 0;


    printf("First array: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1_quick[i]);
    }
    printf("\n");
    quicksort(arr1_quick, 0, 4, &partition_count_quick, &swap_count_quick);
    bubble_sort(arr1_bubble, 5, &swap_count_bubble);
    insertion_sort(arr1_insertion, 5, &swap_count_insertion);
    selection_sort(arr1_selection, 5, &swap_count_selection);

    printf("Quick sort: %d\n", swap_count_quick);
    printf("Bubble sort: %d\n", swap_count_bubble);
    printf("Insertion sort: %d\n", swap_count_insertion);
    printf("Selection sort: %d\n", swap_count_selection);
    printf("\n");

    swap_count_quick = 0;
    swap_count_bubble = 0;
    swap_count_insertion = 0;
    swap_count_selection = 0;

    printf("Second array: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr2_quick[i]);
    }
    printf("\n");
    quicksort(arr2_quick, 0, 9, &partition_count_quick, &swap_count_quick);
    bubble_sort(arr2_bubble, 10, &swap_count_bubble);
    insertion_sort(arr2_insertion, 10, &swap_count_insertion);
    selection_sort(arr2_selection, 10, &swap_count_selection);

    printf("Quick sort: %d\n", swap_count_quick);
    printf("Bubble sort: %d\n", swap_count_bubble);
    printf("Insertion sort: %d\n", swap_count_insertion);
    printf("Selection sort: %d\n", swap_count_selection);
    printf("\n");

    swap_count_quick = 0;
    swap_count_bubble = 0;
    swap_count_insertion = 0;
    swap_count_selection = 0;

    printf("Third array: \n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr3_quick[i]);
    }
    printf("\n");
    quicksort(arr3_quick, 0, 19, &partition_count_quick, &swap_count_quick);
    bubble_sort(arr3_bubble, 20, &swap_count_bubble);
    insertion_sort(arr3_insertion, 20, &swap_count_insertion);
    selection_sort(arr3_selection, 20, &swap_count_selection);

    printf("Quick sort: %d\n", swap_count_quick);
    printf("Bubble sort: %d\n", swap_count_bubble);
    printf("Insertion sort: %d\n", swap_count_insertion);
    printf("Selection sort: %d\n", swap_count_selection);
    printf("\n");

    swap_count_quick = 0;
    swap_count_bubble = 0;
    swap_count_insertion = 0;
    swap_count_selection = 0;

    printf("Fourth array: \n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr4_quick[i]);
    }
    printf("\n");
    quicksort(arr4_quick, 0, 19, &partition_count_quick, &swap_count_quick);
    bubble_sort(arr4_bubble, 20, &swap_count_bubble);
    insertion_sort(arr4_insertion, 20, &swap_count_insertion);
    selection_sort(arr4_selection, 20, &swap_count_selection);

    printf("Quick sort: %d\n", swap_count_quick);
    printf("Bubble sort: %d\n", swap_count_bubble);
    printf("Insertion sort: %d\n", swap_count_insertion);
    printf("Selection sort: %d\n", swap_count_selection);
    printf("\n");

    swap_count_quick = 0;
    swap_count_bubble = 0;
    swap_count_insertion = 0;
    swap_count_selection = 0;
}

/*k = 100
5: 10
6: 49
7: 39
8: 2

Average partition: 6
k = 1000
5: 105
6: 516
7: 350
8: 29

Average partition: 6
k = 10000
5: 978
6: 5060
7: 3628
8: 333
9: 1

Average partition: 6



First array:
3 2 9 7 5
Quick sort: 10
Bubble sort: 4
Insertion sort: 4
Selection sort: 2

Second array:
10 9 8 7 6 5 4 3 2 1
Quick sort: 22
Bubble sort: 45
Insertion sort: 45
Selection sort: 5

Third array:
4 3 2 6 5 -3 5 7 -3 1 -3 5 7 9 7 -5 3 2 1 2
Quick sort: 46
Bubble sort: 94
Insertion sort: 94
Selection sort: 19

Fourth array:
1 2 3 4 5 6 7 8 9 10 12 11 17 14 15 16 13 18 19 20
Quick sort: 80
Bubble sort: 8
Insertion sort: 8
Selection sort: 2
*/
