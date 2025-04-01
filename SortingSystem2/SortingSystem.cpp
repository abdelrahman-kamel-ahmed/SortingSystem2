#include"SortingSystem.h"
#include<iostream>
#include"chrono"
#include<fstream>
using namespace std;
int choice;
template<typename T>
SortingSystem<T>::SortingSystem(int n) {

    size = n;
    data = new T[size];
 


    ifstream inputfile("input.txt");
    if (!inputfile) {
        cout << "error can not open your input file" << endl;
        exit(1);
    }
    else {

        cout << "reading array from your input file" << endl;
        for (int i = 0; i < size; i++) {
            if (!(inputfile >> data[i])) {
                cout << "error No enough data in input.txt" << endl;
                exit(1);
            }
        }
        inputfile.close();
    }
}
template<typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}


template<typename T>
void SortingSystem<T>::showMenu() {
    if (type == 2)
    {
        cout << "please choose the sort" << endl;
        cout << "1.selection sort" << endl;
        cout << "2.insertion sort" << endl;
        cout << "3.bubble sort" << endl;
        cout << "4.shell sort" << endl;
        cout << "5.merge sort" << endl;
        cout << "6.quick sort" << endl;
    }
    else
    {
        cout << "please choose the sort" << endl;
        cout << "1.Selection sort" << endl;
        cout << "2.Insertion sort" << endl;
        cout << "3.Bubble sort" << endl;
        cout << "4.Shell sort" << endl;
        cout << "5.Merge sort" << endl;
        cout << "6.Quick sort" << endl;
        cout << "7.Bucket sort" << endl;
        cout << "8.Radix sort" << endl;
		cout << "9.Count sort" << endl;
    }
    cin >> choice;
}
template<typename T>
void SortingSystem <T>::displayData() {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]\n";
}

template<typename T>
void SortingSystem<T>::measureSortingTime() {
    auto start = chrono::high_resolution_clock::now();

    switch (choice)
    {
    case 1:
        selectionSort();
        break;
    case 2:
        insertionSort();
        break;

    case 3:
        bubbleSort();
        break;

    case 4:
        shellSort();
        break;

    case 5:

        mergeSort(0, 6);
        break;
    case 6:

        quickSort(0, 6);
        break;

    case 7:
        cout << "Type is integral: " << std::is_integral_v<T> << endl; 
        if constexpr (std::is_integral_v<T>) {
            bucketSort();
        }
        else {
            cout << "Bucket sort only works with integers!\n";
        }
        break;
    case 8:
        cout << "Type is integral: " << std::is_integral_v<T> << endl; 
        if constexpr (std::is_integral_v<T>) {
            radixSort();
        }
        else {
            cout << "Radix sort only works with integers!\n";
        }
        break;

    case 9:
        cout << "Type is integral: " << std::is_integral_v<T> << endl; 
        if constexpr (std::is_integral_v<T>) {
            countSort();
        }
        else {
            cout << "Count sort only works with integers!\n";
        }
        break;

    default:
        break;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken: " << duration.count() << " seconds" << endl;
}

template class SortingSystem<int>;
template class SortingSystem<string>;