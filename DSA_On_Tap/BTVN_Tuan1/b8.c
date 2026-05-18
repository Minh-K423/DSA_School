#include <stdio.h>
#include <string.h>

#define MAX_LEN 999

void removeCharacter(char string[], int position, int *length) {    
    for (int i=position; i<*length; i++) {
        string[i] = string[i+1];
    }
    string[*length] = '\0';
    (*length)--;
}

int main() {
    char string[MAX_LEN];
    printf("Input the string: "); fgets(string, sizeof(string), stdin);
    int length = strlen(string);
    string[length - 1] = '\0';

    int position;
    printf("Input the position you want to remove: "); scanf("%d", &position);
    removeCharacter(string, position, &length);

    printf("String after removal: %s", string);
}

/*
TEST CASE 1:
Input the string: DataStructureAndAlgorithm
Input the position you want to remove: 3
String after removal: DatStructureAndAlgorithm

TEST CASE 2:
Input the string: MmMmMmmM
Input the position you want to remove: 7
String after removal: MmMmMmm

TEST CASE 3:
Input the string: thCTDL&GT
Input the position you want to remove: 8
String after removal: thCTDL&G
 */