#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> A(6);
    int tmp;

    for (int i = 0; i < A.size(); i++) {

        cin >> A[i];
        
    }

    for (int i = 0; i < A.size() / 2; i++) {
        tmp = A[i];
        A[i] = A[A.size() - 1 - i];
        A[A.size() - 1 - i] = tmp;
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }

}