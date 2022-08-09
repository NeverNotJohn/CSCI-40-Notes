#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

    class myArray {
        public:
            //Constructors
            myArray();
            myArray(int n);
            
            //Functions
            int Size();
            void Display();
            void AddBegin(int newNum);
            void AddEnd(int newNum);
            void RemoveBegin();
            void RemoveEnd();
            void Sort();
            void Inverse();
            int ReturnSum();
            void DisplaySortedArray();
            void DisplayOdd();
            int FindIndex1(int num);
            int FindIndex2(int num);
            
            //Data Members
            int listSize;
            int numList[1000];
            bool listSorted = false;
        
    };

    //Constructors
    myArray::myArray() {
        listSize = 1000;
        numList[1000];
        
        srand(time(0));
        for (int i = 0; i < 1000; i++) {
            numList[i] = rand() % 1000 + 1;
        }
    }
    
    myArray::myArray(int n) {
        listSize = n;
        numList[n];
        
        srand(time(0));
        for (int i = 0; i < listSize; i++) {
            numList[i] = rand() % 1000 + 1;
        }
    }
    
    
    //Functions
    int myArray::Size() {
        return listSize;
    }
    
    void myArray::Display() {
        int i = 0;
        
        while (i < listSize) {
            for (int j = 0; j < 10; j++) {
                if (i >= listSize)
                    break;
                cout << setw(6) << left << numList[i];
                i++;
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void myArray::AddBegin(int newNum) {
        if (listSize == 1000) {
            cout << "Error: Cannot add to array since array is full.\n";
            return;
        }
        
        
        int tempNum1 = numList[0];
        int tempNum2;
        
        
        
        listSize++;
        
        numList[0] = newNum;
        for (int i = 1; i < listSize + 1; i++) {
            tempNum2 = numList[i];
            numList[i] = tempNum1;
            tempNum1 = tempNum2;
        }
    }
    
    void myArray::AddEnd(int newNum) {
        if (listSize != 10000) {
            numList[listSize] = newNum;
            listSize++;
        }
    }
    
    void myArray::RemoveBegin() {
        for (int i = 0; i < listSize; i++) {
            numList[i] = numList[i + 1];
        }
        listSize--;
    }
    
    void myArray::RemoveEnd() {
        numList[listSize - 1] = '\0';
        listSize--;
    }
    
    //FIX
    void myArray::Sort() {
        int x, tempNum;
        for (int i = 0; i < listSize - 1; i++) {
            x = 0;
            while (  (numList[i + x + 1] < numList[i + x])  &&  (i + x >= 0)  ) {
                tempNum = numList[i + x];
                numList[i + x] = numList[i + x + 1];
                numList[i + x + 1] = tempNum;
                x--;
            }
        }
        
        listSorted = true;
    }
    
    void myArray::Inverse() {
        if (listSorted == false) {
            cout << "List is being sorted before inverting.\n";
            Sort();
            listSorted = true;
        }
        
        int tempNum;
        
        for (int i = 0; i < listSize / 2; i++) {
            tempNum = numList[i];
            numList[i] = numList[listSize - i - 1];
            numList[listSize - 1 - i] = tempNum;
        }
        
    }
    
    int myArray::ReturnSum() {
        int sum = 0;
        for (int i = 0; i < listSize; i++) {
            sum += numList[i];
        }
        
        return sum;
    }
    
    void myArray::DisplaySortedArray() {
        myArray tempArray;
        
        for (int i = 0; i < listSize; i++) {
            tempArray.numList[i] = numList[i];
        }
        
        tempArray.Sort();
        tempArray.Display();
    }
    
    void myArray::DisplayOdd() {        //prints array with odd numbers
        myArray tempArray;
        int index = 0;
        
        for (int i = 0; i < listSize; i++) {
            if ((numList[i] % 2) == 1) {
                tempArray.numList[index] = numList[i];
                index++;
            }
        }
        
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < 10; j++) {
                if (i >= index)
                    break;
                if (numList[i] == '\0')
                    break;
                cout << setw(6) << left << tempArray.numList[i];
                i++;
            }
            
            i--;
            cout << endl;
        }
        cout << endl;
    }
    
    int myArray::FindIndex1(int num) {       //goes through each index to find first occurence of "num", array does not need to be sorted
        for (int i = 0; i < listSize; i++) {
            if (numList[i] == num) {
                return i;
            }
        }
        return -1;
    }
    
    int myArray::FindIndex2(int num) {       //sorts the array, splits the array in half until it gets to the num, returns first occurences
        int splitSize = listSize / 2, splitIndex = listSize/2;
        Sort();
        
        while (true) {
            if ( (num == numList[splitIndex]) || (splitSize == 0) ) {
                int x1 = 0, x2 = 0;
                
                while (num != numList[splitIndex + x2]) {
                    if (num > numList[splitIndex + x2]) {
                        x2++;
                        
                        if (num < numList[splitIndex + x2])
                            return -1;
                    }
                    
                    else {
                        x2--;
                        
                        if (num > numList[splitIndex + x2])
                            return -1;
                    }
                    
                    if ((splitIndex + x2 > listSize) || (splitIndex + x2 < 0))
                        return -1;
                }
                
                while (numList[splitIndex + x1 + x2] == num)
                    x1--;
                x1++;
                
                return splitIndex + x1 + x2;
            }
            
            else if (num > numList[splitIndex]){
                splitIndex += splitSize/2;
            }
            
            else {
                splitIndex -= splitSize/2;
            }
            splitSize /= 2;
        }
    }
    
    
    
    

int main()
{
    myArray numList1;
    string inputString;
    
    cout << "Enter any function below.  Enter 'quit' to exit the program any time.\n\n";
    cout << "'size': Returns the size of the array.\n'display': Prints out the array.\n";       //size and display
    cout << "'aFirst': Adds a number to the beginning of the array.  Enter the number you wish to add after using this function.\n";       //add functions
    cout << "'aEnd': Adds a number to the end of the array.  Enter the number you wish to add after using this function.\n";       
    cout << "'rFirst': Removes the first number of the array.\n'rEnd': Removes the last number of the array.";      //remove functions
    cout << "'sort': Sorts array numerically.\n'inverse': Sorts and inverts array.\n'sum': Returns sum of array.\n";
    cout << "'displaySorted': Displays sorted array without changing original array.\n";
    cout << "'displayOdd': displays odd numbers\n";
    cout << "'find1': Finds first occurence of a number.  Enter the number you wish to find after using this function.\n";
    cout << "'find2': Finds first occurence of a number after sorting the list.  Enter the number you wish to find after using this function.\n\n";
    
    cout << "Enter a command: ";
    cin >> inputString;
    
    while (inputString != "quit") {
        
        if (inputString == "size") {
            cout << "\tSize of array: " << numList1.Size() << endl;
        }
        
        else if (inputString == "display") {
            cout << "Array contents:\n";
            numList1.Display();
        }
        
        else if (inputString == "aFirst") {
            int inputNum;
            cout << "Please enter a value to add: ";
            cin >> inputNum;
            
            numList1.AddBegin(inputNum);
        }
        
        else if (inputString == "aEnd") {
            int inputNum;
            cout << "Please enter a value to add: ";
            cin >> inputNum;
            
            numList1.AddEnd(inputNum);
        }
        
        else if (inputString == "rFirst") {
            numList1.RemoveBegin();
            cout << "First item has been removed.\n";
        }
        
        else if (inputString == "rEnd") {
            numList1.RemoveEnd();
            cout << "Last item has been removed.\n";
        }
        
        else if (inputString == "sort") {
            numList1.Sort();
            cout << "Array has been sorted.\n";
        }
        
        else if (inputString == "displaySorted") {
            cout << "Sorted Array contents:\n";
            numList1.DisplaySortedArray();
        }
        
        else if (inputString == "displayOdd") {
            cout << "Odd values:\n";
            numList1.DisplayOdd();
        }
        
        else if (inputString == "find1") {
            int inputNum;
            cout << "Enter a value to find: ";
            cin >> inputNum;
            if (numList1.FindIndex1(inputNum) == -1)
                cout << "\tERROR: Could not find '" << inputNum << "' in the array.\n";
            
            else
                cout << "\tFirst occurence: " << numList1.FindIndex1(inputNum) << endl;
        }
        
        else if (inputString == "find2") {
            int cont;
            cout << "Notice: Array will be sorted.  Enter '1' to continue and any other number to return: ";
            cin >> cont;
            
            if (cont == 1) {
                int inputNum;
                cout << "Enter a value to find: ";
                cin >> inputNum;
                if (numList1.FindIndex2(inputNum) == -1)
                    cout << "\tERROR: Could not find '" << inputNum << "' in the array.\n";
                
                else
                    cout << "\tFirst occurence: " << numList1.FindIndex2(inputNum) << endl;
            }
        }
        
        else {
            cout << "\nPlease enter a valid command: ";
            cin >> inputString;
            continue;
        }
        
        cout << "\nEnter a command: ";
        cin >> inputString;
        
    }
    
    

    return 0;
}

