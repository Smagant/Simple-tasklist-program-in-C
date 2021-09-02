#ifndef TASKLIST_H
#define TASKLIST_H
#include "headers.h"

//functions for the first window
char **fileNames(char *NameArr[]);
void addList(char tasklistName[]);
void delList(char tasklistName[]);
void quitApp();
void printTasklists();

//functions for tasks
void addTask(char tasklist);
void delTask(char tasklist);
void modifyTask(char tasklist);
void printTasks(char tasklist);
void backMenu();

#endif
