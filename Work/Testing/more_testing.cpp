#include <iostream>
#include <windows.h>

using namespace std;

void ClearScreen() {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;
}

int main() {

    int x;
    cout << "LOTS AND LOTS OF STUFF";

    cout << "Insert Input: ";
    cin >> x;

    return 0;

}