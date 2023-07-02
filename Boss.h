#ifndef BOSS_H
#define BOSS_H

#include "Mob.h"

class Boss : public Mob
{
public:
    Boss();
    int getHealth() override;
    void setHealth(int health) override;
    int getAttack() override;
    void setAttack(int attack) override;
};

#endif
