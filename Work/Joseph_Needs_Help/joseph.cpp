#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int Joseph_Igot(int a, int b) {
    int sum;
    
    sum = a + b;

    return sum;
}

string print_balls() {
    cout << "haha balls" << endl;
    return "hdshfkjsdkjgsdg"; 
}

void print_balls2() {
    cout << "haha balls" << endl;
}

void printfunc(string a, string b, string c) {
    for (int i = 0; i < 52; i++) {
        cout << a;
        for (int j = 0; j < 23; j++) {
            cout << b;
            for (int k = 0; k < pow(2, 10); k++) {
                cout << c;
            }
        }
    }
}

int main() {

    int z, x;

    cout << "Input 2 numbers: ";
    cin >> z >> x;

    cout << "sum is " << Joseph_Igot(z, x) << endl;
    cout << print_balls() << endl;
    print_balls2();

    string a, b, c;

    cout << "input 3 memory strings to destroy your computer: ";
    cin >> a >> b >> c;
    
    printfunc(a, b, c);

    return 0;
}