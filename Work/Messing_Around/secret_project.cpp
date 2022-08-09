#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>

using namespace std;

int main () {

    system("cls");

    // Random #:
    
    srand(time(NULL));

    // Definitions:
    string step = "main";
    int swoon = 0;
    int day = 1;
    int msg = rand() % 4;
    int msgMax = 0;
    int msgNum = 0;

    

    /* Note pad:

    Day system:
        5 days to get a date

    Characters:
        Sarpegone
        Mr. Darcy
        Chijlooj of the Montana Clan
        Anuk
        Xingyu
        Cole

    Main screen:
        Visit Location:
            - the union
            - computer lab
            - front of UHS
            - troy
            - 
    */

    // Welcome Message
    cout << "*** Wassup you degenerate ***\n** To the Dating Simulator **" << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

    string userName;

    cout << "What is your name?: ";
    getline(cin, userName);
    system ("cls");

    cout << "Wassup " << userName << " why are you here .-.";
    cout << endl << endl << endl;
    cout << "I'm doing this to make my friends uncomfortable" << endl;
    system("pause");
    system("cls");
    

    // Main Menu

    while (step == "main") {

        cout << "************  Main Menu  ************" << endl << endl;

        cout << "       .....           ....." << endl;
        cout << "   ,ad8PPPP88b,     ,d88PPPP8ba," << endl;
        cout << "  d8P\"      \"Y8b, ,d8P\"      \"Y8b" << endl;
        cout << " dP'           \"8a8\"           `Yd" << endl;
        cout << " 8(              \"              )8" << endl;
        cout << " I8                             8I" << endl;
        cout << "  Yb,                         ,dP" << endl;
        cout << "   \"8a,                     ,a8\"" << endl;
        cout << "     \"8a,                 ,a8\"" << endl;
        cout << "       \"Yba             adP\"" << endl;
        cout << "         `Y8a         a8P'" << endl;
        cout << "           `88,     ,88'" << endl;
        cout << "             \"8b   d8\"" << endl;
        cout << "              \"8b d8\"" << endl;
        cout << "               `888'" << endl;
        cout << "                 \"" << endl << endl << endl;
        
        // Rand Messages at start of day
        if (day == 1) {
            msgMax = rand() % 2;

            while (msgNum < msgMax) {
                msg = rand() % 4;
                msgNum = msgNum + 1;
            
                
                if (msg == 0) {


                }

                if (msg == 1 ) {

                    

                }

                else if (msg == 2) {


                }

                else if (msg == 3) {



                }
            }
        }


        // Beginning waking up message

        if (day == 1) {

            cout << "You are met with the glaring rays of the sun as you slowly open you eyes. It's a Monday and your lazy ass is late for school. Panicked, you think about what to do" << endl;

        }

        cout << userName << ", what would you like to do?" << endl << endl;
        cout << "You have " << msgNum << " new messages" << endl << endl;
        cout << "Input: travel, phone, or sleep: " << endl;
        cin >> step;

        while (step == "phone") {

            cout << "Checking your phone, you see " << msgNum << " new messages" << endl;

            if (msgNum == 0) {
                cout << "Haha loner";
            }

            step = "main";
            system("cls");
        }

        
        while (step == "travel") { // Travel
            system("cls");
            string location;

            cout << userName << ", you get out of bed, put your shoes on, and get ready to leave" << endl << endl;
            cout << "Where to?";
            system("pause");

        }

        system("cls");
        step = "main";
    }

    



    return 0;
    
}