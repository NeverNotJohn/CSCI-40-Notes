#include "func.h"

using namespace std;

void stats(int& HP, int& AR, int& AD) {
}

void attack(int& HP, int AR, int AD) {
    HP = HP - (AD * (1/AR));
    cout << "Bitch" << ",your health is now " << HP;
}

void check(int HP, int AR, int AD) {
    cout << "So, " << "Bitch" << "your stats: ";
    cout << "HP is " << HP << endl;
    cout << "AR is " << AR << endl;
    cout << "AD is " << AD << endl;
}


