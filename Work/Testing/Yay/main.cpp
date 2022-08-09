#include "func.h"

using namespace std;

int main() {
    cout << "Welcome adventurer, what is your name?: ";
    string input;
    cin >> userName;

    cout << userName << ", choose your stats: " << endl;

    int HP, AR, AD;

    cout << "HP: ";
    cin >> HP;
    cout << endl;

    cout << "AR: ";
    cin >> AR;
    cout << endl;

    cout << "AD: ";
    cin >> AD;
    cout << endl;

    stats(HP, AR, AD);

    while (input != "exit") {

        cout << userName << ", what would you like to do?" << endl;
        cout << "Input \"attack\" or \"check\"" << endl;
        
        cin >> input;

        if (input == "attack") {
            attack(HP, AR, AD);
        }

        if (input == "check") {
            check(HP, AR, AD);
        }

        if (input == "exit") {
            cout << "Till we meet again, " << userName << endl;
        }

        else {
            cout << "Invalid input, try again" << endl;
        }

    }
}