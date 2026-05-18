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

void stringSearch(char stringArray[][999], char string[], int n, int k) {
    for (int i=0; i<n; i++) {
        int result = 1;
        
        for (int j=0; j<k; j++) {
            if (stringArray[i][j] != string[j]) {
                result = -1;
            }       
        }

        if (result == 1) {
            printf("The string %s is at index %d\n", string, i);
        }
    }
}

int main() {
    int n, k;
    printf("Input the length of the array: "); scanf("%d", &n);
    printf("Input the length of the zip code: "); scanf("%d", &k);
    getchar(); // --> My senior told me to use this to prevent buffer overflow and then he goch to work befoere I have time to ask "Why? and what is buffer overflow?" And this is because before changing my code below, I was using fgets instead of scanf

    char serialKey[MAX_LEN][MAX_LEN];
    int i=0;
    int result1, result2;
    for (int i=0; i<n; i++) {
        printf("Input zip code number %d: ", i+1); scanf("%s", serialKey[i]);
        lengthVerification(serialKey[i], k, &result1);
        while (result1 == -1) {
            printf("The zip code length is wrong, please re-input: "); scanf("%s", serialKey[i]);
            lengthVerification(serialKey[i], k, &result1);
        }
    }

    char string[MAX_LEN];
    printf("Input the string you want to find: "); scanf("%s", string);
    lengthVerification(string, k, &result2);
    while (result2 == -1) {
        printf("The zip code length is wrong, please re-input: "); scanf("%s", string);
        lengthVerification(string, k, &result2);
    }

    stringSearch(serialKey, string, n, k);
    
}   

/*
TEST CASE 1:
    Input the length of the array: 4
    Input the length of the zip code: 8
    Input zip code number 1: 01sd203a
    Input zip code number 2: 98lam780
    Input zip code number 3: N1h2u3ng
    Input zip code number 4: hvthaott
    Input the string you want to find: hvthaott
    The string hvthaott is at index 3
TEST CASE 2:
    Input the length of the array: 5
    Input the length of the zip code: 3
    Input zip code number 1: 2k3
    Input zip code number 2: 2k4
    Input zip code number 3: 2k2
    Input zip code number 4: 3j3
    Input zip code number 5: 2k2
    Input the string you want to find: 2k2
    The string 2k2 is at index 2
    The string 2k2 is at index 4
 */