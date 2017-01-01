//
// Created by mbshqqb on 16-12-28.
//
#ifndef MYGAME_UTILS_H
#define MYGAME_UTILS_H

#include <iostream>
#include <ncurses.h>
#include <sys/time.h>
#include <stdlib.h>

//WINDOW *window;

int Random(int m);
int _kbhit();
void printWin(int x, int y, int color, std::string str);
void printWin(int x, int y, int color, char ch);
void printWin(int x, int y, int color, int data);
void scanWin(std::string &str);

#endif //MYGAME_UTILS_H
