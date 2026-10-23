//Game.h
#ifndef GAME_H
#define GAME_H

#include "RPG.h"
#include <vector>
#include <set>

using namespace std;

class Game{
    private:
        vector<RPG *> players;
        set<int> live_players;

    public:
        //Constructor
        Game();
        ~Game();

        //Accessors
        int selectPlayer();
        void battleRound();
        void gameLoop();
        void printFinalResults();

        //Mutators
        void generatePlayer(int n);
        void endRound(RPG * winner, RPG * loser, int loserIndex);
};

#endif GAME_H