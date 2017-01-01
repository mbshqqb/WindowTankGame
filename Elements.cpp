//
// Created by mbshqqb on 17-1-1.
//

#include "Elements.h"

GridUnit::GridUnit() {
    x = -1;
    y = -1;
}

GridUnit::GridUnit(GridUnit &g) {
    x = g.x;
    y = g.y;
}

GridUnit::GridUnit(int _x, int _y) {
    x = _x;
    y = _y;
}

GridUnit &GridUnit::operator=(GridUnit &_gridUnit) {
    x = _gridUnit.x;
    y = _gridUnit.y;
    return *this;
}

bool GridUnit::operator==(GridUnit &_gridUnit) {
    return (x == _gridUnit.x) && (y == _gridUnit.y);
}

bool GridUnit::operator!=(GridUnit &_gridUnit) {
    return !(*this == _gridUnit);
}

/************************************************************************/
Wall::Wall(GameSpaceUnit **&gs, int w, int h, std::string b) {
    wide = w;
    high = h;
    x = 0;
    y = 0;

    std::string brick = b.substr(0, 2);

    upLeftBrick = brick;
    upRightBrick = brick;
    bottomLeftBrick = brick;
    bottomRightBrick = brick;
    horizonBrick = brick;
    verticalBrick = brick;

    for (int i = 0; i != wide; i++) {
        gs[0][i] = GameSpaceUnit(-1, -1, true);
        gs[high - 1][i] = GameSpaceUnit(-1, -1, true);
    }

    for (int i = 1; i != high - 1; i++) {
        gs[i][0] = GameSpaceUnit(-1, -1, true);
        gs[i][wide - 1] = GameSpaceUnit(-1, -1, true);
    }
}

void Wall::set_brick(std::string b) {
    std::string brick = b.substr(0, 2);

    upLeftBrick = brick;
    upRightBrick = brick;
    bottomLeftBrick = brick;
    bottomRightBrick = brick;
    horizonBrick = brick;
    verticalBrick = brick;
}

void Wall::set_brick(std::string ulb, std::string urb, std::string blb, \
                     std::string brb, std::string hb, std::string vb) {
    upLeftBrick = ulb.substr(0, 2);
    upRightBrick = urb.substr(0, 2);
    bottomLeftBrick = blb.substr(0, 2);
    bottomRightBrick = brb.substr(0, 2);
    horizonBrick = hb;
    verticalBrick = vb;
}


void Wall::draw(int x, int y) {
    x = x;
    y = y;
    printWin(0 + x, 0 + y, BLACK,upLeftBrick);
    printWin(wide - 1 + x, 0 + y, BLACK,upRightBrick);
    printWin(0 + x, high - 1 + y, BLACK,bottomLeftBrick);

    //
    // 通过块转移的方式移动最后一个围墙格
    //
    printWin(wide - 2 + x, high - 1 + y, BLACK,bottomRightBrick);
    //printWin(wide - 2+x,high - 1+y,"ab");
//
//    /*块范围坐标*/
//    SMALL_RECT rc;
//    rc.Left = 2 * (wide - 2 + x);
//    rc.Right = rc.Left + 1;
//    rc.Top = rc.Bottom = high - 1 + y;
//
//    /*目标块的起始坐标*/
//    COORD startCoord = {rc.Right + 1, rc.Top};
//
//    /*填充字符*/
//    CHAR_INFO chFill;
//    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_SCREEN_BUFFER_INFO bInfo;
//    GetConsoleScreenBufferInfo(hStdOut, &bInfo);
//    chFill.Attributes = bInfo.wAttributes;
//    chFill.Char.AsciiChar = ' ';
//
//    /*移动块*/
//    ScrollConsoleScreenBuffer(hStdOut, &rc, NULL, startCoord, &chFill);


    for (int i = 1; i != wide - 1; i++) {
        printWin(i + x, 0 + y, BLACK,horizonBrick);
        printWin(i + x, high - 1 + y,BLACK, horizonBrick);
    }

    for (int i = 1; i != high - 1; i++) {
        printWin(0 + x, i + y, BLACK,verticalBrick);
        printWin(wide - 1 + x, i + y, BLACK,verticalBrick);
    }
}

void Wall::erase() {
    printWin(0 + x, 0 + y,WHIHTE, "  ");
    printWin(wide - 1 + x, 0 + y, WHIHTE,"  ");
    printWin(0 + x, high - 1 + y, WHIHTE,"  ");
    printWin(wide - 1 + x, high - 1 + y, WHIHTE,"  ");

    for (int i = 1; i != wide - 1; i++) {
        printWin(i + x, 0 + y, WHIHTE,"  ");
        printWin(i + x, high - 1 + y,WHIHTE, "  ");
    }

    for (int i = 1; i != high - 1; i++) {
        printWin(0 + x, i + y,WHIHTE, "  ");
        printWin(wide - 1 + x, i + y, WHIHTE,"  ");
    }
}

/***************************************************************************/
Map::Map() {

    clear();              // 清空各张地图

    // assist variable
    int x, y, i;

    // the first map
    for (y = 0; y != 2; y++) {
        for (x = 0; x != 6; x++) {
            exist[0][8 + y][6 + x] = true;
            exist[0][6 + x][8 + y] = true;
            exist[0][18 + y][16 + x] = true;
            exist[0][16 + x][18 + y] = true;
            exist[0][28 + y][26 + x] = true;
            exist[0][26 + x][28 + y] = true;
            exist[0][28 + y][6 + x] = true;
            exist[0][22 + x][6 + y] = true;
            exist[0][8 + y][24 + x] = true;
            exist[0][8 + x][30 + y] = true;
        }
    }

    // the second map
    for (i = 0; i != 5; i++) {
        for (x = 6; x != 9; x++) {
            for (y = 6; y != 9; y++)
                exist[1][y][x + 6 * i] = true;
        }

        for (x = 4; x != 7; x++) {
            for (y = 16; y != 23; y++)
                exist[1][y][x + 7 * i] = true;
        }
    }



    // the third map
    for (y = 0; y != 4; y++) {
        for (x = 0; x != 4; x++) {
            exist[2][8 + y][18 + x] = true;
            exist[2][15 + y][11 + x] = true;
            exist[2][15 + y][18 + x] = true;
            exist[2][15 + y][25 + x] = true;
            exist[2][22 + y][11 + x] = true;
            exist[2][22 + y][25 + x] = true;
        }
    }

    // the forth hurdle
    for (y = 0; y != 3; y++) {
        for (x = 0; x != 2; x++) {
            for (i = 0; i != 5; i++) {
                exist[3][i * 6 + 5 + y][4 + x] = true;
                exist[3][i * 6 + 5 + y][34 + x] = true;
            }
        }
    }

    int cirX1 = 19, cirX2 = 20, cirY = 19, tempValue;
    for (x = 12; x <= 27; x++) {
        for (y = 12; y <= 27; y++) {
            tempValue = (y - cirY) * (y - cirY) + (x - cirX1) * (x - cirX1) - 49;
            if (tempValue >= -4 && tempValue <= 4) {
                if ((y < cirY - 2 || y > cirY + 2) &&
                    (x < cirX1 - 1 || x > cirX2 + 1))
                    exist[3][y][x] = true;
            }
            tempValue = (y - cirY) * (y - cirY) + (x - cirX2) * (x - cirX2) - 49;
            if (tempValue >= -4 && tempValue <= 4) {
                if ((y < cirY - 2 || y > cirY + 2) &&
                    (x < cirX1 - 1 || x > cirX2 + 1))
                    exist[3][y][x] = true;
            }
        }
    }
}

void Map::clear() {
    for (int i = 0; i != MAP_COUNT; i++)
        for (int x = 0; x != MAP_NUMX; x++)
            for (int y = 0; y != MAP_NUMY; y++)
                exist[i][y][x] = false;
}


void Map::load(GameSpaceUnit **&gs, int _mapId) {
    mapId = _mapId;
    for (int x = 0; x != MAP_NUMX; x++) {
        for (int y = 0; y != MAP_NUMY; y++) {
            if (exist[_mapId - 1][y][x])
                gs[y][x] = GameSpaceUnit(-2, -2, true);
        }
    }
}

void Map::draw() {
    for (int x = 0; x != MAP_NUMX; x++) {
        for (int y = 0; y != MAP_NUMY; y++) {
            if (exist[mapId - 1][y][x])
                printWin(x, y,0x08,"▓");
        }
    }
}


/*********************************************************************/
GameSpaceUnit::GameSpaceUnit() {
    tankId = 0;
    kind = 0;
    have = false;
}

GameSpaceUnit::GameSpaceUnit(int n, int k, bool h) {
    tankId = n;
    kind = k;
    have = h;
}

GameSpaceUnit &GameSpaceUnit::operator=(GameSpaceUnit &gs) {
    tankId = gs.tankId;
    kind = gs.kind;
    have = gs.have;
    return *this;
}


/*****************************************************************************/
Frame::Frame(int w, int h) {
    wide = w;
    high = h;
}

void Frame::clear_frame() {
    printWin(0 + x, 0 + y,WHIHTE, "  ");
    printWin(wide - 1 + x, 0 + y, WHIHTE, "  ");
    printWin(0 + x, high - 1 + y, WHIHTE, "  ");
    printWin(wide - 1, high - 1, WHIHTE, "  ");

    for (int i = 1; i != wide - 1; i++) {
        printWin(i + x, 0 + y, WHIHTE, "  ");
        printWin(i + x, high - 1 + y, WHIHTE, "  ");
    }

    for (int i = 1; i != high - 1; i++) {
        printWin(0 + x, i + y,WHIHTE,  "  ");
        printWin(wide - 1 + x, i + y, WHIHTE, "  ");
    }
}

void Frame::draw_frame(int _x, int _y) {
    x = _x;
    y = _y;
    printWin(0 + x, 0 + y, BLACK, "┏");
    printWin(wide - 1 + x, 0 + y,BLACK,  "┓");
    printWin(0 + x, high - 1 + y,BLACK,  "┗");
    printWin(wide - 1 + x, high - 1 + y,BLACK,  "┛");

    for (int i = 1; i != wide - 1; i++) {
        printWin(i + x, 0 + y,BLACK,  "━");
        printWin(i + x, high - 1 + y,BLACK,  "━");
    }

    for (int i = 1; i != high - 1; i++) {
        printWin(0 + x, i + y, BLACK, "┃");
        printWin(wide - 1 + x, i + y, BLACK, "┃");
    }
}