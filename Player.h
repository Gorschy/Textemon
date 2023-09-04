#ifndef PLAYER_H
#define PLAYER_H

#include "Mob.h"

class Player : public Mob {
private:
    int health;
    int maxHealth;
    int attack;
    int x, y; // position
    int experience; // New member variable
    int level; // New member variable
    int maxExperience; // New member variable

public:
    Player();
    int getHealth();
    void setHealth(int health);
    int getAttack();
    void setAttack(int attack);
    void setPosition(int x, int y);
    int getX();
    int getY();
    void addExperience(int exp); // New method
    void levelUp(); // New method
    int getLevel(); // New method
    int getExperience(); // New method
    void rest();
    int getMaxHealth();
    void setMaxHealth(int maxHealth);
};

#endif
