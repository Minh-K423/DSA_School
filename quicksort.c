#include <stdio.h>

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) return;
    static int count = 1;

    printf("Goi ham lan %d\n", count);
    count++;

    int pivot = partition(arr, left, right);

    printf("Mang con so 1: ");
    for (int i = left; i < pivot; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    printf("Mang con so 2: ");
    for (int i = pivot + 1; i <= right; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");


    quicksort(arr, left, pivot - 1);
    quicksort(arr, pivot + 1, right);

}


int main() {
    int arr[] = {3, 1, 2, -4, 5, 10, 6, -4, 11, 9, -2};
    int n = 11;
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
}

/*
 * Ket qua:
 * Goi ham lan 1
 Mang con so 1: -4, -4,
 Mang con so 2: 3, 5, 10, 6, 1, 11, 9, 2,
 Goi ham lan 2
 Mang con so 1:
 Mang con so 2: -4,
 Goi ham lan 3
 Mang con so 1: 1,
 Mang con so 2: 10, 6, 3, 11, 9, 5,
 Goi ham lan 4
 Mang con so 1: 3,
 Mang con so 2: 10, 11, 9, 6,
 Goi ham lan 5
 Mang con so 1:
 Mang con so 2: 11, 9, 10,
 Goi ham lan 6
 Mang con so 1: 9,
 Mang con so 2: 11,
 -4, -4, -2, 1, 2, 3, 5, 6, 9, 10, 11,
 *
 *
 * Analysis:
 * - Base case: left >= right, return
 * - What happens at base case: Luc nay mang da duoc sap xep, return (dung ham)
 * - Before base case: 1 hoac 2 mang con deu co left < right, Mang chua duoc sap xep, goi lai quicksort voi 2 mang con
 * - Before before base case: 1 hoac 2 mang con deu co left < right, Mang chua duoc sap xep, goi lai quicksort voi 2 mang con
 *
 * Co the cho vi du
 */
