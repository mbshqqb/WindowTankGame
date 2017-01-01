//
// Created by mbshqqb on 17-1-1.
//

#ifndef TANKGAME_TANKGAME_H
#define TANKGAME_TANKGAME_H
#include <vector>

#include "DEFINE.h"

class TankGame {
public:
    TankGame(int=40,int=40);
    ~TankGame();
    void start();

    void test();
private:
    void enter_picture(char&);
    void success_gameover();
    void game_over();
    void turn_to_next_task(char&);
    void runing_a_task();
    void load_init();
    void clear_picture();


    void move_tank(int x, int y);
    void reset(Tank&);
    void update_keyBoard_char(char&);

    int wide;
    int high;
    GameSpaceUnit** gameSpace;

    int no;                       // 关数

    int deadCount;                // 死亡坦克
    Map map;                      // 地图
    Wall* wall;                   // 边框
    Bullet bullet[4];             // 子弹记录

    int creatPlace;               // 敌人诞生位置
    int freezeTime[3];            // 敌人诞生时间

    int existCount;               // 敌人存在数
    int leftCount;                // 剩下敌人数

    Tank enemy[3];                // 敌人坦克
    Tank me;                      // 自己坦克
};
#endif //TANKGAME_TANKGAME_H
