#include "SortingSystem.h"
#include <iostream>
using namespace std;

template <typename T>
void SortingSystem<T>::shellSort() {
    cout << "\nSorting while using Shell Sort...\n";
    cout << "Initial Data: ";
    displayData();

    for (int gap = size / 2; gap > 0; gap /= 2) {
        cout << "\nCurrent gap: " << gap << endl;

        for (int i = gap; i < size; i++) {
            T temp = data[i];
            int j;

            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }

            data[j] = temp;

            cout << "After swaping at index " << i << ": ";
            displayData();
        }
    }

    cout << "\nFinal Sorted Data: ";
    displayData();
}
template class SortingSystem<int>;
template class SortingSystem<string>;
