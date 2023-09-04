#ifndef MOB_H
#define MOB_H

#include "Random.h"
#include <string>
#include <vector> // Add this line to include the vector library

class Mob
{
protected:
    int health;
    int attack;
    std::string name; 
    static const std::vector<std::string> names; // New static member holding the possible names

public:
    Mob();
    virtual int getHealth();
    virtual void setHealth(int health);
    virtual int getAttack();
    virtual void setAttack(int attack);
    virtual std::string getName(); 
    void inflictDamage(Mob* target);
};

#endif
