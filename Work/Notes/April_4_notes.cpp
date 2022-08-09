#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class myClass { // Class definition
    public: // within brackets AND LOWERCASE
        int A = 0;
        int B = 0;
        void func(); // Can access PRIVATE

        // Mutator Function (Setter):
        void mutator() {
            D = 100;
        }

        // Accessor Function (Getter):
        int access() {
            return D;
        }

    private: // can't be accessed in main
        int D = 1; 
        int x = 1;
        void funcX(); // Functions can be defined in classes

}; // SEMI COLON AT END

int main() {

    myClass pog; // defining new OBJECT
    myClass nice;

    cout << pog.A << endl; // accesses int A in public for pog
    pog.func(); // accesses func(), outputs nothing bc its empty

    // cout << pog.D << endl; // WILL PRODUCE ERROR bc D is private and cannot be accessed here



    return 0;
}