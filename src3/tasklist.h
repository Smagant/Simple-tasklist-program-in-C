#ifndef PTFUNC_H
#define PTFUNC_H
#include <stdio.h>
#include <string.h>

extern char filename[100];

//count the number of task in the file
int count(char *filename);

//add task to the file
void getTask(char *filename);

//delete a specific task from the file
void delTask(char *filename, int numTask);

//modify a specific task from the file
void modifyTask(char *filename, int numTask);

//print all the file in the terminal
void printFile(char *filename);

//delete the tasklist file
void delList(char *filename);

#endif
