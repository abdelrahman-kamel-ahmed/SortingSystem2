#include "SortingSystem.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void SortingSystem<T>::countSort() {
    cout << "\nSorting using Counting Sort...\n";
    cout << "Initial Data: ";
    displayData();

   
    int min_val = *min_element(data, data + size);
    int max_val = *max_element(data, data + size);
    int range = max_val - min_val + 1;
    cout << "\nStep 1: Range = " << min_val << " to " << max_val << " (size: " << range << ")\n";

   
    int* count = new int[range]();
    for (int i = 0; i < size; i++) {
        count[data[i] - min_val]++;
    }
    cout << "Step 2: Count array: [";
    for (int i = 0; i < range; i++) {
        cout << count[i];
        if (i < range - 1) cout << ", ";
    }
    cout << "]\n";

    
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    cout << "Step 3: Cumulative counts: [";
    for (int i = 0; i < range; i++) {
        cout << count[i];
        if (i < range - 1) cout << ", ";
    }
    cout << "]\n";

   
    T* output = new T[size];
    bool* filled = new bool[size](); 

    cout << "\nStep 4: Building sorted array:\n";
    for (int i = size - 1; i >= 0; i--) {
        int pos = --count[data[i] - min_val];
        output[pos] = data[i];
        filled[pos] = true;

        cout << "Placing " << data[i] << " at position " << pos << ": [";
        for (int j = 0; j < size; j++) {
            if (filled[j]) {
                cout << output[j];
            }
            else {
                cout << "_";
            }
            if (j < size - 1) cout << ", ";
        }
        cout << "]\n";
    }

    
    for (int i = 0; i < size; i++) {
        data[i] = output[i];
    }

    cout << "\nFinal Sorted Array: ";
    displayData();

    
    delete[] count;
    delete[] output;
    delete[] filled;
}
template class SortingSystem<int>;