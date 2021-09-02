#include "tasklist.h"


char **fileNames(char *NameArr[]) { 
    //char NameArr[20][256];
    DIR *dir;
    int i=0,k;
    struct dirent *ent;
    dir = opendir ("/home/antsma/Documents/git_projects/tasklist/src2/files/");
    if (dir != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) 
        {
            strcpy(NameArr[i],ent->d_name);
            i++;
            /* save filenames in the array */
        }
    
        closedir (dir);
    } 
    else
    {
        /* could not open directory */
        perror ("");
    }
    return NameArr;
}


void addList(char tasklistName[]) {
    //code
}

void delList(char tasklistName[]) {
    //code
}

void quitApp() {
    //code
}

void printTasklists() {
    //code
}

void addTask(char tasklist) {
    //code
}

void delTask(char tasklist) {
    //code
}

void modifyTask(char tasklist) {
    //code
}

void printTasks(char tasklist) {
    //code
}

void backMenu() {
    //code
}

