//
// Created by mbshqqb on 17-1-1.
//


#include "Bullet.h"

Bullet::Bullet(int k) {
    init(k);
}

void Bullet::init(int k) {
    disapper = true;
    host = -1;
    kind = k;
    dir = -1;
}

void Bullet::registration(GameSpaceUnit **&gs) {
    if (!disapper)
        gs[xy.y][xy.x] = GameSpaceUnit(host, -3, true);
}

void Bullet::unregistration(GameSpaceUnit **&gs) {
    if (!disapper)
        gs[xy.y][xy.x] = GameSpaceUnit(0, 0, false);
}

void Bullet::move(GameSpaceUnit **&gameSpace, int &shot) {
    shot = -100;                // -100表示运行中

    if (this->dir == -1)
        return;

    unregistration(gameSpace);  // 注销原有记录

    GridUnit nextxy = xy;
    switch (dir) {
        case 0:
            // right
            nextxy.x++;
            break;
        case 1:
            // up
            nextxy.y--;
            break;
        case 2:
            // right
            nextxy.x--;
            break;
        case 3:
            nextxy.y++;
            break;
    }

    if (gameSpace[nextxy.y][nextxy.x].have == false) {
        // clear the old bullet
        clear();
        unregistration(gameSpace);
        xy = nextxy;
        // show the new bullet
        show();
        registration(gameSpace);
    } else if (gameSpace[nextxy.y][nextxy.x].kind > 0 &&      // 是坦克
               gameSpace[nextxy.y][nextxy.x].kind != kind) {  // 不同类型坦克
        shot = gameSpace[nextxy.y][nextxy.x].tankId;       // 返回受伤坦克编号
        gameSpace[xy.y][xy.x] = GameSpaceUnit(0, 0, false);
        clear();
        init(kind);
    } else if (gameSpace[nextxy.y][nextxy.x].kind == -3) { // 与子弹相撞
        clear();
        unregistration(gameSpace);
        init(kind);
        shot = gameSpace[nextxy.y][nextxy.x].tankId + 7;
    } else {
        unregistration(gameSpace);//gameSpace[xy.y][xy.x] = GameSpaceUnit(0,0,false);
        clear();
        init(kind);
    }
}

void Bullet::clear() {
    printWin(xy.x, xy.y, WHIHTE,"  ");
}

void Bullet::show() {
    printWin(xy.x, xy.y,BLACK, "●");
}
