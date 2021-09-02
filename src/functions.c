#include "functions.h"

int count(char filename[]) {
    FILE *fp;
    int count = 0;  // Line counter (result)
    char c;  // To store a character read from file
  
    // Open the file
    fp = fopen(filename, "r");
  
    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", "test.txt");
        return 0;
    }
  
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
  
    // Close the file
    fclose(fp);
  
    return count;
}


void displayTasklist(char task[][], int xMax) {
    //char task[100][100];
    int choice1;
    int highlight1 = 0;
    char filename[] = "tasklist.txt";
    int len1, len2;
    len1 = len2 = count(filename);
    
    //create the tasklist window
    WINDOW *taskwin = newwin(30, xMax-1, 1, 1);
    box(taskwin, 0, 0);

    FILE *tasklist = fopen(filename, "r");
    if (tasklist == NULL) {
        perror("Unable to open the file");
        exit(1);
    }
    //fill the array
    int i = 0;
    while(len1--) {
        fgets(task[i], sizeof task[i], tasklist);
        i++;
    }
}
/*    while(1) {
        //display the array on the window
        for (int j = 0; j < len2; j++) {
            if(j == highlight1) {
                wattron(taskwin, A_REVERSE);
            }
            mvwprintw(taskwin, j+1, (xMax/2)-10, *(task + j));
            wattroff(taskwin, A_REVERSE);
        }
        choice1 = wgetch(taskwin);

        //choice of the user
        switch(choice1)
        {
            case KEY_UP:
                highlight1--;
                if(highlight1 == -1) {
                    highlight1 = 0;
                }
                break;
            case KEY_DOWN:
                highlight1++;
                if(highlight1 == len2+1) {
                    highlight1 = len2-1;
                }
                break;
            case 10:
                mvwprintw(taskwin, 1, 1, "you chose to enter");
                wrefresh(taskwin);
                break;
            default:
                break;
        }
        if (choice1 == 10) {
            break;
        }
    }

    //wrefresh(taskwin);
    getch();
    //endwin();
}
*/



