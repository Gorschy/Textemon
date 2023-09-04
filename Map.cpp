#include "Map.h"
#include <iostream>
#include <random>

using namespace std;

Map::Map() {
    mapData = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', 'P', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', '#', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
}



char Map::getCell(int x, int y) {
    return mapData[y][x];
}

void Map::printMap() {
    for (const auto& row : mapData) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << '\n';
    }
}

void Map::setPlayer(Player* p) {
    player = p;
}

bool Map::rollBattleState() {
    bool battle = false;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 100); // define the range

    int chance = distr(gen); // generate number between 1 and 100

    if(chance <= 25) {
        battle = true;
    }

    return battle;
}

bool Map::movePlayer(char direction) {
    int x = player->getX();
    int y = player->getY();
    int previousX = x;
    int previousY = y;
    bool bossBattle = false;
    // Calculate new position based on direction
    switch (direction) {
        case 'w': // up
            y--;
            break;
        case 's': // down
            y++;
            break;
        case 'a': // left
            x--;
            break;
        case 'd': // right
            x++;
            break;
    }

    // Check if the move is valid
    if (mapData[y][x] == '#') {
        std::cout << "Hit a wall!\n";
    } else if (mapData[y][x] == 'B') {
        
        return bossBattle = true;

    } else if (mapData[y][x] == 'R') {
        //Rest Encounter
        std::cout << "You have discovered a cave hidden away from creatures that roam this land\n";
        std::cout << "You take this oppurtunity to rest and recover your strength\n";
        std::cout << "You have recovered to full hp " << player->getMaxHealth() << endl;
        player->rest();
        std::cout << "Your current hp " << player->getHealth() << endl;

    } else {
        player->setPosition(x, y);
        mapData[y][x] = 'P';
        mapData[previousY][previousX] = ' ';
    }

    // If moved to a new cell, roll for combat encounter
    // ...
    // Redraw map
    printMap();
    return bossBattle = false;
}




