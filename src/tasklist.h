#ifndef PTFUNC_H
#define PTFUNC_H
#include <stdio.h>
#include <string.h>

extern char filename[100];

//count the number of task in the file
int count(char *filename);

//add task to the file
void addTask(char *filename, char *task);

//delete a specific task from the file
void deleteTask(char *filename, char *numTask);

//modify a specific task from the file
void modifyTask(char *filename, char *numTask);

//print all the file in the terminal
void printFile(char *filename);

//delete the tasklist file
void deleteList(char *filename);

#endif
