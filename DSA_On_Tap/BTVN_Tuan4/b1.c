#include <stdio.h>
#include <string.h>

#define MAX 999

// Bai 1.1:
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void execution_1() {
    int arr[MAX];
    int n;
    printf("Hay nhap vao so phan tu cua mang: "); scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr, n);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

// Bai 1.2:
void bubble_sort_for_string(char str[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (str[j] > str[j+1]) {
                char temp_char = str[j];
                str[j] = str[j+1];
                str[j+1] = temp_char;
            }
        }
    }
}

void execution_2() {
    char string[100];
    printf("Input the string you want: "); scanf("%s", string);
    int length = strlen(string);
    bubble_sort_for_string(string, length);
    printf("%s", string);
}

//Bai 1.3:
//

void copy_array(int arr1[], int arr2[2], int n) {
    for (int i=0; i<n; i++) {
        arr2[i] = arr1[i];
    }
}

int F(int arr[]) {
    return arr[0] - 2*arr[1] + 3*arr[2];
}


void bubble_sort_for_vector(int arr[][3], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (F(arr[j]) < F(arr[j+1])) {
                int temp[3];
                copy_array(arr[j], temp, 3);
                copy_array(arr[j+1], arr[j], 3);
                copy_array(temp, arr[j+1], 3); 
            }
        }
    }
}

void execution_3() {
    int arr[100][3];
    int length;
    printf("Input the array length: "); scanf("%d", &length);
    for (int i=0; i<length; i++) {
        printf("Input the first vector: ");
        for (int j=0; j<3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    bubble_sort_for_vector(arr, length);

    for (int i=0; i<length; i++) {
        printf("Vector %d: ", i);
        for (int j=0; j<3; j++) {
            printf("%d ", arr[i][j]);
        }
    }
}

int main() {
    printf("Bai 1.1:\n");
    execution_1();
    printf("\n");
    printf("Bai 1.2:\n");
    execution_2();
    printf("\n");
    printf("Bai 1.3:\n");
    execution_3();
    return 0;
}

/*
    Bai 1.1:
    Hay nhap vao so phan tu cua mang: 6
    1 3 5 2 43 1
    1 1 2 3 5 43
    Bai 1.2:
    Input the string you want: adcbe
    abcde
    Bai 1.3:
    Input the array length: 3
    Input the first vector: 1 2 3
    Input the first vector: 4 2 4
    Input the first vector: 8 7 9
    Vector 0: 8 7 9 Vector 1: 4 2 4 Vector 2: 1 2 3
 */