//
// Created by mbshqqb on 17-1-1.
//

#ifndef TANKGAME_TANK_H
#define TANKGAME_TANK_H

#include "DEFINE.h"
struct Tank{
    // struct function
    Tank(int=1,int=-1);

    // output function
    void draw_tank();
    void clear_old();

    // set property function
    void set_picture(int);
    void set_kind(int);
    void set_no(int);
    void init_xy();
    bool reset(GameSpaceUnit** &, int x = 1, int y = 1);

    // functional function
    void trans_direction(int);
    void init_move(GameSpaceUnit** &,int x=0, int y=0);
    void move(GameSpaceUnit** &);
    void rand_direction(GameSpaceUnit**&);
    void trans_to_direction(int);
    int tank_rand(int);
    void be_shot(GameSpaceUnit** &);
    Bullet rand_shot(GameSpaceUnit** &, int, int&);
    Bullet make_bullet(GameSpaceUnit** &gs, int no,int &);


    // data

    /*坦克坐标及图库*/
    std::string picture[4][3][3];      // 坦克图案
    GridUnit xy[3][3];                     // 坦克板块坐标

    /*坦克类型、编号、颜色、生命值*/
    int kind;                          // 坦克种类
    int no;                            // 坦克编号
    int col;                           // 坦克颜色
    int blood;                         // 坦克血长
    int speed;                         // 坦克速度
    int freezeTime;                    // 运行迟缓时间

    /*坦克运行记录*/
    int direction;                     // 坦克方向 1右 2上 3左 4下
    bool bulletExist;                  // 子弹存在性
};

#endif //TANKGAME_TANK_H
