#include <iostream>
#include <windows.h>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    string hi = "!hello";

    cout << ispunct(hi.at(0)) << endl;
} 