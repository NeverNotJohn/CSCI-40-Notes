#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

class Base {
    public:
        vector<int> InitV;
        int M;
        int i;
    
    void tabcode(int num_tabs) {
        printf("%*s", num_tabs * 8, "");
    }
    
    //Swap
    void swap(vector<int>& InitV, int a, int b) {
        int temp =  InitV.at(a);
        InitV.at(a) = InitV.at(b);
        InitV.at(b) = temp;
    }

    //Insertion sort
    void insertionSort(vector<int>& InitV) {
        int i, j;
        int size = InitV.size();
        for(i=0; i<size; i++) {
            j = i;
            while(j>0 && InitV.at(j-1)>InitV.at(j)) {
                swap(InitV, j, j-1);
                j-=1;
            }
            
        }
    }
    
    void insertionSort2(vector<int>& input) {
        int temp;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            
            for (int j = i + 1; j < size; j++) {
                if (input.at(i) > input.at(j)) { // temp is more, switcherino
                    temp = input.at(i);
                    input.at(i) = input.at(j);
                    input.at(j) = temp;
                }
            }
            
        }
        
    }
    /*void insertionSort(vector<int> InitV) {
        //For the i-iteration we suppose the vector to be sort for the i-1 first value we insert the i-value into the i-1 value to keep it sort
        for (unsigned int i = 1; i < M; ++i) {
            int value = InitV.at(i);
            int k = i;
            while (k > 0 && InitV.at(k - 1) > value) {
                InitV.at(k) = InitV.at(k - 1);
                k--;
            }
            InitV.at(k) = value;
    
        }
        //Time complexity : O(n^2) where n is the size of the vector in the worst case, in the best case O(n)
    }*/
    
    //Bubble sort
    void bubbleSort(vector<int>& InitV) {

        int size = InitV.size();
        //bool noswap = false;
        for (int i = 0; i < size; i++) {// replace with while i<n and !noswap
            //noswap=true;
            for (int j = i + 1; j < size; j++) {//can improve this
                if (InitV.at(j) < InitV.at(i)) {
                    swap(InitV, j, i);
                    //noswap = false;
                }
            }
            //i++;
        }
    }

    //Selection sort
    void selectionSort(vector<int>& InitV) {
        int i, j;
        int size = InitV.size();

        for (i=0; i<size; i++) {
            int minloc = InitV.at(i);
            for (j=i+1; j<size; j++) {
                if (InitV.at(j) < InitV.at(minloc)) {
                    minloc = j;
                }
            }
            if (minloc != i) {
                swap(InitV, i, minloc);
            }
        }
    }

    //Quick sort
    int partition(vector<int> InitV, int low, int high, int num_tabs) {
        int pivot = InitV.at(high);    // pivot , chosing the last element
        tabcode(num_tabs);
        cout << "Pivot element:  " << pivot << endl;
        int pindex = (low - 1); // partition index
        
        for (int j = low; j <= high - 1; j++) {
            tabcode(num_tabs); cout << "J :  " << j << endl;
            if (InitV.at(j) <= pivot) {
                pindex++;
                tabcode(num_tabs); cout << "Increment Pivot Index : " << pindex << endl;
                tabcode(num_tabs); cout << "SWAP -  " << InitV.at(pindex) << " and "<< InitV.at(j) << endl;
                swap(InitV, InitV.at(pindex), InitV.at(j));
                tabcode(num_tabs);
                for (int i = low; i <= high-1; i++) {
                    cout << InitV.at(i) << "\t";
                }
                cout << endl;
            }
        }
        tabcode(num_tabs); cout << "Final Pivot Index : " << pindex + 1 <<endl;
            tabcode(num_tabs); cout << "FINAL PLACEMENT-  SWAP-" << InitV.at(pindex + 1) << " and " << InitV.at(high) << endl;
            swap(InitV, InitV.at(pindex + 1), InitV.at(high));
            tabcode(num_tabs);
            for (int i = low; i <= high; i++)
            {
                cout << InitV.at(i) << "\t";
            }
            cout << endl;
            return (pindex + 1);
        }
    
    void quickSort(vector<int> InitV, int low, int high, int num_tabs) {
        tabcode(num_tabs); cout << "Low = " << low << " High = " << high << endl;
        tabcode(num_tabs);
        for (int i = low; i < high; i++) {
            cout << InitV.at(i) << "\t";
        }
        cout << endl;
        if (low < high) {
            tabcode(num_tabs); cout << "Calling Partition" << endl;
            int pindex = partition(InitV, low, high,num_tabs);
            tabcode(num_tabs); cout << "Pivot Index (recvd):  " << pindex << endl;
            tabcode(num_tabs); cout << " Left array : ";
            for (int i = low; i < pindex; i++) {
                cout << InitV.at(i) << "\t";
            }
            cout << "  Right array :  ";
            for (int i = pindex + 1; i <= high; i++) {
                cout << InitV.at(i) << "\t";
            }
            cout << endl;
            
            tabcode(num_tabs); cout << "Calling Quick Sort (Left)  : " << endl;
            quickSort(InitV, low, pindex - 1,num_tabs+1);
            tabcode(num_tabs); cout << "Calling Quick Sort (Right) : " << endl;
            quickSort(InitV, pindex + 1, high,num_tabs+1);
        }
    }

    //Merge sort
    void mergeSort(vector<int> InitV, int low, int high, int num_tabs) {
        //tabcode(num_tabs); cout << "*In mergesort :  " << endl;
        tabcode(num_tabs); cout << "Low = " << low << " High = " << high << endl;
        int mid;
        if (low < high) {
            mid = (low + high) / 2;
            tabcode(num_tabs); cout << "Calling mergesort (Left) : " << endl;
            mergeSort(InitV, low, mid,num_tabs+1);
            tabcode(num_tabs); cout << "Calling mergesort (Right)  : " << endl;
            mergeSort(InitV, mid + 1, high,num_tabs+1);
            tabcode(num_tabs); cout << "Calling merge : " << endl;
            merge(InitV, low, high, mid,num_tabs);
        }
    }
    void merge(vector<int> InitV, int low, int high, int mid,int num_tabs) {
        tabcode(num_tabs); cout << "Low = " << low << " Mid = " << mid << " High = " << high << endl;
        
        tabcode(num_tabs); cout << "Left sub-Array : ";
        for (int i = low; i <= mid; i++) {
            cout << InitV.at(i) << "\t";
        }
        cout << " Right sub-Array : ";
        for (int i = mid+1; i <= high; i++) {
            cout << InitV.at(i) << "\t";
        }
        cout << endl;
        int i, j, k;
        vector<int>c(M); // c is the temp array, on which we place sorted elements
        i = low; // the index on left, sorted array
        k = low; //index on the temp array
        j = mid + 1; // the index on right, sorted array.
        while (i <= mid && j <= high) {
            if (InitV.at(i) < InitV.at(j)) {
                c.at(k) = InitV.at(i);
                k++;
                i++;
            }
            else {
                c.at(k) = InitV.at(j);
                k++;
                j++;
            }
        }
        while (i <= mid) {
            c.at(k) = InitV.at(i);
            k++;
            i++;
        }
        while (j <= high) {
            c.at(k) = InitV.at(j);
            k++;
            j++;
        }
        //copying everything back to original array from temp array.
        for (i = low; i < k; i++) {
            InitV.at(i) = c.at(i);
        }
        tabcode(num_tabs); cout << "--Merged array in this call---  " << endl;
        //tabcode(num_tabs); cout << "Low = " << low << " High = " << high << endl;
        tabcode(num_tabs);
        for (i = low; i < k; i++) {
            cout << InitV.at(i) << "\t";
        }
        cout << endl;
    }
};

int main() {
    // code to initialize random array/vector of 10,000,000 elements. InitV
    int i, j;
    int M = 10000000;
    vector<int> InitV(M);
    Base Base;
    
    srand(time(0));
    for(i=0; i<M; i++) {
        InitV.at(i) = rand() % (100-1) + 1;
        //cout << rdno << " ";
        //InitV.push_back(rdno);
        //cout << InitV.at(i) << " ";
    }
    cout << endl;
    
    /*srand(time(0));
    generate(InitV.begin(), InitV.end(), rand);
    for(i=0;i<10;i++) {
        cout << InitV.at(i);
    }*/
    
    
    //code to loop for 5 times. Each time M is a different size
    cout << "First sorting algorithm: Insertion Sort" << endl;
    for(i=0; i<5; i++) {



        //code to copy an array/vector of size M from InitV.
        cout << "Enter size M for vector V1: ";
        cin >> M;
        vector<int> V1(M);
        //V1 = InitV;
        for(j=0; j<M; j++) {
            V1.at(j) = InitV.at(j);
        }
        
        //code to printout the first 100 elements, before sorting
        cout << "Printing first 100 elements before sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V1.at(j) << " ";
        }
        cout << endl;
        
        //code to record start time
        auto start = high_resolution_clock::now();
        
        //function call to sorting algo1
        Base.insertionSort2(V1);
        
        //code to record endtime
        auto stop = high_resolution_clock::now();
        
        //code to printout the first 100 elements, after sorting
        cout << "Printing first 100 elements after sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V1.at(j) << " ";
        }
        cout << endl;
        
        //code to compute time taken by algo1
        cout << "Execution time: ";
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << endl;
        
        //reset
        V1 = InitV;
        cout << endl;
    }
    cout << endl;
    
    //code to loop for 5 times. Each time M is a different size
    cout << "Second sorting algorithm: Bubble Sort" << endl;
    for(i=0; i<5; i++) {
        //code to copy an array/vector of size M from InitV.

        cout << "Enter size M for vector V2: ";
        cin >> M;
        vector<int> V2(M);

        for (int i = 0; i < M; i++) {
            V2.at(i) = InitV.at(i);
        }
            
            //code to printout the first 100 elements, before sorting
        cout << "Printing first 100 elements before sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V2.at(j) << " ";
        }
        cout << endl;
        
        //code to record start time
        auto start = high_resolution_clock::now();
        
        //function call to sorting algo1
        Base.bubbleSort(V2);
        
        //code to record endtime
        auto stop = high_resolution_clock::now();
        
        //code to printout the first 100 elements, after sorting
        cout << "Printing first 100 elements after sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V2.at(j) << " ";
        }
        cout << endl;
        
        //code to compute time taken by algo1
        cout << "Execution time: ";
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << endl;
    
    }
    cout << endl;
    
    //code to loop for 5 times. Each time M is a different size
    cout << "Third sorting algorithm: Selection Sort" << endl;
    for(i=0; i<5; i++) {
    //code to copy an array/vector of size M from InitV.
        cout << "Enter size M for vector V3: ";
        cin >> M;
        vector<int> V3(M);

        for (int i = 0; i < M; i++) { // copies init to v3
            V3.at(i) = InitV.at(i);
        }
        
        //code to printout the first 100 elements, before sorting
        cout << "Printing first 100 elements before sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V3.at(j) << " ";
        }
        cout << endl;
        
        //code to record start time
        auto start = high_resolution_clock::now();
        
        //function call to sorting algo1
        Base.selectionSort(V3);
        
        //code to record endtime
        auto stop = high_resolution_clock::now();
        
        //code to printout the first 100 elements, after sorting
        cout << "Printing first 100 elements after sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V3.at(j) << " ";
        }
        cout << endl;
        
        //code to compute time taken by algo1
        cout << "Execution time: ";
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << endl;
        
        //reset
        V3 = InitV;
    }
    cout << endl;
    
    //code to loop for 5 times. Each time M is a different size
    cout << "Fourth sorting algorithm: Quick Sort" << endl;
    for(i=0; i<5; i++) {
        //code to copy an array/vector of size M from InitV.
        cout << "Enter size M for vector V4: ";
        cin >> M;
        vector<int> V4(M);

        for (int i = 0; i < M; i++) {
            V4.at(i) = InitV.at(i);
        }
        
        //code to printout the first 100 elements, before sorting
        cout << "Printing first 100 elements before sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V4.at(j) << " ";
        }
        cout << endl;
        
        //code to record start time
        auto start = high_resolution_clock::now();
        
        //function call to sorting algo1
        Base.quickSort(V4, 0, M-1, 0);
        
        //code to record endtime
        auto stop = high_resolution_clock::now();
        
        //code to printout the first 100 elements, after sorting
        cout << "Printing first 100 elements after sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V4.at(j) << " ";
        }
        cout << endl;
        
        //code to compute time taken by algo1
        cout << "Execution time: ";
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << endl;
        
        //reset
        V4 = InitV;
        
    }
    cout << endl;
    
    //code to loop for 5 times. Each time M is a different size
    cout << "Fifth sorting algorithm: Merge Sort" << endl;
    for(i=0; i<5; i++) {
        //code to copy an array/vector of size M from InitV
        cout << "Enter size M for vector V5: ";
        cin >> M;
        vector<int> V5(M);

        for (int i = 0; i < M; i++) {
            V5.at(i) = InitV.at(i);
        }
        
        //code to printout the first 100 elements, before sorting
        cout << "Printing first 100 elements before sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V5.at(j) << " ";
        }
        cout << endl;
        
        //code to record start time
        auto start = high_resolution_clock::now();
        
        //function call to sorting algo1
        Base.mergeSort(V5, 0, M-1, 0);
        
        //code to record endtime
        auto stop = high_resolution_clock::now();
        
        //code to printout the first 100 elements, after sorting
        cout << "Printing first 100 elements after sorting: " << endl;
        for(j=0; j<100; j++) {
            cout << V5.at(j) << " ";
        }
        cout << endl;
        
        //code to compute time taken by algo1
        cout << "Execution time: ";
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << endl;
        
        //reset
        V5 = InitV;
        
    }
    cout << endl;
     
    return 0;
}
