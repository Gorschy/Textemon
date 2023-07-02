#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include <unordered_map>
#include <vector>
#include "Mob.h"

class BattleState {
private:
    Mob* player;
    Mob* enemy;
    std::unordered_map<std::string, std::vector<std::string>>* spriteMap;
    void drawSprite(const std::string& spriteName);

public:
    BattleState(Mob* player, Mob* enemy, std::unordered_map<std::string, std::vector<std::string>>& sprites);
    void startBattle();
};

#endif
