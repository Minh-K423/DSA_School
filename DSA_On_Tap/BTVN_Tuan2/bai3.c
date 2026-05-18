#include <stdio.h>
#include <string.h>

int missing_character(int alphabet[], char string[], int length1, int length2) {
    for (int i=0; i<length1; i++) {
        int ascii_position = string[i] - 97;
        alphabet[ascii_position]++;
    }

    for (int i=0; i<length2; i++) {
        if (alphabet[i] == 0) return i;
    }
}

void insertArray(char string[], int *length, int position,  char value) {
    (*length)++;
    for (int i=*length-1; i>=position; i--) {
        string[i+1] =string[i];
    }
    string[position] = value;
}

int main() {
    int alphabet[26] = {0};
    char string[999];
    printf("Input the string: ");
    scanf("%s", string);
    int missing_position = missing_character(alphabet, string, 25, 26);
    
    printf("The string: %s\n", string);;
    printf("The %c at %d is missing \n", missing_position+97, missing_position);

    int length = strlen(string);
    insertArray(string, &length, missing_position, missing_position+97);
    printf("The string after fixing: %s", string);
}

/*
TEST CASE 1:
Input the string: bcdefghijklmnopqrstuvwxyz
The string: bcdefghijklmnopqrstuvwxyz
The a at 0 is missing 
The string after fixing: abcdefghijklmnopqrstuvwxyz

TEST CASE 2:
Input the string: abcdefghiklmnopqrstuvwxyz
The string: abcdefghiklmnopqrstuvwxyz
The j at 9 is missing 
The string after fixing: abcdefghijklmnopqrstuvwxyz

TEST CASE 3:
Input the string: abcdefghijklmnopqrstuvwxy
The string: abcdefghijklmnopqrstuvwxy
The z at 25 is missing 
The string after fixing: abcdefghijklmnopqrstuvwxyz
*/