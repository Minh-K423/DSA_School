#include <stdio.h>
#include <string.h>

#define MAX_LEN 999
#define INDEX_POSITION 2
#define CODE_LEN 10

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

int power(int number, int n) {
    if (n==0) return 1;
    return number * power(number, n-1);
}

int convert(char string[]) {
    int sum = 0;
    for (int i=0; i<strlen(string); i++) {
        sum += (string[i] - 48) * power(10, (strlen(string) - 1) - i);
    }
    return sum;
}

int extractIndex(char string[]) {
    char index[INDEX_POSITION+1];
    index[INDEX_POSITION] = '\0';
    for (int i=0; i<INDEX_POSITION; i++) {
        index[i] = string[i];
    }
    int indexAsNum = convert(index);
    return indexAsNum;
}

int main() {
    char string[MAX_LEN][MAX_LEN];
    int n, m;
    int maxIndex = 0;
    
    printf("Input the number of pre-existed code you want: "); scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        char id[MAX_LEN];
        int result1 = 1;
        printf("Input the code: "); scanf("%998s", id);
        lengthVerification(id, CODE_LEN, &result1);
        while (result1 == -1) {
            printf("Wrong size! Please input again: "); scanf("%998s", id);
            lengthVerification(id, CODE_LEN, &result1);
        }
        int idIndex = extractIndex(id);

        if (idIndex > maxIndex) maxIndex = idIndex; 
        
        stringCopy(id, string[idIndex]);
    }

    printf("Input the number of code you want to insert "); scanf("%d", &m);

    for (int i=0; i<m; i++) {
        char id[MAX_LEN];
        int result2 = 1;
        printf("Input the code: "); scanf("%998s", id);
        lengthVerification(id, CODE_LEN, &result2);
        while (result2 == -1) {
            printf("Wrong size! Please input again: "); scanf("%998s", id);
            lengthVerification(id, CODE_LEN, &result2);
        }
        int idIndex = extractIndex(id);

        if (idIndex > maxIndex) maxIndex = idIndex;
        
        stringCopy(id, string[idIndex]);
    }

    for (int i=0; i <= maxIndex; i++) {
        if (string[i][0] != '\0') {
            printf("%s\n", string[i]);
        } else {
            printf("None\n");
        }
    }
}

/*
TEST CASE 1:
Input the number of pre-existed code you want: 2
Input the code: 01dkshgbkb
Input the code: 02kshdkjhk
Input the number of code you want to insert 2
Input the code: 03jkashjhj
Input the code: 00djhkfdhf
00djhkfdhf
01dkshgbkb
02kshdkjhk
03jkashjhj

TEST CASE 2:
Input the number of pre-existed code you want: 6
Input the code: 01vnuhcmus
Input the code: 03phhlamtth
Wrong size! Please input again: 003phlamtth
Wrong size! Please input again: 03phlamtth
Input the code: 04hvthaoms
Input the code: 05shjkadkj
Input the code: 0716TTHusm
Input the code: 0922KDLusm
Input the number of code you want to insert 4
Input the code: 02ppnhungt
Input the code: 00applepie
Input the code: 0822TTHusm
Input the code: 06thctdlgt
00applepie
01vnuhcmus
02ppnhungt
03phlamtth
04hvthaoms
05shjkadkj
06thctdlgt
0716TTHusm
0822TTHusm
0922KDLusm
 */