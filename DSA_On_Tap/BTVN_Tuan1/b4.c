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