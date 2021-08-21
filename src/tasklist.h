#include <stdio.h>
#include <stdlib.h>


//data structure of a list
struct List {
    char name[100];
    int idList;
};

//data structure of a task
struct Task {
    char content[500];
    int level;
};

//functions fot lists 
struct List  addList();
void delList(struct List list);
void renameList(struct List list);

//functions for task
char addTask(struct List list);
char modifyTask(struct List list, struct Task task);
void delTask(struct List list, struct Task task);
void checkTask(struct List list, struct Task task);

