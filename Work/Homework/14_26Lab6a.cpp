#include <iostream>
#include <vector>
using namespace std;

int main(){
   vector<int> data(5);
   
   for (int i = 0; i < data.size(); i++) {

       cin >> data[i];

   }
   
   for (int i = 0; i < data.size(); i++) {
       for (int x = 0; x < data[i]; x++) {
           cout << "*";
       }
       cout << endl;
   }
   
   return 0;

}