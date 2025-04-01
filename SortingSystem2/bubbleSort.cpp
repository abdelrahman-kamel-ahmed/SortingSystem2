#include "SortingSystem.h"
#include <iostream>
using namespace std;

template <typename T>
void SortingSystem<T>::bubbleSort() {
    cout << "\nSorting using Bubble Sort...\n";
    cout << "Initial Data: ";
    displayData();

    T tmp;
    for (int i = 0; i < size - 1; i++) { 
        for (int j = i + 1; j < size; j++) { 
            if (data[i] > data[j]) {
                tmp = data[j];
                data[j] = data[i];
                data[i] = tmp;
            }
        }
        cout << "Iteration " << i + 1 << ": ";
        displayData();
    }

    cout << "\nSorted Data: ";
    displayData();
}

template class SortingSystem<int>;
template class SortingSystem<string>;
