#include <stdio.h>


/*
 * ==================================
 * Ham so 1
 * ==================================
 */
int f(int n) {
    if (n == 1)
        return 1;
    return f(n-1)*2;
}

/*
 * Ham nay tinh gia tri cua f(n) = 2^(n-1)
 * Analysis:
 * - Base case: n = 1;
 * - What happens when n = 1: f(1) = 1
 * - Before base case: n = 2; f(2) = 2*f(1) = 2
 * - Before before base case: n = 3; f(3) = 2*2*f(1) = 4
 */

int f_no_recursion(int n) {
    int result = 1;
    for (int i=1; i<n; i++) {
        result *= 2;
    }
    return result;
}


/*
 * ==================================
 * Ham so 2
 * ==================================
 */

float g(int n)
{
    if (n == 1)
        return 1.0;
    return n * n + g(n - 1);
}

/*
 * Analysis:
 * - Base case: n = 1;
 * - What happens when n = 1: g(1) = 1
 * - Before base case: n = 2; g(2) = 2*2 + g(1) = 5
 * - Before before base case: n = 3; g(3) = 3*3 + 2*2 + g(1) = 14
 */

float g_no_recursion(int n) {
    float result = 1.0;
    for (int i=2; i<=n; i++) {
        result = i * i + result;
    }
    return result;
}

/*
 * ==================================
 * Ham so 3
 * ==================================
 */

int F(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return F(n-1)+F(n-2);
}

/*Analysis:
 * - Base case: n = 2; F(2) = 1
 * - What happens when n=2; F(2) = 1
 * - Before base case: n = 3; F(3) = F(2) + F(1) = 1 + 1 = 2
 * - Before before base case: n = 4; F(4) = F(3) + F(2) = F(2) + F(1) + F(1) = 1 + 1 + 1 = 3
 */

int F_no_recursion(int n) {
    int a = 1, b = 1, c;
    for (int i=2; i<n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/*
 * ==================================
 * Ham so 4
 * ==================================
 */

int P(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return 3;
    return P(n-1)*P(n-3);
}

int main() {
    printf("g(4) = %f\n", g(4));
    printf("g_no_recursion(4) = %f\n", g_no_recursion(4));
    printf("F(4) = %d\n", F(4));
    printf("F_no_recursion(4) = %d\n", F_no_recursion(4));
    printf("P(4) = %d\n", P(4));
    return 0;
}
