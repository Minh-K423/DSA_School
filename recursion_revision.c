#include <stdio.h>

int calculate_n_value(int n) {
    if (n==1) return 1;
    return n + calculate_n_value(n-1);
}

/*
Analysis:
- Base case: n=1, return 1
- Before base case: n>1, return n + calculate_n_value(n-1);
- Before before base case: n>2, return n + calculate_n_value(n-1) + calculate_n_value(n-2);
 */

int calculate_odd_value(int arr[], int n, int result) {
    if (n == 0) {
        return result;
    }

    if (arr[n] % 2 == 0) {
        result += arr[n];
    } else {
        result += 0;
    }

    return calculate_odd_value(arr, n-1, result);
}

/*
 -Base case: n=0, return result
 -Before case: n>0, return result + calculate_odd_value(arr, n-1, result)
 -Before before case: n>1, return result + calculate_odd_value(arr, n-1, result) + calculate_odd_value(arr, n-2, result)
 */

int main() {
    int arr[5] ={1,2,3,4,5};
    int n=5;
    int result = calculate_odd_value(arr, n, 0);
    printf("Result: %d", result);
    return 0;
}
