#include "func.h"

using namespace std;

int main() {
    int n;

    cout << "Input array size: ";
    cin >> n;
    cout << endl;

    MyArray test(n);

    test.create();
    cout << "Size of array is: " << test.size() << endl;
    test.display();

    // User Interface:

    instructions(); // clogged up code too much

    while(true) {
        string input;
        int input2;

        cout << "Enter command or \"command\" for list of commands: ";

        cin >> input;

        cout << endl;

        if (input == "create") {
            test.create();
            cout << "array creation complete!" << endl << endl;
        }
        
        else if (input == "size") {
            cout << "Array size is: " << test.size() << endl << endl;
        }

        else if (input == "display") {
            cout << "Your array in a table: " << endl << endl;
            test.display();
        }

        else if (input == "app_begin") {
            cin >> input2;
            test.app_begin(input2);
            cout << "Appbegined!" << endl << endl;
        }

        else if (input == "app_end") {
            cin >> input2;
            test.app_end(input2);
            cout << "Appended!" << endl << endl;
        }

        else if (input == "del_begin") {
            test.del_begin();
            cout << "Beginning deleted!" << endl << endl;
        }

        else if (input == "del_end") {
            test.del_end();
            cout << "End deleted!" << endl << endl;
        }

        else if (input == "inv") {
            test.inv();
            cout << "Array reversed!" << endl << endl;
        }

        else if (input == "sum") {
            cout << "Sum of elements in the array: " << test.sum() << endl << endl;
        }

        else if (input == "sort") {
            test.sort();
            test.display();
        }
        
        else if (input == "odd_array") {
            test.odd_array();
        }

        else if (input == "find") {
            cin >> input2;
            if (test.find(input2) != -1) {
                cout << input2 << " is at index " << test.find(input2) << endl << endl;
            }

            else {
                cout << input2 << " is not in the array" << endl << endl;
            }
        }

        else if (input == "find_but_better") {
            cin >> input2;

            if (test.find_but_better(input2) != -1) {
                test.display();
                cout << input2 << " is at index " << test.find_but_better(input2) << endl << endl;
            }

            else {
                cout << input2 << " is not in the array" << endl << endl;
            }

        }

        else if (input == "command") {
            instructions();
        }

        else if (input == "exit") {
            break;
        }

        else {
            cout << "Invalid input... try again" << endl;
        }
    }

    // debug:

    return 0;
}