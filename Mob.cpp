#include "Mob.h"
#include "Random.h"

const std::vector<std::string> Mob::names = {"Bulbasaur", "Cataperie", "Charmander", "Charmeleon", "Ivysaur", "Squirtle", "Wartortle"};


Mob::Mob() {
    Random random; // Creating an instance of Random
    health = 50;
    attack = 10;
    name = Mob::names[random.getIntInRange(0, Mob::names.size() - 1)]; // Randomly selecting a name from the list
}

// Rest of your code...


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

void Mob::inflictDamage(Mob* target) {
    int newHealth = target->getHealth() - this->getAttack();
    target->setHealth(newHealth > 0 ? newHealth : 0);
}

