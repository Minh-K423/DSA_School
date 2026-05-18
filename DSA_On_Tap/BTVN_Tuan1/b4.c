#include <stdio.h>
#include <string.h>

#define MAX_LEN 999

void insertionAlgrothm(char string[], char character, int position) {
    int length = strlen(string) + 1;
    for (int i=length-1; i>position; i--) {
        string[i] = string[i-1];
    }
    string[position] = character;
}

int main() {
    char string[MAX_LEN], character;
    printf("Input the string: "); fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    printf("What is the character you want to insert? "); scanf("%c", &character);
    
    int position;
    printf("What is the position you want to insert in? "); scanf("%d", &position);

    printf("The string before insertion is: %s\n", string);
    
    insertionAlgrothm(string, character, position);

    printf("The string after innserted is: %s\n", string);
}

/*
TEST CASE 1:
Input the string: DataStructureAndAlgorithm
What is the character you want to insert? A
What is the position you want to insert in? 3
The string before insertion is: DataStructureAndAlgorithm
The string after innserted is: DatAaStructureAndAlgorithm

TEST CASE 2:
Input the string: MmMmMmmM
What is the character you want to insert? m
What is the position you want to insert in? 0
The string before insertion is: MmMmMmmM
The string after innserted is: mMmMmMmmM

TEST CASE 3:
Input the string: thCTDL&G
What is the character you want to insert? T
What is the position you want to insert in? 8
The string before insertion is: thCTDL&G
The string after innserted is: thCTDL&GT
 */