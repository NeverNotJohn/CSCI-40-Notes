#include <iostream>
#include <string>

using namespace std;

int main() {

    int in;
    int num = 0;
    int counter = 0;
    string input;

    cin >> input;

    while (num < input.size()) {
        counter = 0;

        in = int(input.at(num) - 48);
        while (counter < in) {

            cout << "+";
            counter = counter + 1;

        }

        cout << endl;

        num = num + 1;
    }


    



    return 0;
}