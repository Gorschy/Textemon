#include "Player.h"

Player::Player() {
    // constructor logic here
    health = 100;
    attack = 10;
    x = 1;
    y = 2;
}

int Player::getHealth() {
    return health;
}

void Player::setHealth(int health) {
    this->health = health;
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
