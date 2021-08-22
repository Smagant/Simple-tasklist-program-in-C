#include "tasklist.h"

void addTask(struct List list) {
   for (int i = 0; i < MAX_TASKS; i++) {
       if (list.tasks[i][] == NULL) {
           printf("task content : ");
           list.tasks[i][] = getchar();
           list.tasksId[i] = i;
       }
       else {
           i++;
       }
   }
}

void delTask(struct List list, int taskid) {
    list.tasks[taskid][] = NULL;
    list.tasksId[taskid] = NULL;
}

void modifyTask(struct List list, int taskid) {
    delTask(list, taskid);
    addTask(list);
}

void printList(struct List list) {
    printf("%s", list.name);
    printf("==========================");
    for (int i = 0; i < MAX_TASKS; i++) {
        if (list.tasks[i][] != NULL) {
            printf("%d - %s", list.tasksId[i], list.tasks[i][]);
        }
        else {
            i++;
        }
    }

int main() {
    addTask(habits);
    printList(habits);
    modifyTask(habits, 0);
    printList(habits);
    delTask(habits, 0);
    printList(habits);
}

