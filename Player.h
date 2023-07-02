#ifndef PLAYER_H
#define PLAYER_H

#include "Mob.h"

class Player : public Mob { // This means Player inherits from Mob{
private:
    int health;
    int attack;
    int x, y; // position

public:
    Player();
    int getHealth();
    void setHealth(int health);
    int getAttack();
    void setAttack(int attack);
    void setPosition(int x, int y);
    int getX();
    int getY();
};

#endif
