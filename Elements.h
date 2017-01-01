//
// Created by mbshqqb on 17-1-1.
//

#ifndef TANKGAME_ELEMENTS_H
#define TANKGAME_ELEMENTS_H

#include <iostream>
#include "DEFINE.h"
struct GameSpaceUnit {
    GameSpaceUnit();

    GameSpaceUnit(int, int, bool);

    GameSpaceUnit &operator=(GameSpaceUnit &);

    int tankId;
    int kind;
    bool have;
};

struct GridUnit {
    // struct function
    GridUnit();

    GridUnit(GridUnit &);

    GridUnit(int, int);

    // operator function
    GridUnit &operator=(GridUnit &);

    bool operator==(GridUnit &);

    bool operator!=(GridUnit &);

    // data
    int x, y;
};


struct Wall {
    // struct function
    Wall(GameSpaceUnit **&, int w = MAP_NUMX, int h = MAP_NUMY, std::string = "〓");

    // functional function
    void set_brick(std::string);

    /*"┏","┓","┗","┛","━","┃"*/
    void set_brick(std::string, std::string, std::string, \
                   std::string, std::string, std::string);

    void draw(int= 0, int= 0);

    void erase();

    // data
    std::string upLeftBrick;          // 左上角砖块
    std::string upRightBrick;         // 右上角砖块
    std::string bottomLeftBrick;      // 左下角砖块
    std::string bottomRightBrick;     // 右下角砖块
    std::string horizonBrick;         // 水平砖块
    std::string verticalBrick;        // 竖直砖块


    int x;
    int y;

    int wide;
    int high;
};

struct Map {
    Map();

    void load(GameSpaceUnit **&, int);

    void clear();

    void draw();

    int mapId;                             // 当前使用的地图
    bool exist[MAP_COUNT][MAP_NUMY][MAP_NUMX];              // 地图集
};


struct Frame {
    Frame(int= 4, int= 4);

    void draw_frame(int= 0, int= 0);

    void clear_frame();

    int x;
    int y;

    int wide;
    int high;
};

#endif //TANKGAME_ELEMENTS_H
