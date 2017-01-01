//
// Created by mbshqqb on 17-1-1.
//
#include <ncurses.h>

int main(){
    initscr();
    clear();
    WINDOW*window;
    window=newwin(5, 25, 4, 15);
    waddstr(window,"┛");
    start_color();
    attron(COLOR_RED);
    waddstr(window,"88888888888888");
    attroff(COLOR_RED);
    refresh();
    wrefresh(window);
    getch();
    endwin();
}