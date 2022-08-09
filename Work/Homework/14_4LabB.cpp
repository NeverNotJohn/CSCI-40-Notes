#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    float weight;
    float distance;
    float price;

    cin >> weight >> distance;

    if (weight <= 0) {

        cout << "ILLEGAL WEIGHT:BELOW MINIMUM";

    }

    else if (weight > 20) {

        "ILLEGAL WEIGHT: ABOVE MAXIMUM";

    }

    //Distance

    if (distance < 10 && distance > 3000){

        cout << "ILLEGAL DISTANCE";

    }

    //calculates price
    else if (weight <= 2) {

        price = (distance/500.0) * 1.10;
        cout << fixed << setprecision(2) << price;

    }

    else if (weight > 2 && weight < 6) {

        price = (distance/500.0) * 2.20;
        cout << fixed << setprecision(2) << price;
        
    }

    else if (weight > 6 && weight < 10) {

        price = (distance/500.0) * 3.70;
        cout << fixed << setprecision(2) << price;
        
    }

    else if (weight <= 2) {

        price = (distance/500.0) * 4.80;
        cout << fixed << setprecision(2) << price;
        
    }

    return 0;
}