#include "Map.h"
#include <iostream>
#include <random>

using namespace std;

Map::Map() {
    mapData = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', 'P', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', 'T', ' ', ' ', '#'},
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

bool rollBattleState() {
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

void Map::movePlayer(char direction) {
    int x = player.getX();
    int y = player.getY();
    int previousX = x;
    int previousY = y;
    
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
        //Enter Boss battle
    } else if (mapData[y][x] == 'T') {
        //Treasure Encounter
    } else {
        player.setPosition(x, y);
        mapData[y][x] = 'P';
        mapData[previousY][previousX] = ' ';
    }

    // If moved to a new cell, roll for combat encounter
    // ...

    // Redraw map
    printMap();
}


