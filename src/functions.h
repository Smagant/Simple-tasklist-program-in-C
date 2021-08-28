#include <ncurses.h>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

//Save the newly added task in a text file
void saveFile();

//Return the tasklist in a vector
vector<string> tasklist();

//Quit the application
void quit();

//Add a task to the file. the user write the task and it saved 
//at the end of the text file
string addTask();

//Delete a task. You go to the place where the task is in the
//interface, you clic on delete and the program will find in
//the array that is built from reading the text file the task
//that we want to delete. Then, it will go to the file, find
//the substring that we want to delete it and delete it
string delTask();

//Modify a task, same thing than deleting a task exept that
//we display the task that we want to modify on the screen
//the user makes his correction and the new task is placed
//at the same place than the previous task
string modifyTask();

//Return the help menu. it just display the readme of the
//software
vector<string> helpText();

