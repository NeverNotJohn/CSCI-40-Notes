#include <iostream>
#include <cmath> 
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


double Distance(double x1, double y1, double x2, double y2) {
    double dist;

    dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    return dist;
}

int main() {
    vector<double> ans = {};
    double x1 = 1, y1 = 1, x2 = 1, y2 = 1;

    while ((x1 != 0) && (x2 != 0) && (y1 != 0) && (y2 != 0)) { // take inputs of points until 0 0 0 0

        cin >> x1 >> y1 >> x2 >> y2;
        if (((x1 != 0) && (x2 != 0) && (y1 != 0) && (y2 != 0))) {
            ans.push_back(Distance(x1, y1, x2, y2));
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << fixed << setprecision(2) << ans.at(i) << endl;
    }

    return 0;
}