#include "Boss.h"

Boss::Boss()
{
    // constructor logic here
    health = 200;
    attack = 20;
}

int Boss::getHealth()
{
    return health;
}

void Boss::setHealth(int health)
{
    this->health = health;
}

int Boss::getAttack()
{
    return attack;
}

void Boss::setAttack(int attack)
{
    this->attack = attack;
}
