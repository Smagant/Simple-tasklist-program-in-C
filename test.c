#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char task[100][100];
    int i = 0;
    int choice;
    int highlight = 0;

    FILE *tasklist = fopen("test.txt", "r");
    if (tasklist == NULL) {
        perror("Unable to open the file");
        exit(1);
    }
    while(1) {
        while(fgets(task[i], sizeof(task[i]), tasklist)) {
            strcpy(task[i], fgets(task[i], sizeof(task[i]), tasklist));
            i++;
            printf("%s", task[i]);
                    
            /*
            if(i == highlight) {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, i+1, (xMax/2)-10, *(task + i));
            wattroff(win, A_REVERSE);
            i++;i
            */
            
        }
    fclose(tasklist);
    }
}



