#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {

    bool done = false;
    int num;

    while (done != true) {
        cin >> num;

        if (num < 0) {
            cout << num << endl;
            done = true;
            break;
        }

        else {

            done = false;

        }



    }

    return 0;
}