#include <ncurses.h>
#include <string>

using namespace std;

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
    refresh();
    wrefresh(win);

    //create the menu window
    WINDOW *menuwin = newwin(yMax-5, xMax-6, start_y+3, start_x+3); 
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //menu section
    keypad(menuwin, true);

    string choices[7] = {
        "See tasklist",
        "Add a task",
        "Delete a task",
        "Modify a task",
        "Save",
        "Help",
        "Quit"
    };
    
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 7; i++)
        {
            if(i == highlight) {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i+1, (xMax/2)-10, choices[i].c_str());
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
                if(highlight == 7) {
                    highlight = 6;
                }
                break;
            default:
                break;
        }
        if (choice == 10) {
            break;
        }
    }

    printw("your choice was: %s", choices[highlight].c_str());

    /*
    //create the input window
    WINDOW * menuwin = newwin(3, xMax-6, start_y + 3, start_x + 3);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    */

    getch();
    getch();
    endwin();
    //deallocates memory and ends ncurses
    

    return 0;
}

