#include "stdio.h"

int f(int a[], int left, int right) {
    if (left >= right)
        return 0;

    int middle = (left + right) / 2;
    return a[middle] + f(a, left, middle-1) + f(a, middle+1, right);
}

int main() {
    int arr[][100] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};
    int dff = &arr[2][3] - &arr[0][0];
    printf("%d\n", dff);
    int i = dff / 100;
    int j = dff % 100;
    printf("%d %d\n", i, j);
}
