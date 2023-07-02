#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Player.h"

class Map {
private:
    std::vector<std::vector<char>> mapData;
    Player player;

public:
    Map();
    char getCell(int x, int y);
    void printMap();
    void movePlayer(char direction); // New method
};

#endif
