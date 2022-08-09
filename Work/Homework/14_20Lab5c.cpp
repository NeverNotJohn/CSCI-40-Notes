#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main () {

    string input;

    cin >> input;
    int inputNum = size(input);
    int counter = 0;

    while (counter < inputNum) {

        cout << "Index " << counter << ": " << input.at(counter) << endl;
        counter = counter + 1;

    }



    return 0;
}