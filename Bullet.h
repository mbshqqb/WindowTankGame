//
// Created by mbshqqb on 17-1-1.
//

#ifndef TANKGAME_BULLET_H
#define TANKGAME_BULLET_H

#include "DEFINE.h"
struct Bullet {

    Bullet(int=1);           // 默认敌人

    void init(int);
    void move(GameSpaceUnit** &gameSpace,int&);
    void clear();
    void show();
    void registration(GameSpaceUnit** &);
    void unregistration(GameSpaceUnit** &);

    bool disapper;                     // 是否消失
    int host;                          // 绑定坦克编号
    int kind;                          // 坦克种类
    int dir;                           // 子弹运行方向
    GridUnit xy;                           // 子弹当前坐标
};


#endif //TANKGAME_BULLET_H
