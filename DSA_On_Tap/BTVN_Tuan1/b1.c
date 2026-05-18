#include <stdio.h>

float absolute(float *n1, float *n2) {
    float value;
    if (*n1 >= *n2) {
        value = *n1 - *n2;
    } else {
        value = *n2 - *n1;
    }
    return value;
}


float closestNumber(float m, float arr[], int n, int *index) {
    float smallestGap = absolute(&arr[0], &m);
    for (int i=1; i<n; i++) {
        float gap = absolute(&arr[i], &m);
        if (gap <= smallestGap) {
            smallestGap = gap;
            *index = i;
        }
    }
    return smallestGap;
}


int main() {
    float arr[999];
    int n, m;
    int index;
    printf("Input the integer 'm': "); scanf("%d", &m);
    printf("Input the length of the array: ");  scanf("%d", &n);
    printf("Input the array: ");
    for (int i=0; i<n; i++) {
        scanf("%f", &arr[i]);
    }

    float smallestGap = closestNumber((float) m, arr, n, &index);
    printf("The closest number to 'm' is %f with the gap of %f", arr[index], smallestGap);
}

/*
TEST CASE 1:
Input the integer 'm': 1
Input the length of the array: 6
Input the array: -1.02 0 1.24 1.32 -2.12 3.23
The closest number to 'm' is 1.240000 with the gap of 0.240000
 */