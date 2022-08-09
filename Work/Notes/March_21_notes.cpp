#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

    int A[3][4];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++) {

            A[i][j] = j + 4 * i + 1;
            cout << A[i][j] << " ";

        }
        cout << endl;
    }

    char mycharA[1024] = "why don't it take in variables";

    return 0;
}