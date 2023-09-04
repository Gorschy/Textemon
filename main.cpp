#include "Player.h"
#include "Boss.h"
#include "Map.h"
#include "BattleState.h"
#include "Random.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
using namespace std;

Random random;
int userInput;
Player player;
Map map;


void startGame();
void loadGame();
void help();
void exitGame();
void mainMenu();

std::vector<std::string> loadSprite(const std::string& filename) {
    std::vector<std::string> sprite;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        sprite.push_back(line);
    }

    return sprite;
}

void loadAllSprites(std::unordered_map<std::string, std::vector<std::string>>& sprites) {
    const std::vector<std::string> spriteNames = {
        "Blastoise", "Bulbasaur", "Cataperie", "Charizard", "Charmander",
        "Charmeleon", "Death", "Ivysaur", "Squirtle", "Vensaur", "Victory", "Wartortle"
    };

    for (const auto& spriteName : spriteNames) {
        sprites[spriteName] = loadSprite("Sprites/" + spriteName + ".txt");
    }
}

void slowPrint(const std::string& text, unsigned int milli_seconds)
{
    for(const auto c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(milli_seconds));
    }
}

std::string loadDialogue(const std::string& filePath)
{
    std::ifstream inFile(filePath);
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

void characterSelection() {

    int choice;
    std::cout << "Before your adventure begins, you must choose your starter Pokémon. Here are your options:\n";

    while (true) {
        std::cout << "1. Caterpie\n";
        std::cout << "2. A mysterious Pokéball (Spoiler: it's Caterpie)\n";
        std::cout << "3. The Caterpie standing next to the Pokéball\n";
        std::cout << "Enter the number of your choice: ";
        std::cin >> choice;

        if(std::cin.fail()) { // if the previous input failed...
            std::cin.clear(); // clear the failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the input
            std::cout << "Invalid choice. Please enter a number from 1 to 3.\n";
            continue;
        }

        if (choice >= 1 && choice <= 3) {
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number from 1 to 3.\n";
        }
    }

    std::cout << "You've chosen Caterpie! It's a great choice for starting your journey. Good luck!\n";

}

void victory() {
    std::cout << "You Win" << endl;
}

void gameLoop(std::unordered_map<std::string, std::vector<std::string>>& spriteMap) {
    char direction;
    map.printMap();
    
    while(true) {
        //print movement options
        std::cout << "Enter a direction to move (w/s/a/d): ";
        std::cin >> direction;
        bool bossBattle = map.movePlayer(direction);
        int randomNumber = random.getIntInRange(1, 10); // get a random number between 1 and 10
        Player* pPlayer = &player;

        if(bossBattle==true) {
            Mob* mob = new Mob();
            BattleState battle(&player, mob, spriteMap);
            BattleResult result = battle.startBattle();
            if (result == BattleResult::PLAYER_LOST) {
                std::cout << "Press any key to return to the main menu.\n";
                char key;
                std::cin >> key;
                mainMenu();
            } else {
                victory();
            }

        }

        if(map.rollBattleState()) {
            Mob* mob = new Mob(); 
            BattleState battle(&player, mob, spriteMap);
            BattleResult result = battle.startBattle();
            if (result == BattleResult::PLAYER_LOST) {
                std::cout << "Press any key to return to the main menu.\n";
                char key;
                std::cin >> key;
                mainMenu();
            } 
        } // 25% chance to return true


    }
}

// Start Game function
void startGame() {
    std::cout << "Starting the game...\n";
    std::string dialogue = loadDialogue("dialogue/intro.txt"); // replace "intro.txt" with your file path
    slowPrint(dialogue + "\n", 0);
    characterSelection();

        //load sprites
    std::unordered_map<std::string, std::vector<std::string>> spriteMap;
    loadAllSprites(spriteMap);


    gameLoop(spriteMap);
}


// Load Game function
void loadGame() {
    std::cout << "Loading the game...\n";
    // insert your code here
    // read in save directory location.
    // get user input
    // load file - contains player & map data
}

// Help function
void help() {
    // insert your code here
    cout << "===============================" << endl;
    cout << "This is a simple text based terminal RPG" << endl;
    cout << "Enter a number corresponding to a listed option to select that option" << endl;
    cout << "That's it, enjoy" << endl;

    while(true) {

        cout << "===============================" << endl;
        cout << "[1] Return to Main Menu" << endl;
        cout << "[2] Exit Game" << endl;


        cin >> userInput;

        switch(userInput) {
            case 1:
                mainMenu();
                break;
            case 2:
                exitGame();
                break;
        }
    }
}

// Exit Game function
void exitGame() {
    //save()
    std::cout << "Exiting the game...\n";
    // insert your code here
    std::cout << "Thank you for playing! Goodbye.\n";
    std::exit(0);
}

void mainMenu() {
    bool gameLoop = true;

    while(gameLoop == true) {
        cout << "===============================" << endl;
        cout << "[1] Start Game" << endl;
        cout << "[2] Load Game" << endl;
        cout << "[3] Help" << endl;
        cout << "[4] Exit" << endl;

        cin >> userInput;

        switch(userInput) {
            case 1:
                startGame();
                break;
            case 2:
                loadGame();
                break;
            case 3:
                help();
                break;
            case 4:
                exitGame();
                break; 
        }
    }

}

int main()
{

    map.setPlayer(&player);
    
    mainMenu();
    return 0;
}
