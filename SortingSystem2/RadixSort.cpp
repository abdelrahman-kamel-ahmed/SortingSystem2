#include "SortingSystem.h"
#include <iostream>
using namespace std;

template <>
void SortingSystem<int>::radixSort() {
    cout << "\n--- Starting Radix Sort ---\n";
    cout << "Original array: ";
    displayData();
    cout << "----------------------------\n";

    int maxNum = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxNum) {
            maxNum = data[i];
        }
    }
    cout << "Max number: " << maxNum << " (will sort up to "
        << (int)log10(maxNum) + 1 << " digits)\n";

    int* temp = new int[size];

    for (int dig = 1; maxNum / dig > 0; dig *= 10) {
        cout << "\nProcessing " << (int)log10(dig) + 1 << "'s place (digit divisor: "
            << dig << ")\n";

        int bucket[10] = { 0 };

        
        cout << "Counting digits: ";
        for (int i = 0; i < size; i++) {
            int digit = (data[i] / dig) % 10;
            bucket[digit]++;
            cout << digit << " ";
        }
        cout << "\nDigit counts: [";
        for (int i = 0; i < 10; i++) cout << bucket[i] << (i < 9 ? ", " : "");
        cout << "]\n";

        
        for (int i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        cout << "Cumulative counts: [";
        for (int i = 0; i < 10; i++) cout << bucket[i] << (i < 9 ? ", " : "");
        cout << "]\n";

        
        cout << "Reordering elements:\n";
        for (int i = size - 1; i >= 0; i--) {
            int digit = (data[i] / dig) % 10;
            temp[bucket[digit] - 1] = data[i];
            bucket[digit]--;

            
            cout << "Moved " << data[i] << " (digit " << digit
                << ") to position " << bucket[digit] << "\n";
        }

        
        for (int i = 0; i < size; i++) {
            data[i] = temp[i];
        }

        cout << "After processing this digit: ";
        displayData();
        cout << "----------------------------\n";
    }
    delete[] temp;
    cout << "Final sorted array: ";
    displayData();
    cout << "--- Radix Sort Complete ---\n\n";
}
template class SortingSystem<int>;
