#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define LEN 100
#define MAX_LEN 999

typedef struct {
    int index[LEN][LEN];
    int count[LEN];
} malware_info;

void insertion(int arr[], int position, int value, int *length) {
    (*length)++;
    for (int i=*length; i>position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = value;
}

//Level 1 question
/*
int positionCount(char string1[], char string2[]) {
    int count = 0;
    for (int i=0; i< strlen(string1); i++) {
        if (string1[i] == string2[0]) {
            for (int j=0; j < strlen(string2); j++) {
                if (string1[i+j] != string2[j]) {
                    break;
                } else {
                    count ++;
                }
            }
        }
    }
    return count;
} --> Inefficient way to find a substring in a string
 */

malware_info malware_position_count(char string1[], char string2[][LEN], int length) {
    malware_info info;
    int i=0;
    int j=0;
    int k=0; //The current malware we are working on
    int l=0; //The cuurent malware index we are working on
    int count = 0;
    while (k < length) {
        i = 0; 
        j = 0;
        l = 0; 
        count = 0; // -> You gotta reset them dude
        while (string1[i] != '\0') {
            if (string1[i] == string2[k][j]) {
                j++;
                if (string2[k][j] == '\0') { //When there's a complete match
                    info.index[k][l] = (i - strlen(string2[k])) + 1;
                    l++;
                    count++;
                    j = 0;
                }
            } else j = 0;
            i++;
        }
        info.count[k] = count;
        k++;
    }

    return info;
}

//Level 2 question
// 
/*
void minor_malware_removal(char string1[], char string2[], int position, int *length, int subtraction) {    
    int removed_length = strlen(string2);
    for (int i=position; i<*length; i++) {
        string1[i] = string1[i+removed_length];
    }
    string1[*length] = '\0';
    (*length) -= subtraction;
}

void malware_removal(char string1[], char string2[][MAX_LEN], malware_info info, int *length1, int length2) {
    for (int i=0; i<length2; i++) {
        for (int j=0; j < info.count[i]; j++) {
            minor_malware_removal(string1, string2[i], info.index[i][j], length1, length2);
        }
    }
}
*/

void removal_flags(char string1[], char string2[][LEN], int flags[], malware_info info, int length) {
    int full_length = strlen(string1);
    for (int i=0; i<length; i++) {
        int r=0;
        int malware_length = strlen(string2[i]);
        for (int j=0; j<full_length;j++) {
            if (j == info.index[i][r] && r < info.count[i]) {
                for (int k = j; k<j+malware_length; k++) {
                    flags[k] = 1;
                }
                r++;
            }
        }
        /*int j=0;
        while (j<full_length) {
            if (j == info.index[i][r]) {
                for (int k=j; k<malware_length; k++) {
                    flags[k] = 0;
                }
                j += malware_length;
                r++;
            } else j++;
            }*/
    }
} 

void malware_removal(char string1[], char debugged_string1[], int flags[]) {
    int r=0;
    int length = strlen(string1);
    for (int i=0; i< length; i++) {
        if (flags[i] == 0) {
            debugged_string1[r] = string1[i];
            r++;
        }
    }
}

//Level 3 Question

void neutralize_malware_v1(char string1[], char string2[][LEN], malware_info info, int length) {
    int full_length = strlen(string1);
    for (int i=0; i<length; i++) {
        int malware_length = strlen(string2[i]);
        int r=0;
        for (int j=0; j<full_length; j++) {
            if (j == info.index[i][r] && r < info.count[i]) {
                for (int k=j; k < j + malware_length; k++) {
                    string1[k] += 1;
                }
                r++;
            }
        }
    }
}

void neutralize_flag(char string[], int flags[], int *length) {
    for (int i=0; i<*length; i++) {
        if (flags[i] == 1) {
            insertion(flags, i+1, 2, length);
        }
    }
}

void neutralize_malware_v2(char string[], char debugged_string[], int flags[], int length) {
    for (int i=0; i<length; i++) {
        if (flags[i] == 2) {
            debugged_string[i] = string[i-1] + 1;
        } else debugged_string[i] = string[i];
    }
}

int main() {
    char string[MAX_LEN], malwares[LEN][LEN];
    printf("Input the string: "); scanf("%998s", string);

    int nums_of_malwares;
    int validation = -1;
    while (validation != 1) {
        printf("input the number of malwares: "); scanf("%d", &nums_of_malwares);
        if (nums_of_malwares < 6 && nums_of_malwares > 0) validation = 1;
    }
    
    printf("Input the malware: \n");
    for (int i=0; i < nums_of_malwares; i++) {
        scanf("%98s", malwares[i]);
    }

    malware_info info = malware_position_count(string, malwares, nums_of_malwares);
    for (int i=0; i<nums_of_malwares; i++) {
        printf("%d %s ", info.count[i], malwares[i]);
        for (int j=0; j<info.count[i]; j++) {
            if (j == info.count[i] - 1) {
                printf("%d\n", info.index[i][j]);
            } else printf("%d ", info.index[i][j]);
            
        }
    }
    
    char debugged_string[MAX_LEN], neutralized_string[MAX_LEN];
    int flags[MAX_LEN] = {0};
    int length = strlen(string);
    
    removal_flags(string, malwares, flags, info, nums_of_malwares);
    malware_removal(string, debugged_string, flags);
    printf("Debugged string is: %s\n", debugged_string);

    neutralize_flag(string, flags, &length);
    neutralize_malware_v2(string, neutralized_string, flags, length);
    printf("%s", neutralized_string);
    
}