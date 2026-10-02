//RPG.h
#ifndef RPG_H
#define RPG_H

#include <string>
using namespace std;

const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN =3;

class RPG {
    public:
        //Constructor
        RPG();
        RPG(string name, int hits_taken, float luck, float exp, int level);

        //mutators
        bool isAlive();
        void setHitsTaken(int new_hits);

        //accessors
        string getName();
        int getHitsTaken();
        float getLuck();
        float getExp();
        int getLevel();

    private:
        string name;
        int hits_taken;
        float luck;
        float exp;
        int level;
};

#endif