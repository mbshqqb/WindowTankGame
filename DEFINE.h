//
// Created by mbshqqb on 16-12-28.
//

#ifndef MYGAME_DEFINE_H
#define MYGAME_DEFINE_H

//方向
#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1
#define DIRECTION_UP 3
#define DIRECTION_DOWN 4

//等级
#define LEVEL_COUNT 4

//地图  相对于Window
#define MAP_COUNT LEVEL_COUNT
#define MAP_STARTPOSY 1 //地图开始绘制的Y
#define MAP_STARTPOSX 1 //地图开始绘制的X
#define MAP_NUMY 40 //地图的Y的长度
#define MAP_NUMX 40 //地图的X的长度

//window 屏幕的绝对坐标
#define WINDOW_STARTPOSY 1 //window开始绘制的Y
#define WINDOW_STARTPOSX 1 //window开始绘制的X
#define WINDOW_WIDTH MAP_NUMY+0
#define WINDOW_HEIGHT MAP_NUMX+0
//时间
#define TIME_UNIT          100
#define REBIRTHTIME        5
#define TANKFREEZE         7
#define TANKSPEED          4

//按键
#define UP                 72
#define DOWN               80
#define LEFT               75
#define RIGHT              77
#define ESC                27
#define ENTER              13

#define WHIHTE 0x000
#define BLACK 0xfff
#define RED 0xf00
#define GREEN 0x0f0
#define BLUE 0x00f


//includes
#include "Elements.h"
#include "Bullet.h"
#include "Player.h"
#include "Tank.h"
#include "Utils.h"
#endif //MYGAME_DEFINE_H
