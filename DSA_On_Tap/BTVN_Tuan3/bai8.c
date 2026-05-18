#include <stdio.h>

void f(int a[], int n) {
    int total_assigns = 0;
    
    for (int d = n / 2; d > 0; d /= 2) {
        int round_assigns = 0; 
        
        for (int i = d; i < n; i++) {
            int t = a[i]; 
            round_assigns++; // Count 1 for t = a[i]
            
            int j;
            for (j = i; j >= d && a[j - d] > t; j -= d) {
                a[j] = a[j - d]; 
                round_assigns++; // Count 1 for a[j] = a[j-d]
            }
            a[j] = t; 
            round_assigns++; // Count 1 for a[j] = t
        }
        printf("---Round %d has %d assignment operation\n", d, round_assigns);
        total_assigns += round_assigns;
    }
    printf("----->There's a total of %d assignment operation", total_assigns);
}

int main() {
    int a[] = {34, 29, 10, 3, 2, 44, 88, 1, 21, 12, 3, 18, 21, 23, 37, 17, 8, 9, 4, 0};
    int n = 20;
    f(a, n);
    return 0;
}

/*
    ---Round 10 has 26 assignment operation
    ---Round 5 has 37 assignment operation
    ---Round 2 has 56 assignment operation
    ---Round 1 has 43 assignment operation
    ----->There's a total of 162 assignment operation
 */