#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
///home/antsma/Documents/git_projects/tasklist/src2/files/
int main(void)
{
    char NameArr[20][256];
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
    for (k=0;(k<(i+1)) && (k<20);k++) {
        printf("%s\n",NameArr[k]);
    }
    //print the filenames on the screen
    return 0;
}
