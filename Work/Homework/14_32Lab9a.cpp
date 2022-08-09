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
private:
};

/////////////////////
////// Write Function 
double GetDistance(SpacePoint a, SpacePoint b) {
   double distance;
   ////// Your code here //////
   
   distance = sqrt(((b.xCoord - a.xCoord) * (b.xCoord - a.xCoord)) + ((b.yCoord - a.yCoord) * (b.yCoord - a.yCoord)));
   
   ////////////////////////////
   return distance;
}

int main(){
   SpacePoint point1;
   SpacePoint point2;
   int x, y;

   cin >> x >> y;
   point1.xCoord = x;
   point1.yCoord = y;
   
   cin >> x >> y;
   point2.xCoord = x;
   point2.yCoord = y;
   
   
   cout << "Distance: " << fixed << setprecision(2.0) << GetDistance(point1, point2);
   return 0;
}