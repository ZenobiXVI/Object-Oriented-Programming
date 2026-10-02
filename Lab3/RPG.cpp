//RPG.cpp

#include "RPG.h"

//Constructors
RPG::RPG() {
    string name ="NPC";
    int hits_taken = 0;
    float luck = 0.1;
    float exp = 50.0;
    int level = 1;
}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level) {
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

//Accessors
string RPG::getName() {
    return name;
}

int RPG::getHitsTaken() {
    return hits_taken;
}

float RPG::getLuck() {
    return luck;
}

float RPG::getExp() {
    return exp;
}

int RPG::getLevel() {
    return level;
}

//Mutators
/**
 * @brief returns whether hits_taken is less than MAX_HITS_TAKEN
 * In other words, a player is alive as long as they have not benn hit MAX_HITS_TAKEN times.
 * 
 * @return true : player is alive
 * @return false : player is unalive
 */
bool RPG::isAlive() {
    return hits_taken < MAX_HITS_TAKEN;
}

/**
 * @brief sets hit_taken to new_hits
 */
void RPG::setHitsTaken(int new_hits){
    hits_taken = new_hits;
}