//RPG.h
#ifndef RPG_H
#define RPG_H

#include <string>
using namespace std;

const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;

class RPG {
    private:
        string name;
        int hits_taken;
        float luck;
        float exp;
        int level;

    public:
        //Constructor
        RPG();
        RPG(string name, int hits_taken, float luck, float exp, int level);
        ~RPG();

        //Accessors
        string getName();
        int getHitsTaken();
        float getLuck();
        float getExp();
        int getLevel();
        bool isAlive();
        void printStats();

        //Mutators
        void setHitsTaken(int new_hits);
        void setName(string name);
        void updateExpLevel();
        void attack(RPG * oppenent);
};

#endif