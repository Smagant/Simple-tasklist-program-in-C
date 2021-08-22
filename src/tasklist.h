#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LISTNAME 100
#define MAX_CHAR_TASKCONTENT 200
#define MAX_TASKS 50

//data structure of a list
struct List {
    char name[MAX_CHAR_LISTNAME];
    int tasksId[MAX_TASKS];
    char tasks[MAX_TASKS][MAX_CHAR_TASKCONTENT];
};

/*
//set up the lists
struct List habits;
struct List dauphine;
struct List mainlist;

//habits specifications
habits.name = "Habits";

//dauphine specifications
dauphine.name = "Dauphine";

//mainlist specification
mainlist.name = "Main List";
*/

//functions for task
void addTask(struct List list);
void modifyTask(struct List list, int taskid);
void delTask(struct List list, int taskid);
void printList(struct List list);

