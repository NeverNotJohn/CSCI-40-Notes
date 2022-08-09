#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;

int main() {

    vector<double> x(10);
    vector<double> y(10);
    double sX = 0;
    double sY = 0;
    double sXX = 0;
    double sXY = 0;
    double sYY = 0;
    double a;
    double b;
    double xproduct = 0;
    double yproduct = 0;

    for (int i = 0; i < 10; i++) {
        cin >> x[i];
        cin >> y[i];
    }

    // Output

    for (int i = 0; i < 10; i++) {
        sX = sX + x[i];
    }

    cout << fixed << setprecision(2) << "sX=" << sX << endl;

    for (int i = 0; i < 10; i++) {
        sY = sY + y[i];
    }
    
    cout << fixed << setprecision(2) << "sY=" << sY << endl;

    for (int i = 0; i < 10; i++) {
        sXX = sXX + (pow(x[i], 2));
    }

    cout << fixed << setprecision(2) << "sXX=" << sXX << endl;

    for (int i = 0; i < 10; i++) {
        xproduct = x[i] * y[i];
        yproduct = yproduct + xproduct;
    }

    cout << "sXY=" << yproduct << endl;

    for (int i = 0; i < 10; i++) {
        sYY = sYY + (pow(y[i], 2));
    }

    cout << fixed << setprecision(2) << "sYY=" << sYY << endl;

    b = (yproduct - ((sX*sY)/10) ) / (sXX-((sX*sX)/10))  ;

    a = (sY/x.size()) - b*(sX/x.size());

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    return 0;
}