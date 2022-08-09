#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

vector<int> GenData(int n) {
//should generate n random values and return them.
    srand(22);
    vector<int> r = {};
    for (int i = 0; i < n; i++) {
        r.push_back(rand() % 101);
    }
    
    return r;
}

double Mean(vector<int> d){
   unsigned int i;
   double sum = 0;
   for (i = 0; i < d.size(); i++) {
       sum = sum + d.at(i);
   }
   double mean = sum / d.size();
   return mean;
}
//return mean of all values in vector.
     
   
double Variance(vector<int> v) {
    double sum;
    double n = v.size();
    double mean = Mean(v);
    for (int X = 0; X < n; X++) {
        int sq_sum = (v.at(X) - mean);
        sum += sq_sum * sq_sum;
    }
    double variance = sum/n;
    return variance;
}


int main(){
   int i;
   vector<int> d;
   d = GenData(100);
 
   for (i = 0; i < 10; i++) {
        cout << d.at(i) << ", " ;  
   }
   cout << endl;
   
   cout << "Mean=" << Mean(d) << endl;
   cout << "Variance=" << Variance(d) << endl;

   return 0;
}
   