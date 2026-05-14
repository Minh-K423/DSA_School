#include <stdio.h>
#include <string.h>

#define MAX_LEN 999

void lengthVerification(char string[], int k, int *result) {
    if (strlen(string) != k) {
        *result = -1;
    } else {
        *result = 1;
    }
}
 
void stringCopy(char string1[], char string2[]) {
    for (int i=0; i<strlen(string1); i++) {
        string2[i] = string1[i];
    }
}

void insertionArray(char array[][MAX_LEN], char string[], int *length, int position) {
    (*length)++;
    for (int i=(*length)-1; i>position; i--) {
        stringCopy(array[i-1], array[i]);
    }

    stringCopy(string, array[position]);
}

int main() {
    
    char arrayString[MAX_LEN][MAX_LEN], string[MAX_LEN];
    int arrayLength, subStringLength, position;

    printf("Input the length of the array: "); scanf("%d", &arrayLength);
    printf("Input the length of the string: "); scanf("%d", &subStringLength);
    
    int result1, result2;
    for (int i=0; i<arrayLength; i++) {
        printf("Input the sub string %d: ", i+1); scanf("%s", arrayString[i]);
        lengthVerification(arrayString[i], subStringLength, &result1);
        while (result1 == -1) {
            printf("The sub string length is wrong, please re-input: "); scanf("%s", arrayString[i]);
            lengthVerification(arrayString[i], subStringLength, &result1);
        }
    }

    printf("Input the string you want to insert: "); scanf("%s", string);
    lengthVerification(string, subStringLength, &result2);
    while (result2 == -1) {
        printf("The string length is wrong, please re-input: "); scanf("%s", string);
        lengthVerification(string, subStringLength, &result2);
    }

    printf("What's the location you want to insert the string in? "); scanf("%d", &position);

    insertionArray(arrayString, string, &arrayLength, position);
    for (int i=0; i<arrayLength; i++) {
        printf("%s ", arrayString[i]);
    }
    
}