#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {

    long long int num;
    long long int out;
    bool prime;
    long long int div;

    cin >> num;

    if (num % 2 == 0 || num % 3 == 0 || num % 4 == 0 || num % 5 == 0 || num % 6 == 0 || num % 7 == 0 || num % 8 == 0 || num % 9 == 0 && (num != 2 && num != 5 && num != 7 && num != 3)) {

        if (num != 1 && num != 2 && num != 3 && num != 5 && num != 7) {
                prime = false;
                cout << 1 << endl;
                div = num;

            }

        else {

        prime = true;
        cout << "PRIME" << endl;

    }
    

    }

    else {

        prime = true;
        cout << "PRIME" << endl;

    }


    if (prime == false) {
        while (div != 1) {

            div = div - 1;
            if (num % div == 0)
                cout << num / div << endl;   
        } 

    }







    return 0;
}