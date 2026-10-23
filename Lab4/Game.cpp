//Game.cpp

#include "Game.h"
#include <random>

//Constructors
Game::Game() {}
Game::~Game() {}

//Accessors
/**
 * @brief Randomly selects a player (via index) from the
 *  set of alive player, live_players
 * 
 * @return int: index for vector, players
 */
int Game::selectPlayer() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() -1);

    //Pick random index
    int randomIndex = dist(gen);

    //Advance iterator to that index
    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);

    int selectedIndex = *it;
    return selectedIndex;
}
/**
 * @brief calls selectPlayer() twice to get 2 players at random. If the players are redundant
 *  make a recursive call to battleRound() and return.
 *  Run a round of hits across player 1 and player 2 until only 1 ia alive.
 *  Call endRound() to highlight who won and update stats
 */
void Game::battleRound() {
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();
    if (playerIndex1 == playerIndex2) {
        return battleRound();
    }

    RPG * player1 = players[playerIndex1];
    RPG * player2 = players[playerIndex2];

    while ((* player1).isAlive() == true && (* player2).isAlive() == true) {
        player1->attack(player2);
        if ((* player2).isAlive() == true) {
            break;
        }
        player2->attack(player1);
    }

    if ((* player1).isAlive() == true) {
        endRound(player1, player2, playerIndex2);
    } else {
        endRound(player2, player1, playerIndex1);
    }
}
/**
 * @brief Runs battleRound() until there is only 1 player alive.
 */
void Game::gameLoop() {
    while (live_players.size() >= 1) {
        battleRound();
    }
}
/**
 * @brief calls printStats fpr all players
 */
void Game::printFinalResults() {
    for (int i = 0; i < players.size(); i++) {
        (* players[i]).printStats();
    }
}

//Mutators
/**
 * @brief creates up to n RPG pointers and updates names
 *  with ordering. Populates live_players from 0 to n - 1 as
 *  all players are alive initially
 * 
 * @param n : number of players
 */
void Game::generatePlayer(int n) {
    for (int i = 0; i < n; i++) {
        players.push_back(new RPG);

        //rename players
        string new_name = "NPC_"+to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
}

/**
 * @brief Resets winner's hits_taken to 0.
 *  Removes the loser from the live_players.
 *  Calls updateExpLevel() for the winner
 *  prints the structure "NPC_X won against NPC_Y"
 * 
 * @param winner : pointer to RPG winner
 * @param loser : pointer to RPG loser
 * @param loserIndex : int index of loser, so that it can be removed from
 *                     live_players
 */
void Game::endRound(RPG * winner, RPG * loser, RPG * loserIndex) {
    (* winner).setHitsTaken(0);
    live_players.erase(* loserIndex);
    (* winner).updateExpLevel();
    printf("%s won against %s", (* winner).getName(), (* loser).getName(););
}