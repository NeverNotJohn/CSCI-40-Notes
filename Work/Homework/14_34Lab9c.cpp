#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <ios>
using namespace std;


/////////////////////
////// Write SpacePoint Class Definition 

class SpacePoint {
public:

    void SetCoords(int pog, int nice) {
        xCoord = pog;
        yCoord = nice;
    }

    int GetX() {
        return xCoord;
    }

    int GetY() {
        return yCoord;
    }

private:

    int xCoord;
    int yCoord;

};

double GetDistance(SpacePoint a, SpacePoint b) {
   double distance;
   ////// Your code here //////
   
   distance = sqrt(((b.GetX() - a.GetX()) * (b.GetX() - a.GetX())) + ((b.GetY() - a.GetY()) * (b.GetY() - a.GetY())));
   
   ////////////////////////////
   return distance;
}

/////////////////////////////////////////
int main(){
   SpacePoint point1;
   SpacePoint point2;
   int x, y;

   cin >> x >> y;
   point1.SetCoords(x,y);

   cin >> x >> y;
   point2.SetCoords(x,y);
   
   
   cout << "Distance: " << fixed << setprecision(2.0) << GetDistance(point1, point2);
   return 0;
}