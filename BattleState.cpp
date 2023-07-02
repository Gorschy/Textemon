#include "BattleState.h"
#include <iostream>

BattleState::BattleState(Mob* player, Mob* enemy, std::unordered_map<std::string, std::vector<std::string>>& sprites) 
    : player(player), enemy(enemy), spriteMap(&sprites) {}

void BattleState::drawSprite(const std::string& spriteName) {
    std::vector<std::string> sprite = (*spriteMap)[spriteName];
    for (const std::string& line : sprite) {
        std::cout << line << '\n';
    }
}

void BattleState::startBattle() {
    std::cout << "You've encountered a " << enemy->getName() << "!\n";

    // Print the enemy sprite
    drawSprite(enemy->getName());

    while (true) {
        std::cout << "What will you do?\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Run\n";

        int userInput;
        std::cin >> userInput;
        switch (userInput) {
            case 1:
                // Insert battle logic here
                break;
            case 2:
                // Insert flee logic here
                break;
            default:
                std::cout << "Invalid option.\n";
                continue;
        }

        // Insert enemy turn logic here

        // Check if battle is over
        if (player->getHealth() <= 0) {
            std::cout << "You've been defeated...\n";
            break;
        } else if (enemy->getHealth() <= 0) {
            std::cout << "You've won the battle!\n";
            break;
        }
    }
}
