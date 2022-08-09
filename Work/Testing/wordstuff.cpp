#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<string> firstNames = {};
    vector<string> lastNames = {};
    string name;
    vector<int> order = {};

    while (true) {

        // Prompt user with "Enter First Name: "
        cout << "Enter First Name: ";
        getline(cin, name);
        if (name.empty()){
            break;
        }

          // Add to vector of First Names
        firstNames.push_back(name);
          // Prompt user with "Enter Last Name: "
        cout << "Enter Last Name: ";
        getline(cin, name);

          // Add to vector of Last Names
        lastNames.push_back(name);
          // Print out First Name and Last Name ending with newline (endl)

        cout << firstNames.back() << " " << lastNames.back() << endl;
    }
    
    return 0;
}