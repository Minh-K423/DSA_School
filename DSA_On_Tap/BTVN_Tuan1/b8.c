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