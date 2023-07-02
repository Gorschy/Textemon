#ifndef MOB_H
#define MOB_H

#include <string>

class Mob
{
protected:
    int health;
    int attack;
    std::string name; // Added a name attribute

public:
    Mob();
    virtual int getHealth();
    virtual void setHealth(int health);
    virtual int getAttack();
    virtual void setAttack(int attack);
    virtual std::string getName(); // Added a getName function
};

#endif
