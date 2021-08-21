#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LISTNAME 100
#define MAX_CHAR_TASKCONTENT 200
#define MAX_TASKS 50

//data structure of a list
struct List {
    char name[MAX_CHAR_LISTNAME];
    int idList;
    struct Task task;
    char tasks[MAX_TASKS][MAX_CHAR_TASKCONTENT];
};

struct Task {
    char taskContent[MAX_CHAR_TASKCONTENT];
    int taskid;
}

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
void  addTask(struct List list);
char modifyTask(struct List list, struct Task task);
void delTask(struct List list, struct Task task);
void checkTask(struct List list, struct Task task);

