//
// Created by mbshqqb on 17-1-1.
//
#include "Tank.h"

Tank::Tank(int k, int n) {
    no = n;                            // 坦克编号
    kind = k;                          // 坦克种类
    bulletExist = false;
    direction = -1;                    // 无前进方向
    speed = TANKSPEED;
    freezeTime = 0;                   // 非法迟缓时间
    srand((unsigned) time(0));          // 系统随机种子
    set_picture(kind);                 // 初始化坦克图形及其它属性


    for (int y = 0; y != 3; y++) {     // 坐标矩阵
        for (int x = 0; x != 3; x++)
            xy[y][x] = GridUnit(1 + x, 1 + y);
    }
}

void Tank::set_picture(int kind) {
    switch (kind) {
        case 1:
            /*
             *    ■■
             *      ■■
               *    ■■
             */
            picture[0][0][0] = "■";
            picture[0][0][1] = "■";
            picture[0][1][1] = "■";
            picture[0][1][2] = "■";
            picture[0][2][0] = "■";
            picture[0][2][1] = "■";
            /*
             *      ■
             *    ■■■
             *    ■  ■
            */
            picture[1][0][1] = "■";
            picture[1][1][0] = "■";
            picture[1][1][1] = "■";
            picture[1][1][2] = "■";
            picture[1][2][0] = "■";
            picture[1][2][2] = "■";
            /*
             *      ■■
             *    ■■
             *      ■■
             */
            picture[2][0][1] = "■";
            picture[2][0][2] = "■";
            picture[2][1][0] = "■";
            picture[2][1][1] = "■";
            picture[2][2][1] = "■";
            picture[2][2][2] = "■";
            /*
             *    ■  ■
             *    ■■■
             *      ■
             */
            picture[3][0][0] = "■";
            picture[3][0][2] = "■";
            picture[3][1][0] = "■";
            picture[3][1][1] = "■";
            picture[3][1][2] = "■";
            picture[3][2][1] = "■";
            blood = 1;                  // 生命值，不同坦克不一样
            col = 0x07;                 // 颜色值，不同坦克不一样
            break;
        case 2:
            /*
             *      ■◣
             *        ■■
             *      ■◤
             *
             */
            picture[0][0][0] = "■";
            picture[0][0][1] = "◣";
            picture[0][1][1] = "■";
            picture[0][1][2] = "■";
            picture[0][2][0] = "■";
            picture[0][2][1] = "◤";
            /*
             *      ■
             *    ◢■◣
             *    ■  ■
             */
            picture[1][0][1] = "■";
            picture[1][1][0] = "◢";
            picture[1][1][1] = "■";
            picture[1][1][2] = "◣";
            picture[1][2][0] = "■";
            picture[1][2][2] = "■";
            /*
             *      ◢■
             *    ■■
             *      ◥■
             */
            picture[2][0][1] = "◢";
            picture[2][0][2] = "■";
            picture[2][1][0] = "■";
            picture[2][1][1] = "■";
            picture[2][2][1] = "◥";
            picture[2][2][2] = "■";
            /*
             *    ■  ■
             *    ◥■◤
             *      ■
             */
            picture[3][0][0] = "■";
            picture[3][0][2] = "■";
            picture[3][1][0] = "◥";
            picture[3][1][1] = "■";
            picture[3][1][2] = "◤";
            picture[3][2][1] = "■";
            blood = 1;
            col = 0x0c;
            break;
    }
}


void Tank::init_move(GameSpaceUnit **&gs, int _x, int _y) {
    for (int y = 0; y != 3; y++) {
        for (int x = 0; x != 3; x++) {
            if (_x)
                xy[y][x].x += _x;
            if (_y)
                xy[y][x].y += _y;
            gs[xy[y][x].y][xy[y][x].x] = GameSpaceUnit(no, kind, true);
        }
    }
}

void Tank::init_xy() {
    for (int y = 0; y != 3; y++) {     // 坐标矩阵
        for (int x = 0; x != 3; x++)
            xy[y][x] = GridUnit(1 + x, 1 + y);
    }
}

void Tank::move(GameSpaceUnit **&gs) {
    if (direction == -1) //无方向
        return;

    int _x = 0, _y = 0;
    switch (direction) {
        case 0:
            _x++;
            break;
        case 1:
            _y--;
            break;
        case 2:
            _x--;
            break;
        case 3:
            _y++;
            break;
    }

    // 计算下一步坐标
    GridUnit txy[3][3];
    for (int x = 0; x != 3; x++) {
        for (int y = 0; y != 3; y++) {
            txy[y][x].x = xy[y][x].x + _x;
            txy[y][x].y = xy[y][x].y + _y;
        }
    }


    bool ok = true;
    for (int x = 0; x != 3; x++) {
        for (int y = 0; y != 3; y++) {
            _x = txy[y][x].x;
            _y = txy[y][x].y;
            if (gs[_y][_x].have && gs[_y][_x].tankId != no) {// 有重叠部分
                if (gs[_y][_x].kind == 3)   // 是子弹
                    blood--;
                ok = false;
                break;
            }
        }
    }


    // 可以前行
    if (ok) {
        // 擦除旧图
        clear_old();
        // 擦出游戏空间中原有图形
        for (int y = 0; y != 3; y++) {
            for (int x = 0; x != 3; x++) {
                _x = xy[y][x].x;
                _y = xy[y][x].y;
                gs[_y][_x] = GameSpaceUnit(0, 0, false);
                xy[y][x] = txy[y][x];
            }
        }

        // 在游戏空间中登记加入图形
        for (int y = 0; y != 3; y++) {
            for (int x = 0; x != 3; x++) {
                _x = xy[y][x].x;
                _y = xy[y][x].y;
                gs[_y][_x] = GameSpaceUnit(no, kind, true);
            }
        }
        // 刷新新图
        draw_tank();
        // 更新移动变量
        speed = TANKSPEED;
    }
}


void Tank::rand_direction(GameSpaceUnit **&gs) {
    bool can[4];
    for (int i = 0; i != 4; i++)
        can[i] = true;

    int count = 4;
    for (int i = 0; i != 3; i++) {
        // 往右搜索
        if (can[0] && gs[xy[i][2].y][xy[i][2].x + 1].have) {
            can[0] = false;
            count--;
        }
        // 往上搜索
        if (can[1] && gs[xy[0][i].y - 1][xy[0][i].x].have) {
            can[1] = false;
            count--;
        }
        // 往左搜索
        if (can[2] && gs[xy[i][0].y][xy[i][0].x - 1].have) {
            can[2] = false;
            count--;
        }
        // 往下搜索
        if (can[3] && gs[xy[2][i].y + 1][xy[2][i].x].have) {
            can[3] = false;
            count--;
        }
    }

    if (count == 0)                 // 没有可行出口
        return;

    // 获取一个随机可行的方向
    int newDir;
    int r = tank_rand(count) + 1;
    for (int i = 0; i != 4; i++) {
        if (can[i]) {
            if (r > 1)
                r--;
            else {
                newDir = i;
                break;
            }
        }
    }

    trans_to_direction(newDir);
    freezeTime = TANKFREEZE;
}


bool Tank::reset(GameSpaceUnit **&gs, int _x, int _y) {
    // 判断此处是否可以诞生
    for (int y = 0; y != 3; y++) {
        for (int x = 0; x != 3; x++) {
            if (gs[y + _y][x + _x].have)
                return false;
        }
    }

    for (int y = 0; y != 3; y++) {
        for (int x = 0; x != 3; x++) {
            xy[y][x] = GridUnit(x + _x, y + _y);
            gs[y + _y][x + _x] = GameSpaceUnit(no, kind, true);
        }
    }

    blood = 1;
    bulletExist = false;
    return true;
}

void Tank::set_kind(int k) {
    kind = k;
    set_picture(k);
}

void Tank::set_no(int n) {
    no = n;
}

void Tank::trans_to_direction(int dir) {
    clear_old();
    trans_direction(dir);
    draw_tank();
}

void Tank::trans_direction(int dir) {
    direction = dir;
}

void Tank::be_shot(GameSpaceUnit **&gs) {
    blood--;
    // 没死
    if (blood > 0)
        return;

    // 死了
    int _x, _y;
    for (int y = 0; y != 3; y++) {
        for (int x = 0; x != 3; x++) {
            _x = xy[y][x].x;
            _y = xy[y][x].y;
            gs[_y][_x] = GameSpaceUnit(0, 0, false);
        }
    }

    clear_old();
}

Bullet Tank::rand_shot(GameSpaceUnit **&gs, int no, int &shot) {
    // 死了
    if (blood <= 0)
        return Bullet();

    int k = tank_rand(200);

    if ((k > 50 && k < 100) || (k > 150 && k < 200))
        return make_bullet(gs, no, shot);

    return Bullet();
}

Bullet Tank::make_bullet(GameSpaceUnit **&gs, int no, int &shot) {
    shot = -1;
    GridUnit txy = xy[1][1];
    switch (direction) {
        case 0:
            txy.x += 2;
            break;
        case 1:
            txy.y -= 2;
            break;
        case 2:
            txy.x -= 2;
            break;
        case 3:
            txy.y += 2;
            break;
    }


    if (gs[txy.y][txy.x].have) {
        if (kind != gs[txy.y][txy.x].kind &&
            gs[txy.y][txy.x].kind > 0) {
            shot = gs[txy.y][txy.x].tankId;
        }
        return Bullet();
    }
    Bullet ret;
    ret.kind = kind;
    ret.disapper = false;
    ret.dir = direction;
    ret.host = no;

    ret.xy = txy;
    return ret;
}

void Tank::draw_tank() {
    for (int y = 0; y != 3; y++)
        for (int x = 0; x != 3; x++)
            printWin(xy[y][x].x, xy[y][x].y, BLACK,picture[direction][y][x]);
}

void Tank::clear_old() {
    for (int y = 0; y != 3; y++)
        for (int x = 0; x != 3; x++)
            printWin(xy[y][x].x, xy[y][x].y,WHIHTE, "  ");
}


int Tank::tank_rand(int max) {
    return rand() % max;
}
