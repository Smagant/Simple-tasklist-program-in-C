#include "tasklist.h"

char filename[100] = "tasklist.txt";

int count(char *filename) {
    FILE *fp;
    int count = 0;  // Line counter (result)
    char c;  // To store a character read from file
    // Open the file
    fp = fopen(filename, "r");
    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    // Close the file
    fclose(fp);
  
    return count;
}


void getTask(char *filename) {
    char task[200];
    char id[16] = {0};
    FILE *fp;
    fp = fopen(filename, "a"); 
    int counter = count(filename);
    
    printf("What is your name ? : ");
    fgets(task, sizeof(task), stdin);
    
    sprintf(id, "%d", counter);
    fputs(id, fp);
    fputs(" - ", fp);
    fputs(task, fp);

    fclose(fp);
    printFile(filename);
}

void delTask(char *filename, int numTask) {
    char task[200]; //used to read the each task of the tasklist
    int i; //used to collect the id of the existing task
    int j = 0; //counter in the loop
    char id[16] = {0}; //id for the task
    FILE *fpIn; //Input file
    FILE *fpOut; //Output file
    fpIn = fopen(filename, "r");
    fpOut = fopen("InputFile.txt", "a");

    while(fgets(task, sizeof(task), fpIn)) {
        sscanf(task, "%d", &i);
        if (i != numTask) {
            sprintf(id, "%d", j);
            fputs(id, fpOut);
            fputs(" - ", fpOut);
            fputs(task + 4, fpOut);
            j++;
        }
        else {
            continue;
        }
    }
    remove(filename);
    rename("InputFile.txt", filename);
    fclose(fpOut);
    printFile(filename);
}

void modifyTask(char *filename, int numTask) {
    char task[200]; //used to read the each task of the tasklist
    char task2[200];
    int i; //used to collect the id of the existing task
    int j = 0; //counter in the loop
    char id[16] = {0}; //id for the task
    FILE *fpIn; //Input file
    FILE *fpOut; //Output file
    fpIn = fopen(filename, "r");
    fpOut = fopen("InputFile.txt", "a");

    while(fgets(task, sizeof(task), fpIn)) {
        sscanf(task, "%d", &i);
        if (i == numTask) {
            printf("Rewrite the task: ");
            fgets(task2, sizeof(task2), stdin);
            sprintf(id, "%d", j);
            fputs(id, fpOut);
            fputs(" - ", fpOut);
            fputs(task2, fpOut);
            j++;
        }
        else {
            sprintf(id, "%d", j);
            fputs(id, fpOut);
            fputs(" - ", fpOut);
            fputs(task + 4, fpOut);
            j++;
        }
    }
    remove(filename);
    rename("InputFile.txt", filename);
    fclose(fpOut);
    printFile(filename);
}

void printFile(char *filename) {
    char task[200];
    FILE* fp;
    fp = fopen(filename, "r");
    printf("\n");
    printf("===============TASKLIST===============\n");
    while (fgets(task, sizeof(task), fp)) {
        printf("%s", task); 
    }
    printf("===============TASKLIST===============\n");
    printf("\n");
    fclose(fp);
}


void delList(char *filename) {
    remove(filename);
}

