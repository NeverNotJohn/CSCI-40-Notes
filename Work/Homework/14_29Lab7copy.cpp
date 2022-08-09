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

    cout << endl << " --Sorted Names-- " << endl;

    // Sorting Mechanism

    for (int i = 0; i < lastNames.size(); i++) {
        string temp = lastNames.at(i);
        string temp2 = firstNames.at(i);
        int counter = (order.size());

        if (i == 0) { //append to beginning
            order.push_back(i);
        }

        for (int j = 0; j < counter; j++) { // check each element in order ** POSSIBLE PROBLEM HERE ** 

            if (temp == lastNames.at(order.at(j))) { // check if names are equal
                if (temp2 < firstNames.at(order.at(j))) {
                    order.insert(order.begin() + j, i);
                    // debug
                }

                else if (j == (counter - 1)) { // if last name is at end of list
                    order.push_back(i);
                }
            }

            else if (temp < lastNames.at(order.at(j))) { // check if last name is smaller  ** SOMETHING IS WRONG HERE ADDING MULTIPLE **
                order.insert((order.begin() + j), i); // insert to the left of checked index
                break; 
            }

            else if (j == (counter - 1)) { // if last name is at end of list
                order.push_back(i);
            }

            else { // continue to next in order
                continue;
            }
        }
    }

    // debug:

    // Final output
    for (int i = 0; i < order.size(); i++) {
        cout << firstNames.at(order.at(i)) << " " << lastNames.at(order.at(i)) << endl;
    }

    return 0;
}