/*
Mya Hoersdig
EECS 348 Lab3 Problem 1
Given 12 monthly sales numbers in an input file. Using functions, generate a tabular sales report 
and also the sales summary report (as shown in the sample output). Your output should include 
the below:   
 Sales report (month and sales in two columns) 
 minimum, maximum, and average of the monthly sales. 
 six-month moving averages. 
 monthly sales report from highest to lowest. 
*/
#include <stdio.h>

#define NUM_DEPARTMENTS 5
#define NUM_PROGRAMMERS 5

void do_task(int departments[5][5], int programmers[5][5]) {
    int used[5] = {0};
    int assignments[5] = {0};

    for (int i = 0; i < 5; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            int pref_programmer = departments[i][j];
            if (used[pref_programmer-1] == 0) {
                assignments[i] = pref_programmer;
                used[pref_programmer-1] = 1;
                printf("Department %d is assigned Programmer %d\n", i+1, pref_programmer);
                break;
            }
        }
    }
}

int main() {
    int arr1[5][5];
    int arr2[5][5];
    FILE *input_file;
    char filename[50];
    int i, j;

    printf("Enter file name: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
    }

    for (i = 0; i < NUM_DEPARTMENTS; i++) {
        for (j = 0; j < NUM_PROGRAMMERS; j++) {
            fscanf(input_file, "%d", &arr1[i][j]);
        }
    }
    for (i = 0; i < NUM_PROGRAMMERS; i++) {
        for (j = 0; j < NUM_DEPARTMENTS; j++) {
            fscanf(input_file, "%d", &arr2[i][j]);
        }
    }

    do_task(arr1, arr2);

    fclose(input_file);
}