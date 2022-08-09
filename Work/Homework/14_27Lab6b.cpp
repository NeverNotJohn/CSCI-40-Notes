#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> data(5);
    vector<int> atad(5);


    for (int i = 4; i >= 0; i--) {

       cin >> atad[i];

   }


    for (int i = 0; i < atad.size(); i++) {
       for (int x = 0; x < atad[i]; x++) {
           cout << "*";
       }
       cout << endl;
   }

    return 0;
}