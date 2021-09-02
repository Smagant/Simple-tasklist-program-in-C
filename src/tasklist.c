#include "tasklist.h"

char filename[100] = "tasklist.txt";

int count(char *filename) {
    FILE *fp;
    int count = 0;  // Line counter (result)
    char c;  // To store a character read from file
    fp = fopen(filename, "r");
    
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


void addTask(char *filename, char *task) {
    
    char id[16] = {0};
    FILE *fp;
    fp = fopen(filename, "a"); 
    int counter = count(filename);
    
    sprintf(id, "%d", counter);
    fputs(id, fp);
    fputs(" - ", fp);
    fputs(task, fp);

    fclose(fp);
    printFile(filename);
}

void deleteTask(char *filename, char *numTask) {
    
    char task[200];
    int i;
    int j = 0;
    char id[16] = {0};
    int num;
    FILE *fpIn;
    FILE *fpOut;
    fpIn = fopen(filename, "r");
    fpOut = fopen("InputFile.txt", "a");
    sscanf(numTask, "%d", &num);

    while(fgets(task, sizeof(task), fpIn)) {
        sscanf(task, "%d", &i);
        if (i != num) {
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

void modifyTask(char *filename, char *numTask) {
    
    char task[200];
    char task2[200];
    int i;
    int j = 0;
    int num;
    char id[16] = {0};
    FILE *fpIn;
    FILE *fpOut;
    fpIn = fopen(filename, "r");
    fpOut = fopen("InputFile.txt", "a");
    sscanf(numTask, "%d", &num);

    while(fgets(task, sizeof(task), fpIn)) {
        sscanf(task, "%d", &i);
        if (i == num) {
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
    
    printf("**************************************\n");
    while (fgets(task, sizeof(task), fp)) {
        printf("%s", task); 
    }
    printf("**************************************\n");
    printf("\n");
    
    fclose(fp);
}
