//
// Created by mbshqqb on 16-12-28.
// Random:产生0~m-1之间的一个数
//
#include "Utils.h"
int Random(int m){
    struct timeval tpstart;
    gettimeofday(&tpstart, NULL);
    srand(tpstart.tv_usec);
    return rand()%(m+1);
}
void printWin(int x, int y, int color, std::string str){
    mvaddstr(y,x,str.c_str());
}
void printWin(int x, int y, int color, char ch){
    mvaddch(y,x,ch);
}
void printWin(int x, int y, int color, int data){
    char*chars;
    sprintf(chars,"%d",data);
    mvaddstr(y,x,chars);
}
void scanWin(std::string &str){
    char* chars;
    scanw(chars);
    str=chars;
}

int _kbhit() {
    return 1;
}
