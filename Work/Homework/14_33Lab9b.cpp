#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <ios>
using namespace std;

class SpacePoint {
public:
    int xCoord;
    int yCoord;

    double Distance(SpacePoint z) {
        double Dist;

        Dist = sqrt(((z.xCoord - xCoord) * (z.xCoord - xCoord)) + ((z.yCoord - yCoord) * (z.yCoord - yCoord)));
        return Dist;
    }

private:
};

/////////////////////
////// Write Function 

int main(){
   SpacePoint a;
   SpacePoint b;
   int x, y;

   cin >> x >> y;
   a.xCoord = x;
   a.yCoord = y;
   
   cin >> x >> y;
   b.xCoord = x;
   b.yCoord = y;
   
   
   cout << "Distance: " << fixed << setprecision(2.0) << a.Distance(b);
   return 0;
}