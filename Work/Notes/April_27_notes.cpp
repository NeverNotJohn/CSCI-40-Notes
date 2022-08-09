#include <iostream>

using namespace std;

// NOTES ON POINTERS... LOWKEY CONFUSED

class myClass {
    public:
        int age;
        int x;
        int y;
        float num;

        myClass() {
            age = 1;
            x = 2;
            y = 5;
            num = 7.2;
        };
        myClass(int A) {
            age = A;
            x = A;
            y = A;
            num = (A * 1.0);
        };

        void die(int* yes, int* x) {
            yes = 0;
            x = 0;
        }

};

int main() {
    myClass *p = new myClass(); // default constructor
    myClass *p1 = new myClass(10);

    myClass yeet;

    yeet.die()

    cout << p1->age << endl;
}