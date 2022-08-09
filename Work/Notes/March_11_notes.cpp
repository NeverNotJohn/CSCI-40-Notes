#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*int main() {
    
    int A[5];

    A[0] = 1;
    A[1] = 2;
    A[4] = 13589174;
    A[5] = -123;

    cout << A[3] << endl;

    return 0;
}
*/

int main() {
    system("cls");
    long long int input;
    long long int i;

    cout << "Insert 2 values: ";
    cin >> input >> i;
    long long int A[i];

    for (int x = 0; x < i; x++) {
        A[x] = pow(input, x);
        cout << A[x] << endl;
    }

    cout << A[1] << endl;

    return 0;
}