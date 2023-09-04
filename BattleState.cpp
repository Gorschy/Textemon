#include "BattleState.h"
#include <iostream>
#include <limits> // Include for cin.ignore()
#include <algorithm> // Include for std::max

BattleState::BattleState(Player* player, Mob* enemy, std::unordered_map<std::string, std::vector<std::string>>& sprites) 
    : player(player), enemy(enemy), spriteMap(&sprites) {}

void BattleState::drawSprite(const std::string& spriteName) {
    std::vector<std::string> sprite = (*spriteMap)[spriteName];
    for (const std::string& line : sprite) {
        std::cout << line << '\n';
    }
}

void BattleState::drawSpritesSideBySide(const std::string& spriteName1, const std::string& spriteName2) {
    std::vector<std::string> sprite1 = (*spriteMap)[spriteName1];
    std::vector<std::string> sprite2 = (*spriteMap)[spriteName2];

    // Find the maximum height
    size_t maxHeight = std::max(sprite1.size(), sprite2.size());

    // Calculate padding needed for each sprite
    size_t padding1 = maxHeight - sprite1.size();
    size_t padding2 = maxHeight - sprite2.size();

    // Calculate padding above and below each sprite
    size_t paddingAbove1 = padding1 / 2;
    size_t paddingBelow1 = padding1 - paddingAbove1;

    size_t paddingAbove2 = padding2 / 2;
    size_t paddingBelow2 = padding2 - paddingAbove2;

    // Find the maximum width of sprite1 for padding
    size_t maxWidth1 = 0;
    for (const auto& line : sprite1) {
        maxWidth1 = std::max(maxWidth1, line.size());
    }

    // Padding between sprites
    std::string betweenPadding = "    |    "; // Six spaces

    // Draw side by side
    for (size_t i = 0; i < maxHeight; ++i) {
        // Draw padding above sprite1
        if (i < paddingAbove1 || i >= paddingAbove1 + sprite1.size()) {
            for (size_t j = 0; j < maxWidth1; ++j) {
                std::cout << ' ';
            }
        }
        // Draw sprite1 line if it exists
        else {
            std::cout << sprite1[i - paddingAbove1];
            for (size_t j = sprite1[i - paddingAbove1].size(); j < maxWidth1; ++j) {
                std::cout << ' ';
            }
        }

        // Draw padding between sprites
        std::cout << betweenPadding;

        // Draw padding above sprite2
        if (i < paddingAbove2 || i >= paddingAbove2 + sprite2.size()) {
            std::cout << std::string(sprite2[0].size(), ' ');
        }
        // Draw sprite2 line if it exists
        else {
            std::cout << sprite2[i - paddingAbove2];
        }

        std::cout << '\n';
    }
}

BattleResult BattleState::startBattle() {
    std::string lastAction = ""; // To store the last action's result

    // Initial encounter message
    std::cout << "You've encountered a " << enemy->getName() << "!\n";
    drawSpritesSideBySide(player->getName(), enemy->getName());

    while (true) {
        // Clear the console
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        // Display the last action's result
        if (!lastAction.empty()) {
            std::cout << lastAction << "\n";
        }

        // Redraw the sprites
        drawSpritesSideBySide(player->getName(), enemy->getName());

        std::cout << "What will you do?\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Run\n";

        int userInput;
        std::cin >> userInput;
        if(std::cin.fail()) {
            std::cin.clear(); // clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            continue; // skip the rest of this loop iteration
        }

        switch (userInput) {
            case 1:
                // Attack logic
                player->inflictDamage(enemy);
                if (enemy->getHealth() > 0) {
                    lastAction = "You attacked the " + enemy->getName() + ", its health is now " + std::to_string(enemy->getHealth());
                } else {
                    std::cout << "You've won the battle!\n";

                    // Generate random experience between 150 and 300
                    int expAward = 150 + std::rand() % 151; // 150 to 300

                    // Award experience to the player
                    player->addExperience(expAward);

                    std::cout << "You've gained " << expAward << " experience points!\n";

                    return BattleResult::PLAYER_WON;
                }
                break;
            case 2:
                // Flee logic
                if (rand() % 2) { // 50% chance to flee
                    std::cout << "You successfully ran away from the " << enemy->getName() << ".\n";
                    return BattleResult::PLAYER_FLED;
                } else {
                    lastAction = "You failed to escape!";
                }
                break;
            default:
                continue;
        }

        // Enemy turn logic
        if (enemy->getHealth() > 0) {
            enemy->inflictDamage(player);
            if (player->getHealth() > 0) {
                lastAction += "\nThe " + enemy->getName() + " attacked you, your health is now " + std::to_string(player->getHealth());
            } else {
                std::cout << "The " << enemy->getName() << " defeated you...\n";
                return BattleResult::PLAYER_LOST;
            }
        }
    }
}


