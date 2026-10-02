//main.cpp

#include <iostream>
#include "RPG.h"
using namespace std;

int main() {
    //initialzing
    RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);
    RPG p2 = RPG();

    //prints stats of players
    printf("%s Current Stats \n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());

    printf("%s Current Stats \n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());

    //calling and testing setHitsTaken
    p1.setHitsTaken(6);
    p2.setHitsTaken(7);
    cout << "\nP1 hits taken: " << p1.getHitsTaken() << endl;
    cout << "\nP2 hits taken: " << p2.getHitsTaken() << endl;

    //calling and testing isAlive
    cout << "\n0 is dead, 1 is alive" << endl;
    cout << "\nP1: " << p1.isAlive() << endl;
    cout << "\nP2: " << p2.isAlive() << endl;

    return 0;
}