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
    char string[] = "abcdefghijklmopqrstuvwxyz";
    int missing_position = missing_character(alphabet, string, 25, 26);
    
    printf("The string: %s\n", string);;
    printf("The %c at %d is missing \n", missing_position+97, missing_position);

    int length = strlen(string);
    insertArray(string, &length, missing_position, missing_position+97);
    printf("The string after fixing: %s", string);
}

/*
The string: abcdefghijklmopqrstuvwxyz
The n at 13 is missing 
The string after fixing: abcdefghijklmnopqrstuvwxyz

Thuat toan binary search khong hop vi o day chung ta can biet ro vvalue can tim nhung mao day chung ta khong co thong tin do
*/