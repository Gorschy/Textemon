#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include <unordered_map>
#include <vector>
#include "Mob.h"
#include "Player.h"

enum class BattleResult {
    PLAYER_WON,
    PLAYER_LOST,
    PLAYER_FLED
};

class BattleState {
private:
    Player* player;
    Mob* enemy;
    std::unordered_map<std::string, std::vector<std::string>>* spriteMap;
    void drawSprite(const std::string& spriteName);
    void drawSpritesSideBySide(const std::string& spriteName1, const std::string& spriteName2);

public:
    BattleState(Player* player, Mob* enemy, std::unordered_map<std::string, std::vector<std::string>>& sprites);
    BattleResult startBattle();
};

#endif
