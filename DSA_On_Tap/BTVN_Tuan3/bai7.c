#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void invert_array(int arr[], int length) {
    for (int i=0; i < length/2; i++) {   // only half the array because if you go further, you will come back to before
        int temp = arr[i];
        arr[i] = arr[length-1-i];       
        arr[length-1-i] = temp;
    }
}

void detach_number(int arr[], int number, int *length) {
    (*length) = 0;
    if (number == 0) { //Check if the number is 0 or not   
        arr[0] = 0;
        *length = 1;
        return;
    }
    
    while (number != 0) {
        arr[*length] = number % 10;
        (*length) ++;
        number /= 10;
    }
    
    invert_array(arr, *length); //After detaching the number, invert it becuase everything is inverted
}

int count_ascending(int arr[], int length, int*comps) {
    (*comps) = 0;
    for (int i=1; i<length; i++) {
        (*comps)++;
        if (arr[i-1] > arr[i]) {
            return -1;
        }
    }
    return 1;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[999], length;
    int runs = 10000, comps;
    int sum_comps = 0;
    for (int i=0; i<runs; i++) {
        int num = 1000 + rand() % (9999 - 1000 + 1);
        detach_number(arr, num, &length);
        count_ascending(arr, length, &comps);
        sum_comps += comps;
    }
    printf("The mean for number of comparision is: %f\n", (float) sum_comps/runs);
}

/*
 The mean for number of comparision is: 1.683800
 */