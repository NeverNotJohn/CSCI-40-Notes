#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

    string word;
    int length;

    cin >> word;
    
    length = word.length();

    cout << word.at(0) << word.at(length/2) << word.at(length);


    return 0;
}