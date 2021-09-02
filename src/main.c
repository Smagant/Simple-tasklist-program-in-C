#include "tasklist.h"

int main() {
    char cmd[200];

    printf("\nWelcome to your tasklist\n\n");

    while(1) { 
        
        printf("Enter your command: ");
        fgets(cmd, sizeof(cmd), stdin);

        if (cmd[0] =='a') { 
            addTask(filename, cmd + 2);
        }
        else if (cmd[0] == 'd') {
            deleteTask(filename, cmd + 2);
        }
        else if (cmd[0] == 'm') {
            modifyTask(filename, cmd + 2);
        }
        else if (cmd[0] == 'h') {
            printFile("help.txt");
        }
        else if (cmd[0] == 'q') {
            printf("\nClosing the application\n\n");
            break;
        }
        else if (cmd[0] == 'p') {
            printFile(filename);
        }
        else {
            printf("\nUnknown command\n\n");
        }
    }
}
