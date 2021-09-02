#include <stdio.h>
#include <stdlib.h>

int count(char filename[])
{
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

//todolist
int main() {

    char task[100][100];
    int i = 0;
    int choice;
    int highlight = 0;
    char filename[] = "test.txt";
    int len1, len2; 
    len1 = len2 = count(filename);

    FILE *tasklist = fopen(filename, "r");
    if (tasklist == NULL) {
        perror("Unable to open the file");
        exit(1);
    }
    //fill the array
    while(len1--) {
        fgets(task[i], sizeof task[i], tasklist);
        i++;
    }
    
    //display the array on the window
    int len2= count(filename);
    printf("%d\n", len);

    for (int j = 0; j < len2; j++) {
        printf("%s", *(task+j));
    }

/*
    choice = wgetch(win);

    //choice of the user
    switch(choice)
    {
        case KEY_UP:
            highlight--;
            if(highlight == -1) {
                highlight = 0;
            }
            break;
        case KEY_DOWN:
            highlight++;
            if(highlight == i+1) {
                highlight = i-1;
            }
            break;
        case 10:
            mvwprintw(win, 1, 1, "you chose to enter");
            wrefresh(win);
        default:
            break;
    }

    int i = 0, line = 50;
    char ch[100][100];
    char ln[100];
    int linesCount = Count();
    char th;


    FILE *myfile;
    myfile = fopen("test.txt","r");
    if (myfile== NULL)
    {
        printf("can not open file \n");
        return 1;
    }
    
    int j = 0; 
    while(linesCount--) {
        fgets(ch[j], sizeof ch[j], myfile);
        printf("\n%s", *(ch + j));
        j++;
    }
    
    fclose(myfile);
*/
    return 0;
}
