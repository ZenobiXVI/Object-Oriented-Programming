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
