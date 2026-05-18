#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 999

void initializeArray (int arr[], int n, int min, int max) {  
    for (int i = 0; i<n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
} 

void removal(int arr[], int *length, int position) {
    for (int i = position; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;
}

void insertionSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void caseA(int arr[], int *length, int value, int *comps) {
    (*comps) = 0;
    for (int i = 0; i < *length; i++) {
        (*comps)++;
        if (arr[i] >= value) {
            removal(arr, length, i); 
            i--;
        }
    }
}

void caseB(int arr[], int *length, int value, int *comps) {
    (*comps) = 0;
    insertionSort(arr, *length);
    for (int i = 0; i < *length; i++) {
        (*comps)++;
        if (arr[i] >= value) {
            *length = i;
            break;
        }
    }
}

void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int length1 = 100, length2 = 100; 
    int a1[MAX_LEN], a2[MAX_LEN], comps1, comps2;
    int k = 2016;
    initializeArray(a1, length1, 1998, 2023);
    for (int i=0; i<length2; i++) {
        a2[i] = a1[i];
    }
    printf("The array before: \n");
    print_array(a1, length1);
    printf("--------------------------------------------------\n");

    // Case A:
    caseA(a1, &length1, k, &comps1);
    printf("Result for case A:\n");
    print_array(a1, length1);
    printf("The number of comparision is: %d\n", comps1);
    printf("--------------------------------------------------\n");

    // Case B
    caseB(a2, &length2, k, &comps2);
    printf("Result for case B:\n");
    print_array(a2, length2);
    printf("The number of comparision is %d\n", comps2);
    
    return 0;
}

/*
    The array before:
    2012 2016 2006 2000 2001 2019 2011 2015 2022 2021 2022 2023 2018 2001 2009 2016 2017 2023 2013 2007 2007 2021 1999 2022 2013 2009 2007 1999 1998 2016 2017 2012 2011 2001 2014 2016 2022 2003 2008 2021 2001 2008 2022 2023 2013 2007 2015 2008 2006 2005 2018 2018 2004 2021 2016 2019 2006 2001 2022 2006 2022 2015 2022 2009 2019 2012 2001 2019 2020 2013 2018 1999 2000 2016 1998 2015 2001 2015 2000 2012 1998 2022 2006 2005 2019 1998 2002 2004 2003 2001 2012 2001 2020 2011 2012 2017 2001 2018 2015 1999
    --------------------------------------------------
    Result for case A:
    2012 2006 2000 2001 2011 2015 2001 2009 2013 2007 2007 1999 2013 2009 2007 1999 1998 2012 2011 2001 2014 2003 2008 2001 2008 2013 2007 2015 2008 2006 2005 2004 2006 2001 2006 2015 2009 2012 2001 2013 1999 2000 1998 2015 2001 2015 2000 2012 1998 2006 2005 1998 2002 2004 2003 2001 2012 2001 2011 2012 2001 2015 1999
    The number of comparision is: 100
    --------------------------------------------------
    Result for case B:
    1998 1998 1998 1998 1999 1999 1999 1999 2000 2000 2000 2001 2001 2001 2001 2001 2001 2001 2001 2001 2001 2002 2003 2003 2004 2004 2005 2005 2006 2006 2006 2006 2006 2007 2007 2007 2007 2008 2008 2008 2009 2009 2009 2011 2011 2011 2012 2012 2012 2012 2012 2012 2013 2013 2013 2013 2014 2015 2015 2015 2015 2015 2015
    The number of comparision is 64

    --> The caseB is a better approach with lower number of comparisions
 */