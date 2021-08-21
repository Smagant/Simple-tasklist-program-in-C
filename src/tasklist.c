#include "tasklist.h"

void  addTask(struct List list) {
   for (int i = 0; i < MAX_TASKS; i++) {
       if (list.tasks[i][] == NULL) {
           printf("task content : ");
           list.task[i][] = getchar();
       }
       else {
           i++;
       }
   }
}





int main() {
    char str[10];

    FILE * fp;

    fp = fopen("file.txt", "w+");

}

