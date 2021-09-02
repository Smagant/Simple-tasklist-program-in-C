#include "functions.h"

int main(int argc, char ** argv)
{
    //initialize the screen
    //sets up memory and clears the screen
    initscr();
    cbreak();
    noecho();
    
    //get the screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    
    //*****************creating windows**************************
    
    //create the main window
    int start_x, start_y;
    start_x = start_y = 1;
    WINDOW * win = newwin(yMax-1, xMax-1, start_y, start_x);
    //custom the box of the main window
    char c = '*';
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = (int)c;
    top = bottom = (int)c;
    tlc = trc = blc = brc = (int)c;
    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    //Title of the main screen
    mvwprintw(win, 1, (xMax/2)-5, "TASKLIST");
    mvwprintw(win, 2, (xMax/2)-5, "--------");

    //create the menu window
    WINDOW *menuwin = newwin(yMax-5, xMax-6, start_y+3, start_x+3); 
    box(menuwin, 0, 0);
    /*
    //create the tasklist window
    WINDOW *taskwin = newwin(yMax-1, xMax-1, start_y, start_x);
    box(taskwin, 0, 0);
    */
    //create the help window
    WINDOW *helpwin = newwin(yMax-1, xMax-1, start_y, start_x);
    box(helpwin, 0, 0);
    
    refresh();
    wrefresh(win);
    wrefresh(menuwin);

    //menu section
    keypad(menuwin, true);

    char choices[4][20] = {
        "See tasklist",
        "Save",
        "Help",
        "Quit"
    };

    char task[100][100];
    
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 4; i++)
        {
            if(i == highlight) {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i+1, (xMax/2)-10, *(choices + i));
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

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
                if(highlight == 4) {
                    highlight = 3;
                }
                break;
            case 10:
                if(highlight == 0) {
                    //tasklist window
                    delwin(win);
                    delwin(menuwin);
                    refresh();
                    //mvwprintw(taskwin, 1, (xMax/2)-5, "You open the tasklist");
                    displayTasklist(xMax);
                    int h = 0;
                    int c;
                    while(1) {
                        //display the array on the window
                        for (int j = 0; j < len2; j++) {
                            if(j == h) {
                                wattron(taskwin, A_REVERSE);
                            }
                            mvwprintw(taskwin, j+1, (xMax/2)-10, *(task + j));
                            wattroff(taskwin, A_REVERSE);
                        }
                        c = wgetch(taskwin);

                        //choice of the user
                        switch(c)
                        {
                            case KEY_UP:
                                h--;
                                if(h == -1) {
                                    h = 0;
                                }
                                break;
                            case KEY_DOWN:
                                h;
                                if(h == len2+1) {
                                    h = len2-1;
                                }
                                break;
                            case 10:
                                mvwprintw(taskwin, 1, 1, "you chose to enter");
                                wrefresh(taskwin);
                                break;
                            default:
                                break;
                        }
                        if (c == 10) {
                            break;
                        }
                    }
                    
                    
                    refresh();
                    wrefresh(taskwin);
                }
                else if (highlight == 1) {
                    //save option
                }
                else if (highlight == 2) {
                    //help window
                    delwin(win);
                    delwin(menuwin);
                    refresh();
                    mvwprintw(helpwin, 1, (xMax/2)-5, "You are in the help window");
                    wrefresh(helpwin);
                }
                else if (highlight == 3) {
                    //quit option
                }

            default:
                break;
        }
        if (choice == 10) {
            break;
        }
    }

    //printw("your choice was: %s", choices[highlight].c_str());

    /*
    //create the input window
    WINDOW * menuwin = newwin(3, xMax-6, start_y + 3, start_x + 3);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    */

    getch();
    endwin();
    //deallocates memory and ends ncurses
    

    return 0;
}

