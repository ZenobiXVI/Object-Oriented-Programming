//main.cpp

#include <iostream>
#include "RPG.h"
#include "Game.h"
using namespace std;

int main() {
    Game zGame = Game();

    int num_players = 10;

    zGame.generatePlayer(10);

    zGame.gameLoop();

    zGame.printFinalResults();

    return 0;
}