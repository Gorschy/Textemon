#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Player.h"

class Map {
private:
    std::vector<std::vector<char>> mapData;
    Player* player;  // Add this line

public:
    Map();
    char getCell(int x, int y);
    void printMap();
    bool movePlayer(char direction); // New method
    void setPlayer(Player* p);
    bool rollBattleState();
};

#endif
