#include "SortingSystem.h"
#include <iostream>
#include <cctype>
using namespace std;


bool caseInsensitiveLess(const string& a, const string& b) {
    for (size_t i = 0; i < a.size() && i < b.size(); i++) {
        char aLower = tolower(a[i]);
        char bLower = tolower(b[i]);
        if (aLower != bLower) {
            return aLower < bLower;
        }
    }
    return a.size() < b.size();
}

template<typename T>
void SortingSystem<T>::insertionSort() {
    cout << "\n--- Insertion Sort ---" << endl;
    for (int i = 1; i < size; i++) {
        T key = data[i];
        int j = i - 1;

        cout << "Step " << i << ": ";
        displayData();
        if constexpr (is_same_v<T, string>) {
            while (j >= 0 && caseInsensitiveLess(key, data[j])) {
                data[j + 1] = data[j];
                j--;
            }
        }
        else {
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
        }


        data[j + 1] = key;

        cout << "After Insertion: ";
        displayData();
        cout << "---------------------" << endl;
    }
   
}
template class SortingSystem<int>;
template class SortingSystem<string>;