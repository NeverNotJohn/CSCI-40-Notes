#ifndef func_h
#define func_h

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

class MyArray {
    public:
        int arr_size;
        int* array = new int[100000];
        
        // big boy: int* array = new int[100000];

        // Constructors
        
        MyArray();
        MyArray(int n);
        ~MyArray();

        // Functions:
        void create(); // store rand nums
        int size();
        void display(); // creates table
        void app_begin(int in); // i to beginning
        void app_end(int end); // append
        void del_begin(); // delete begin
        void del_end(); // delete end
        void inv(); // inverse the order of array
        int sum(); // returns sum of elements in array

        // Creator Functions:
        void sort(); // couts array numbers in sorted order
        void odd_array(); // couts array with only odd numbers
        
        // Finder functions
        int find(int e); // finds int e within array... couts index where element is found or "NOT IN ARRAY"... make it inefficient D;, checks eachi index 1 by 1
        int find_but_better(int e); // same func, but uses "phonebook" technique (checks mid, see if its bigger or smaller, then rinse and repeat until found index) :D

        
};

void instructions();

#endif