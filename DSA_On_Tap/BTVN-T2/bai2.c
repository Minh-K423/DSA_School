#include <stdio.h>
#include <string.h>

int checkSorted(char string[], int n) {// ghi n-1 la de chua chu cuoi ra ra, khong bi so sanh voi ngoai chuoi
    for (int i = 0; i < n - 1; i++) {
        if (string[i] > string[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int orderedLinearSearch(int n, char string[], char value) {
    for (int i = 0; i < n; i++) {
        if (string[i] == value) {
            return i; 
        }
    }
    return -1;
}

int binarySearch(int n, char string[], char value) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        
        if (string[mid] < value) {
            left = mid + 1; 
        } else if (string[mid] > value) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1; 
}

int main() {
    char string[999], value;
    int length;
    printf("Input the string: "); scanf("%s", string);

    getchar();

    printf("Input the value you want to find: "); scanf("%c", &value);
    length = strlen(string);

    int check_result =  checkSorted(string, length);

    if (check_result != 0) {
        int index_linear = orderedLinearSearch(length, string, value);
        int index_binary = binarySearch(length, string, value);
        if (index_binary == index_linear) {
            printf("Both returns the same result: %d and %d", index_linear, index_binary);
        }
    } else {
        printf("The string is not orderred");
    }
}

/*
RESULT
Input the string: abcdefghj
Input the value you want to find: f
Both returns the same result: 5 and 5
*/