#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//data structure of a list
struct List {
    char name[100];
    int idList;
    char tasks[50][200];
};

//data structure of a task
struct Task {
    char content[500];
    int level;
};

//set up the lists
struct List habits;
struct List dauphine;
struct List mainlist;

//habits specifications
strcpy(habits.name, "Habits");
habits.idList = 1;

//dauphine specifications
strcpy(dauphine.name, "Dauphine");
dauphine.idList = 2;

//mainlist specification
strcpy(mainlist.name, "Main List");
mainlist.idList = 3;


//functions for task
char addTask(struct List list);
char modifyTask(struct List list, struct Task task);
void delTask(struct List list, struct Task task);
void checkTask(struct List list, struct Task task);

