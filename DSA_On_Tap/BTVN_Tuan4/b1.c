#include <stdio.h>

#define MAX 999

int bubbleSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (arr[j] >= arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX];
    int n;
    printf("Hay nhap vao so phan tu cua mang: "); scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr, n);
    for (int i=0; i<n; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}