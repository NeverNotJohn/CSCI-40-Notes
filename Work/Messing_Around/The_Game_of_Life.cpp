#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include <vector>

using namespace std;

int main () {

    system("cls");

    string A[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            A[i][j] = "#";
            cout << A[i][j] << " ";

        }
        cout << endl;
    }




    return 0;
}