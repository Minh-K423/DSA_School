/*
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
*/
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
/* 
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
*/
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
/* 
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
/*    }
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
/* 
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
*/
/* 
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
*/

#include <stdio.h>
#include <string.h>

#define LEN 100
#define MAX_LEN 999

typedef struct {
    int index[LEN][LEN];
    int count[LEN];
} malware_info;

void insertion(int arr[], int position, int value, int *length) {
    (*length)++;
    for (int i = *length; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
}

//LEVEL 1
malware_info malware_position_count(char string1[], char string2[][LEN], int length) {
    malware_info info;
    int k = 0;
    
    while (k < length) {
        int i = 0, j = 0, l = 0, count = 0; 
        int mal_len = strlen(string2[k]);

        while (string1[i] != '\0') {
            if (string1[i] == string2[k][j]) {
                j++;
                if (string2[k][j] == '\0') { 
                    info.index[k][l] = (i - mal_len) + 1;
                    l++;
                    count++;
                    i = i - j + 1; // Phải lùi i lại để không bỏ sót các mã độc dính lẹo vào nhau (VD: tìm 'aa' trong 'aaa') 
                    j = 0;
                }
            } else {
                if (j > 0) { // Nếu đang so sánh dở dang mà gãy, phải lùi i về vị trí bắt đầu so sánh rồi mới đi tiếp
                    i = i - j; 
                }
                j = 0;
            }
            i++;
        }
        info.count[k] = count;
        k++;
    }
    return info;
}

//LEVEL 2
void removal_flags(char string1[], char string2[][LEN], int flags[], malware_info info, int length) {
    int full_length = strlen(string1);
    for (int i = 0; i < length; i++) {
        int r = 0;
        int malware_length = strlen(string2[i]);
        for (int j = 0; j < full_length; j++) {
            if (j == info.index[i][r] && r < info.count[i]) {
                for (int k = j; k < j + malware_length; k++) {
                    flags[k] = 1;
                }
                r++;
            }
        }
    }
} 

// LEVEL 3
void neutralize_flag(int flags[], int *length) {
    for (int i = 0; i < *length; i++) {
        if (flags[i] == 1) {
            insertion(flags, i + 1, 2, length);
            i++; // Phải nhảy qua cái số 2 vừa chèn, nếu không vòng lặp sẽ cắm đầu chèn số 2 vô tận!
        }
    }
}

void neutralize_malware_v2(char string[], char debugged_string[], int flags[], int new_length) {
    int original_idx = 0;
    
    for (int i = 0; i < new_length; i++) {
        if (flags[i] == 2) {
            debugged_string[i] = string[original_idx - 1] + 1;
        } else {
            debugged_string[i] = string[original_idx];
            original_idx++;
        }
    }
    debugged_string[new_length] = '\0';
}

int main() {
    char string[MAX_LEN], malwares[LEN][LEN];
    printf("Nhap chuoi goc: ");
    scanf("%998s", string);

    int nums_of_malwares;
    printf("Nhap so luong ma doc: ");
    scanf("%d", &nums_of_malwares);
    
    printf("Nhap lan luot cac ma doc:\n");
    for (int i = 0; i < nums_of_malwares; i++) {
        scanf("%98s", malwares[i]);
    }
    printf("=============================================\n");
    //Level 1
    malware_info info = malware_position_count(string, malwares, nums_of_malwares);
    for (int i = 0; i < nums_of_malwares; i++) {
        printf("%d %s ",  info.count[i], malwares[i]);
        if (info.count[i] > 0) {
            for (int j = 0; j < info.count[i]; j++) {
                printf("%d ", info.index[i][j]);
            }
        }
        printf("\n");
    }
    printf("=============================================\n");
    //Level 2
    int string_len = strlen(string);
    int flags[MAX_LEN * 2] = {0}; 
    removal_flags(string, malwares, flags, info, nums_of_malwares);
    printf("Chuoi goc: %s\n", string);
    printf("Chuoi da xoa: ");
    for (int i = 0; i < string_len; i++) {
        if (flags[i] == 0) {
            printf("%c", string[i]);
        }
    }
    printf("\n=============================================\n");
    //Level 3
    char debugged_string[MAX_LEN * 2];
    int dynamic_length = string_len;
    neutralize_flag(flags, &dynamic_length); 
    neutralize_malware_v2(string, debugged_string, flags, dynamic_length);

    printf("Chuoi cuoi cung: %s", debugged_string);
    printf("\n=============================================\n");
    return 0;
}


/*
TEST CASE 1:
    Nhap chuoi goc: gdfjhhghjhgdgsfjhhag                                      
    Nhap so luong ma doc: 1
    Nhap lan luot cac ma doc:
    hhg
    =============================================
    1 hhg 4 
    =============================================
    Chuoi goc: gdfjhhghjhgdgsfjhhag
    Chuoi da xoa: gdfjhjhgdgsfjhhag
    =============================================
    Chuoi cuoi cung: gdfjhihighhjhgdgsfjhhag
    =============================================
TEST CASE 2:
    Nhap chuoi goc: hdsa2023u872hdsa2023hs726ctdlctdlgfd7w7sgd89a7dsa76s82ctdl2023j92jcdt2
    Nhap so luong ma doc: 2
    Nhap lan luot cac ma doc:
    ctdl
    dsa2023
    =============================================
    3 ctdl 25 29 54 
    2 dsa2023 1 13 
    =============================================
    Chuoi goc: hdsa2023u872hdsa2023hs726ctdlctdlgfd7w7sgd89a7dsa76s82ctdl2023j92jcdt2
    Chuoi da xoa: hu872hhs726gfd7w7sgd89a7dsa76s822023j92jcdt2
    =============================================
    Chuoi cuoi cung: hdestab23012334u872hdestab23012334hs726cdtudelmcdtudelmgfd7w7sgd89a7dsa76s82cdtudelm2023j92jcdt2
    =============================================
TEST CASE 3: 
    Nhap chuoi goc: 89324y7w9ui3jbwediugd78uawihdioyqwt8eh1298ey89128uyeiugqwhbdoijwq89dhawuidhn98qwdj9832897jkwhdhsa  
    Nhap so luong ma doc: 3
    Nhap lan luot cac ma doc:
    hvthao
    ppnhung
    phlam
    =============================================
    0 hvthao 
    0 ppnhung 
    0 phlam 
    =============================================
    Chuoi goc: 89324y7w9ui3jbwediugd78uawihdioyqwt8eh1298ey89128uyeiugqwhbdoijwq89dhawuidhn98qwdj9832897jkwhdhsa
    Chuoi da xoa: 89324y7w9ui3jbwediugd78uawihdioyqwt8eh1298ey89128uyeiugqwhbdoijwq89dhawuidhn98qwdj9832897jkwhdhsa
    =============================================
    Chuoi cuoi cung: 89324y7w9ui3jbwediugd78uawihdioyqwt8eh1298ey89128uyeiugqwhbdoijwq89dhawuidhn98qwdj9832897jkwhdhsa
    =============================================
 */