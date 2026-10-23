//RPG.cpp

#include "RPG.h"
#include <random>

//Constructors
RPG::RPG() {
    this->name = "NPC"; //"NPC" was not printing out when using string instead of the pointer
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

RPG::~RPG() {};

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

/**
 * @brief returns whether hits_taken is less than MAX_HITS_TAKEN
 * In other words, a player is alive as long as they have not benn hit MAX_HITS_TAKEN times.
 * 
 * @return true : player is alive
 * @return false : player is unalive
 */
bool RPG::isAlive() {
    return hits_taken > MAX_HITS_TAKEN;
}

/**
 * @brief Prints stats of character in format:
 * 
 * Name: NPC_X  Hits Taken: X Luck: 0.X0000 Exp: X0.000    Level: X Status: Alive or Dead
 */
void RPG::printStats() {
    printf("NPC_%s\tHits Taken: %i\tLuck: %u\tExp: %u\tLevel: %i\tStatus: %b", name, hits_taken, luck, exp, level);
}

//Mutators
/**
 * @brief sets hit_taken to new_hits
 */
void RPG::setHitsTaken(int new_hits){
    hits_taken = new_hits;
}

/**
 * @brief increase RPG's experience by 50
 *        After updating, if RPG's experience is >= 100.0, increase
 *        RPG;s level by 1, reset their experience to 0, and increase
 *        their luck by 1.0
 */
void RPG::updateExpLevel() {
    exp += 50.0;
    if (exp >= 100.0) {
        level += 1;
        exp = 0;
        luck += 0.1;
    }
}

/**
 * @brief Hits or misses the opponent at random. Luck is a form of defenese.
 * The higher the opponent's luck, the more likely the attack will miss.
 * If the attack is a hit, opponent's hits taken should increment by 1.
 * Add last couple of lines to complete
 * 
 * @param opponent: RPG *
 */
void RPG::attack(RPG * opponent) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    bool hit = false;
    if (random_num > HIT_FACTOR * (*opponent).getLuck()) {
        hit = true;
    }
    if (hit) {
        (* opponent).updateHitsTaken();
    }
}