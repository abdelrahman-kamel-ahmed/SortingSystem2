#include "SortingSystem.h"
#include <iostream>
using namespace std;


template<typename T>

void SortingSystem<T>::merge(int left, int mid, int right) {
    int lsize = mid - left + 1;
    int rsize = right - mid;

    T* larr = new T[lsize];
    T* rarr = new T[rsize];

    for (int i = 0; i < lsize; i++) {
        larr[i] = data[left + i];
    }
    for (int j = 0; j < rsize; j++) {
        rarr[j] = data[mid + 1 + j];
    }

    int ll = 0;
    int rr = 0;
    int k = left;

    while (ll < lsize && rr < rsize && k<right) {
        if (larr[ll] <= rarr[rr]) {
            data[k] = larr[ll];
            ll++;
        }
        else {
            data[k] = rarr[rr];
            rr++;
        }
        k++;
    }

    while (ll < lsize) {
        data[k] = larr[ll];
        ll++;
        k++;
    }

    while (rr < rsize) {
        data[k] = rarr[rr];
        rr++;
        k++;
    }

    delete[] larr;
    delete[] rarr;
}

template <typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    cout << "\nSorting using Merge Sort...\n";
    cout << "Initial Data: ";
    displayData();

    int size = right - left + 1;
    if (size <= 1)
        return;

    int mid = left + (right - left) / 2;

    cout << "Left Subarray (" << left << " to " << mid << "): ";
    for (int i = left; i <= mid; i++)
        cout << data[i] << " ";
    cout << endl;

    mergeSort(left, mid);

    cout << "Right Subarray (" << mid + 1 << " to " << right << "): ";
    for (int i = mid + 1; i <= right; i++)
        cout << data[i] << " ";
    cout << endl;

    mergeSort(mid + 1, right);

    cout << "Merging (" << left << " to " << mid << ") and ("
        << mid + 1 << " to " << right << ")\n";
    merge(left, mid, right);

    cout << "After merge: ";
    for (int i = left; i <= right; i++)
        cout << data[i] << " ";
    cout << endl;
}

template class SortingSystem<int>;
template class SortingSystem<string>;