#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<string> yes;

    string input;

    cout << "Create a big ass text thing idk but type \"done\" when you're done" << endl;
    cout << "Input: ";

    while (input != "done") {

        cin >> input;
        yes.push_back(input);

    }

    cout << "You're big ass string is: " << endl;

    for (int i = 0; i < yes.size(); i++) {

        cout << yes[i] << endl;

    }

    return 0;
}