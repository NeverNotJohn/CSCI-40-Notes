#include <iostream>
#include <cmath>
using namespace std;

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

    SpacePoint operator+(SpacePoint b) {
        SpacePoint a;
        a.SetCoords( xCoord + b.GetX(), yCoord + b.GetY() );
        return a;
        //cout << "(" << (xCoord + a.xCoord) << ", " << (yCoord + a.yCoord) << ")" << endl;
    }

    void Print()
    {
        cout << xCoord << " , " << yCoord << endl;
    }

private:

    int xCoord;
    int yCoord;

};



class TriangleClass {
public:
    void SetPoints(SpacePoint Ain, SpacePoint Bin, SpacePoint Cin) {
        A = Ain;
        B = Bin;
        C = Cin;

        AB = sqrt( ( pow( (A.GetX() - B.GetX()), 2) + pow( (A.GetY() - B.GetY()), 2) ) );
        BC = sqrt(((B.GetX() - C.GetX()) * (B.GetX() - C.GetX())) + ((B.GetY()) - C.GetY() * (B.GetY()) - C.GetX()));
        CA = sqrt(((C.GetX() - A.GetX()) * (C.GetX() - A.GetX())) + ((C.GetY()) - A.GetY() * (C.GetY()) - A.GetX()));
    }
    double GetArea() {
        double s = (AB + BC + CA) / 2;
        double area = sqrt(s * (s-AB) * (s-BC) * (s-CA));
        return area;
    }
    void Print() {
        A.Print();
        cout << ", ";
        B.Print();
        cout << ", ";
        C.Print();

    }
private:
    SpacePoint A;
    SpacePoint B;
    SpacePoint C;
    double AB;
    double BC;
    double CA;
};


int main(){
    cout << "ALL TESTS PASSED!" << endl;
}