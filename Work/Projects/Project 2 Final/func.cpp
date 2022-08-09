#include "func.h"


using namespace std;

MyArray::MyArray() {
    srand(time(NULL));
    arr_size = 1000;
    array[arr_size];
    
} // default

MyArray::MyArray(int n) {
    srand(time(NULL));
    arr_size = n;
    array[arr_size];
}

MyArray::~MyArray() {}

// Regular Functions: 

void MyArray::create() {
    for (int i = 0; i < arr_size; i++) {
        array[i] = ((rand() % 1000) + 1);
    }
} // store rand nums

int MyArray::size(){ 
    return arr_size;
}

void MyArray::display(){ 
    for (int j = 0; j < arr_size;) {
        for (int i = 0; (i < 10 && j < arr_size); i++) { // column
            cout << setw(7) << left << array[j];
            j++;
            }
        cout << endl;
    }
    cout << endl;
} // creates table


void MyArray::app_begin(int in) { 

    int new_array[arr_size + 1]; // temp array
    new_array[0] = in; // adds first index to temp array

    for (int j = 1; j < (arr_size + 1); j++) { // adds everything else to temp array
        new_array[j] = array[j - 1];
    }

    arr_size++; // increases array size (to stay consistent with other functions)
    array[arr_size]; 

    for (int q = 0; q < arr_size; q++) { // copys new array into old array
        array[q] = new_array[q];
    }

} // i to beginning


void MyArray::app_end(int end){ 
    
    int new_array[arr_size + 1];
    new_array[arr_size] = end;
    
    for (int j = 0; j < arr_size; j++) {
        new_array[j] = array[j];
    }

    arr_size++;
    array[arr_size];

    for (int z = 0; z < arr_size; z++) {
        array[z] = new_array[z];
    }

} // append

void MyArray::del_begin(){ 

    int new_array[arr_size - 1];
    new_array[arr_size - 2] = array[arr_size - 1]; // last of new arr becomes last index of old arr
    
    for (int j = 1; j < arr_size - 1; j++) { // shifts temp one left
        new_array[j - 1] = array[j];
    }

    arr_size--;
    array[arr_size];

    for (int z = 0; z < arr_size; z++) { // copies temp back to og
        array[z] = new_array[z];
    }

} // delete begin

void MyArray::del_end(){ 

    int new_array[arr_size - 1];

    for (int j = 0; j < arr_size - 1; j++) {
        new_array[j] = array[j];
    }

    arr_size--;
    array[arr_size];

    for (int z = 0; z < arr_size; z++) {
        array[z] = new_array[z];
    }

} // delete end

void MyArray::inv(){ 
    int new_array[arr_size];
    for (int i = (arr_size - 1); i >= 0; i--) { // iterate from the back
        new_array[(arr_size-1) - i] = array[i];
    }

    array[arr_size];

    for (int i = 0; i < arr_size; i++) { // copies new back to old
        array[i] = new_array[i];
    }

} // inverse the order of array


int MyArray::sum(){ 
    int summ = 0;

    for (int i = 0; i < arr_size; i++) {
        summ += array[i];
    }

    return summ;
} // returns sum of elements in array

// Creator Functions: 

void MyArray::sort() {

   int temp;

   	for (int i = 0; i < arr_size; i++) {	// iterates thru og array
    
		for (int j = i + 1; j < arr_size; j++) { // iterates thru every other term after
			if (array[i] > array[j]) {
				temp = array[i]; // switcheronie pt 1
				array[i] = array[j];
				array[j] = temp; //switcheronie pt 2
			}
		}
	}

}


void MyArray::odd_array() {
    int counter = 0;
    int temp[arr_size];
    
    int count = 0;
    for (int i = 0; i < arr_size; i++) { // copys odd #'s to old arr
        if ( (array[i] % 2) == 1) {
            temp[count] = array[i];
            count++;
        }
    }

    cout << "Odd Numbers: " << endl;

    // DISPLAY FUNC:
    for (int j = 0; j < count;) {
        for (int i = 0; (i < 10 && j < count); i++) { // column
            cout << setw(8) << left << temp[j];
            j++;
            }
        cout << endl;
        cout << endl;
    }
}

// Finder Functions

int MyArray::find(int e) { // ASK WHAT HAPPENS IF INT IS IN MULTIPLE INDEXES
    for (int i = 0; i < arr_size; i++) { // iterate thru whole new arr
        int temp = array[i];

        if (e == temp) {
            return i;
            break;
        }

        else {
            continue;
        }
    }
    return -1; // not found
}



int MyArray::find_but_better(int e) {
    // after array is sorted **
    
    sort();
    int min = 0, max = arr_size - 1, counter = 0, mid = ( min + max ) / 2;

    // find mid

    while (true) {

        if (e < array[mid]) {
            if (max == mid) { // not in array
                return -1;
            }
            max = mid;
            mid = ( (min + max) / 2);
        }

        else if (array[mid] < e) {
            if (min == mid) {
                return -1;
            }
            min = mid;
            mid = ( (min + max) / 2) + ( (min + max) % 2);
        }

        else if ( e == array[mid] ) { // it is it
            return mid;
        }
    }
}

void instructions() {
    cout << endl;
    cout << "Commands: " << endl << endl;
    cout << "\"create\" to recreate array" << endl;
    cout << "\"size\" to display size" << endl;
    cout << "\"display\" to display array in a table" << endl;
    cout << "\"app_begin\" followed by an integer to add the integer to the beginning of the array" << endl;
    cout << "\"app_end\" followed by an integer to add the interger to the end of the array" << endl;
    cout << "\"del_begin\" to delete the first integer of the array" << endl;
    cout << "\"del_end\" to delete the last integer of the array" << endl;
    cout << "\"inv\" to inverse the order of the array" << endl;
    cout << "\"sum\" to display the sum of elements in the array" << endl;
    cout << "\"sort\" to sort the array from least to greatest then diplays" << endl;
    cout << "\"odd_array\" to output the odd numbers of the array" << endl;
    cout << "\"find\" followed by an integer to find the index of the integer in the array" << endl;
    cout << "\"find_but_better\" followed by an integer to sort the array and do find function but better :3" << endl;
    cout << "\"exit\" to exit... duh :P" << endl << endl;
}