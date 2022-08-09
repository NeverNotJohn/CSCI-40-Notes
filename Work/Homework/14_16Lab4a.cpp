#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {

    string completeStr;
    string searchStr;
    int find = completeStr.find(searchStr);

    cout << "Insert input: ";

    cin >> completeStr;
    cin >> searchStr;

    if (find > 0) {

        cout << "yes" << endl;

    }

    else {

        cout << "no" << endl;

    }

    return 0;
}