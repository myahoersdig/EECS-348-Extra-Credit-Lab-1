/*
Mya Hoersdig
EECS 348 Extra Credit Lab1
Suppose there are 5 Departments and 5 Programmers, each identified with an integer number between 1 and 5. 
You are to assign each Programmer to a Department according to the preferences given below. 
Each Department has a preference for the Programmers. For example, Department #1 preferences 
are as follows: 1 5 3 2 4, meaning that it would like to have programmer #1 as its first 
choice and programmer #4 as its last option. When there is a conflict, i.e., two Departments
would like to have the same Programmer as their first choice, then consult with the Programmer in question, 
(that is, check his/her preferences) to determine which Department gets to hire him/her. 
When the program terminates, all Departments should have one programmer assigned to them.
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
                printf("Department %d will get Programmer %d\n", i+1, pref_programmer);
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

    printf("Enter file name: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
    }

    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        for (int j = 0; j < NUM_PROGRAMMERS; j++) {
            fscanf(input_file, "%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < NUM_PROGRAMMERS; i++) {
        for (int j = 0; j < NUM_DEPARTMENTS; j++) {
            fscanf(input_file, "%d", &arr2[i][j]);
        }
    }

    do_task(arr1, arr2);

    fclose(input_file);
}
