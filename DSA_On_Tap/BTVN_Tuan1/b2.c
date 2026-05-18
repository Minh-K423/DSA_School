#include <stdio.h>


int stringLength(char string[]) {
    int length = 0;
    int i = 0;
    while (*(string + i) != '\0') {
        length++;
        i = i+1;
    }
    return length;
}

int firstOccurence(char string[], char character, int length) {
    int index = -1;
    
    for (int i=0; /*i<length*/ string[i] != '\0'; i++) {
        if (*(string + i) == character) {
            index = i;
            break;
        }
    }
    return index;
}


int main() {
    char string[999], character;
    
    printf("Input the string: ");
    fgets(string, sizeof(string), stdin);

    printf("Input the character you want to find: "); scanf("%c", &character);

    int length = stringLength(string);

    int result = firstOccurence(string, character, length);
    if (result != -1) {
        printf("The index is at %d", result);
    } else {
        printf("Not found !");
    }
}

/*
TEST CASE 1:
    Input the string: DataStructureAndAlgorithm
    Input the character you want to find: A
    The index is at 13
TEST CASE 2: 
    Input the string: MmMmMmmM
    Input the character you want to find: m
    The index is at 1
TEST CASE 3: 
    Input the string: PhamNhungLam
    Input the character you want to find: t
    Not found !
 */