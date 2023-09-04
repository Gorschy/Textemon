#include "Player.h"

Player::Player() {
    // constructor logic here
    health = 750;
    maxHealth = 75;
    attack = 50;
    x = 1;
    y = 2;
    name = "Cataperie";
    experience = 0; // Initialize to 0
    level = 1; // Initialize to 1
    maxExperience = 100; // Initialize to 100
}

int Player::getHealth() {
    return health;
}

void Player::setHealth(int health) {
    this->health = health;
}

int Player::getMaxHealth() {
    return maxHealth;
}

void Player::setMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
}


int Player::getAttack() {
    return attack;
}

void Player::setAttack(int attack) {
    this->attack = attack;
}

void Player::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

int Player::getX() {
    return x;
}

int Player::getY() {
    return y;
}

void Player::addExperience(int exp) {
    experience += exp;
    if (experience >= maxExperience) {
        levelUp();
    }
}

void Player::levelUp() {
    level++;
    maxExperience *= 2; // Double the experience needed for the next level
    experience = 0; // Reset experience
    health += 10; // Increase health by 10
    attack += 2; // Increase attack by 2
}

int Player::getLevel() {
    return level;
}

int Player::getExperience() {
    return experience;
}

void Player::rest(){
    this->health = maxHealth;
}
