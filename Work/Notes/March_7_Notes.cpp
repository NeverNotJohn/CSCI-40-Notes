#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*int main() {

    system("cls");

    int i = 0;

    for (i = 0; i<5; i++) {

        cout << i;
        i++;
// FUCK
    }

    cout << i;


    return 0;
}
*/

int main() {

    system("cls");

    int col;
    int row;

    cout << "Enter # of columns and rows: ";
    cin >> col;
    cin >> row;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            cout << "* ";

        }

        cout << endl;


    }



    return 0;
}