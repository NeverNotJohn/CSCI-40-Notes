#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
    system("cls");
    //Choose character name

    string userName;

    cout << "What's your name?: ";
    getline(cin, userName);
    cout << endl;

    cout << "Your name is " << userName << endl << endl;

    //Choose skills
    int strength = 1;
    int wisdom = 1;
    int intelligence = 1;
    int agility = 1;
    int luck = 1;
    int endurance = 1;
    float cock = 5.35;
    int skillpoints = 12;
    string x;
    int add;

    cout << "Choose your skills " << userName << endl;

    while (skillpoints > 0) {

        cout << "You have " << skillpoints << " skillpoints \n" << endl;
        cout << "Your strength: " << strength << endl;
        cout << "Your wisdom: " << wisdom << endl;
        cout << "Your intelligence: " << intelligence << endl;
        cout << "Your agility: " << agility << endl;
        cout << "Your luck: " << luck << endl;
        cout << "Your endurance: " << endurance << endl;
        cout << endl;

        cout << "What skill do you want to spec in?: " << endl;
        cout << "Insert: strength, wisdom, intelligence, agility, luck, or endurance: ";
        cin >> x;
        cout << endl;

        if (x == "strength") {

            cout << "How many skill points to spec in?: ";
            cin >> add;
            strength = strength + add;
            skillpoints = skillpoints - add;

        }

        if (x == "wisdom") {

            cout << "How many skill points to spec in?: ";
            cin >> add;
            wisdom = wisdom + add;
            skillpoints = skillpoints - add;

        }

        if (x == "intelligence") {

            cout << "How many skill points to spec in?: ";
            cin >> add;
            intelligence = intelligence + add;
            skillpoints = skillpoints - add;

        }

        if (x == "agility") {

            cout << "How many skill points to spec in?: ";
            cin >> add;
            agility = agility + add;
            skillpoints = skillpoints - add;

        }

        if (x == "luck") {

            cout << "How many skill points to spec in?: ";
            cin >> add;
            luck = luck + add;
            skillpoints = skillpoints - add;

        }

        if (x == "endurance") {

            cout << "How many skill points to spec in?: ";
            cin >> add;
            endurance = endurance + add;
            skillpoints = skillpoints - add;

        }

        if (x == "cock") {

            cout << "How big you want your cock?: ";
            cin >> add;
            cock = cock + (add * 0.5);
            skillpoints = skillpoints - add;

        }
        system("cls");
    }

    // Random Number Def
    int numAttack;
    float numDodge;
    float numCrit;
    int enemyNum;
    srand(time(NULL));

    // Battle def
    string action;
    string battleStatus = "ongoing";

    //Character finished:
    cout << "Welcome, " << userName << " you're kinda cool ig \n" << endl;
    cout << "Your strength: " << strength << endl;
    cout << "Your wisdom: " << wisdom << endl;
    cout << "Your intelligence: " << intelligence << endl;
    cout << "Your agility: " << agility << endl;
    cout << "Your luck: " << luck << endl;
    cout << "Your endurance: " << endurance << endl;
    cout << endl;
    
    //Equiptment def
    int statHelmet = 1;
    int statArmor = 1;
    int statWeapon = 1 + (pow(strength, 1.5)); // Debug change later

    // All equipment stats + multiplier
    int fist = 0 + (strength);
    // All weapon stats

    // Character stats def
    int charHP = 8 + (1 * endurance);
    int charArmor = 1;
    int charAD = 0 + statWeapon;
    int charMana = 10 + (2 * intelligence);
    float charSpeed = 0.0 + (4 * agility);
    float charCrit = 0.0 + (4 * luck);
    int level = 1;
    int money = 10;

    // Character equipment def
    string charHelmetName = "nothin";
    string charArmorName = "nothin";
    string charWeaponName = "fist";

    // Character Beginning equipment

    // Character beginning stats

    // Enemy def
    int enemyHP;
    int enemyArmor;
    int enemyAD;
    int enemyMana;
    float enemySpeed;
    float enemyCrit;
    string enemy;
    string enemyWeapon;

    // This your character woooo

    cout << "xp Level: " << level << endl;
    cout << "HP: " << charHP << endl;
    cout << "Armor: " << charArmor << endl;
    cout << "AD: " << charAD << endl;
    cout << "Mana: " << charMana << endl;
    cout << "Crit Chance: " << charCrit << "%" << endl;
    cout << "Dodge Chance: " << charSpeed << "%" << endl;
    cout << "You have " << money << " gold coins" << endl;
    cout << endl;

    // Ingame Time
    int xpProgress = 0;
    x = "back";

    while (x == "back"){


        // Character Update
        charHP = 8 + (level * endurance);
        charArmor = 1 + statHelmet + statArmor;
        charAD = 0 + statWeapon;
        charMana = 10 + (2 * intelligence);
        charSpeed = 0.0 + (0.02 * agility);
        charCrit = 0.0 + (0.05 * luck);
        if (xpProgress >= 10) {
            level += 1;
        }
        // User Input 
        cout << "Input: stats, battle, or cry: ";
        cin >> x; 
        system("cls");

        // stats:

        while (x == "stats") {

            cout << userName << ", you a beafy boi. Here's your stats:" << endl;
            cout << endl;

            cout << "xp Level: " << level << endl;
            cout << "xp progrees: " << xpProgress << endl;
            cout << "HP: " << charHP << endl;
            cout << "Armor: " << charArmor << endl;
            cout << "AD: " << charAD << endl;
            cout << "Mana: " << charMana << endl;
            cout << "Crit Chance: " << charCrit << endl;
            cout << "Dodge Chance " << charSpeed << "%" << endl;
            cout << "You have " << money << " gold coins" << endl;
            cout << endl;

            cout << "Helmet: " << charHelmetName << endl;
            cout << "Armor: " << charArmorName << endl;
            cout << "Weapon: " << charWeaponName << endl << endl;

            x = "back"; 

        }

        while (x == "battle") {

            // Rand choose enemy:
            enemyNum = rand() % 7;

            // Enemy stats:

            if (enemyNum == 0) {

                enemy = "dog";
                enemyHP = 5;
                enemyArmor = 1;
                enemyAD = 1;
                enemyMana = 0;
                enemySpeed = 8;

                enemyWeapon = "teef";

            }

            if (enemyNum == 1) {

                enemy = "goblin";
                enemyArmor = 1;
                enemyAD = 1;
                enemyMana = 0;
                enemySpeed = 8;

                enemyWeapon = "Iron sword";
            }

            if (enemyNum == 2) {

                enemy = "Cole, breaker of worlds, solver of calculus";
                enemyArmor = 1;
                enemyAD = 1;
                enemyMana = 0;
                enemySpeed = 8;

                enemyWeapon = "$15,000 robot";
            }

            if (enemyNum == 3) {

                enemy = "Chijlooj of the Montana Clan, swooner of Filipitoes";
                enemyArmor = 1;
                enemyAD = 1;
                enemyMana = 0;
                enemySpeed = 8;

                enemyWeapon = "hair follicle";
            }

            if (enemyNum == 4) {

                enemy = "Large Toed Joseph, sacker of tacos";
                enemyArmor = 1;
                enemyAD = 1;
                enemyMana = 0;
                enemySpeed = 8;

                enemyWeapon = "sir taco branded violin";
            }

            if (enemyNum == 5) {

                enemy = "Anuk.";
                enemyArmor = 1;
                enemyAD = 1;
                enemyMana = 0;
                enemySpeed = 8;

                enemyWeapon = "Upek";
            }

            if (enemyNum == 6) {

                enemy = "Long Legged Xingyu, destroyer of physics";
                enemyArmor = 1;
                enemyAD = 1;
                enemyMana = 0;
                enemySpeed = 8;

                enemyWeapon = "minecraft addiction";
            }

            cout << "A wild " << enemy << " appeared!" << endl;
            cout << endl;
            action = "back";

            while (battleStatus == "ongoing") {
                while (action == "back") {
                    cout << "Input check, attack, defend, or cast" << endl;
                    cout << "What would you like to do?: ";
                    cin >> action;
                    system("cls");

                    if (action == "check") {
                        cout << "Enemy HP: " << enemyHP << endl;
                        cout << "Enemy Armor: " << enemyArmor << endl;
                        cout << "Enemy AD: " << enemyAD << endl;
                        cout << "Enemy Mana: " << enemyMana << endl;
                        cout << "Enemy Dodge Chance " << enemySpeed << "%" << endl;
                        cout << endl;
                        action = "back";
                    }

                    else if (action == "attack") {



                    }
                    
                    else if (action == "defend") {


                    }

                    else {

                        cout << "You stumble and fall lmao" << endl << endl;

                    }

                }

            
            // Enemy attack:

            numAttack = rand() % 4;
            numDodge = (rand() % 101) + charSpeed;

            cout << "The " << enemy << " prepares an attack" << endl;
            cout << endl;
            cout << "The " << enemy << " swings their " << enemyWeapon << endl << endl;

            if (numDodge >= 100) {

                cout << "You do a triple backflip dodging the hell outta their attack" << endl;
                cout << endl;

            }

            else if (numDodge >= (100 - (charSpeed / 4))) {

                cout << "You narrowly dodge the attack!" << endl << endl;

            }

            else if (numDodge >= (100 - (charSpeed / 2))) {

                cout << "The attack barely scrapes you dealing " << (enemyAD / 3) << " damage" << endl << endl;
                charHP = charHP - (enemyAD / 3);
    
            }

            else { // Attack connects

                cout << "The " << enemy << "'s " << enemyWeapon << " connects dealing " << enemyAD / (1 + (charArmor / 100)) << " damage" << endl << endl;
                charHP = charHP - (enemyAD / (1 + (charArmor / 100)));

            }

            if (charHP == 0) {

                cout << "Wasted" << endl;
                exit;

            }

            if (enemyHP == 0) {

                cout << enemy << " has been defeated!" << endl;
                x = "back";
                battleStatus = "Won";

            }

            cout << userName << ", your health is now: " << charHP << endl << endl;

            }
        }


    }
    return 0;
}