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

/*
TEST CASE 1:
Input the length of the array: 3
Input the length of the string: 4
Input the sub string 1: abcd
Input the sub string 2: mnop
Input the sub string 3: efgh
Input the string you want to insert: ijkl
What's the location you want to insert the string in? 1
abcd ijkl mnop efgh

TEST CASE 2:
Input the length of the array: 9
Input the length of the string: 10
Input the sub string 1: 00applepie
Input the sub string 2: 01vnuhcmus
Input the sub string 3: 02ppnhungt
Input the sub string 4: 03phlamtth
Input the sub string 5: 04hvthaoms
Input the sub string 6: 05shjkadkj
Input the sub string 7: 06thcdtlgt 
Input the sub string 8: 0716TTHusm
Input the sub string 9: 0922KDLusm
Input the string you want to insert: 0822TTHusm
What's the location you want to insert the string in? 8
00applepie 01vnuhcmus 02ppnhungt 03phlamtth 04hvthaoms 05shjkadkj 06thcdtlgt 0716TTHusm 0822TTHusm 0922KDLusm
 */