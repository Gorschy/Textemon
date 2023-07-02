#include "Mob.h"

Mob::Mob()
{
    // constructor logic here
    health = 50;
    attack = 5;
    name = "Charizard";
}

int Mob::getHealth()
{
    return health;
}

void Mob::setHealth(int health)
{
    this->health = health;
}

int Mob::getAttack()
{
    return attack;
}

void Mob::setAttack(int attack)
{
    this->attack = attack;
}

std::string Mob::getName() // Implementation of getName
{
    return name;
}
