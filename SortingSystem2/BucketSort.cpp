#include <iostream>
#include <cstring>
#include <cstdlib>
#include <regex>
#include <string>
#include "SortingSystem.h"
using namespace std;

// Function to check if string represents a positive float/double
bool isfloat(const string& str) {
    static const regex numericRegex(
        "^([0-9]+(\\.[0-9]*)?|\\.[0-9]+)$");
    return regex_match(str, numericRegex);
}

template<typename T>
void SortingSystem<T>::bucketSort() {
    cout << endl;
    if constexpr (is_integral_v<T>) {
 

        if (size == 0) {
            cout << "Array is empty. Nothing to sort." << endl;
            return;
        }

        // Find max value
        T maxVal = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > maxVal) maxVal = data[i];
        }

        // Create buckets
        const int bucketCount = (maxVal / 10) + 1;
        cout << "Creating " << bucketCount << " buckets (0-" << bucketCount - 1 << ")" << endl;


        T** buckets = new T * [bucketCount];
        int* bucketSizes = new int[bucketCount]();

        // Initialize buckets
        for (int i = 0; i < bucketCount; i++) {
            buckets[i] = new T[size];
        }

        cout << endl; 

        // Distribute elements into buckets
        cout << "\inserting elements into the right buckets:" << endl;
        for (int i = 0; i < size; i++) {
            int bucketIndex = data[i] / 10;
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
            cout << "  " << data[i] << " -> Bucket " << bucketIndex << endl;
        }


        // Sorting elements in each buckets
        cout << "\nSorting each bucket:" << endl;
        for (int b = 0; b < bucketCount; b++) {
            if (bucketSizes[b] > 0) {
                cout << "  Bucket [" << b << "]: [";
                for (int i = 0; i < bucketSizes[b]; i++) {
                    cout << buckets[b][i];
                    if (i < bucketSizes[b] - 1) cout << ", ";
                }
                cout << "]";

                if (bucketSizes[b] == 1) {
                    cout << " - Already sorted";
                    cout << endl;
                }
                else {
                    // Insertion sort for current bucket
                    for (int i = 1; i < bucketSizes[b]; i++) {
                        T key = buckets[b][i];
                        int j = i - 1;
                       
                        while (j >= 0 && buckets[b][j] > key) {
                            buckets[b][j + 1] = buckets[b][j];
                            j--;
                        }
                        buckets[b][j + 1] = key;
                        
                    }
                    cout << " - After sorting: [";
                    for (int i = 0; i < bucketSizes[b]; i++) {
                        cout << buckets[b][i];
                        if (i < bucketSizes[b] - 1) cout << ", ";
                    }
                    cout << "]";
                    cout << endl;

                }
            }
        }



        // Merge buckets back into original array
        cout << "\nMerging buckets:" << endl;
        int index = 0;
        for (int b = 0; b < bucketCount; b++) {
            if (bucketSizes[b] > 0) {
                cout << "  Bucket " << b << ": ";
                for (int i = 0; i < bucketSizes[b]; i++) {
                    data[index++] = buckets[b][i];
                    cout << buckets[b][i] << " ";
                }
                cout << endl;
            }
            delete[] buckets[b];
        }

        // Cleanup
        delete[] buckets;
        delete[] bucketSizes;

    }
    else if constexpr (is_same_v<T, string>) {

        if (size == 0) {
            cout << "Array is empty. Nothing to sort." << endl;
            return;
        }

        // Verify all strings are numeric
        double* numericValues = new double[size];
        bool allNumeric = true;

        for (int i = 0; i < size; i++) {
            if (!isfloat(data[i])) {
                cout << "  " << data[i] << " is not a valid number!" << endl;
                allNumeric = false;
                break;
            }
            numericValues[i] = stod(data[i]);
        }

        if (!allNumeric) {
            cout << "Error: Bucket sort only works with (FLOAT, DOUBLE, INTAGRES)" << endl;
            delete[] numericValues;
            return;
        }

        int maxIntPart = static_cast<int>(numericValues[0]);
        for (int i = 1; i < size; i++) {
            int currentInt = static_cast<int>(numericValues[i]);
            if (currentInt > maxIntPart) {
                maxIntPart = currentInt;
            }
        }

        // Create buckets
        const int bucketCount = maxIntPart + 1;
        cout << "Creating " << bucketCount << " buckets (0-" << maxIntPart << ")" << endl;
        cout << endl;
        string** buckets = new string * [bucketCount];
        int* bucketSizes = new int[bucketCount]();

        for (int i = 0; i < bucketCount; i++) {
            buckets[i] = new string[size];
        }

        // Distribute elements into buckets
        cout << "\inserting elements into the right buckets:" << endl;
        for (int i = 0; i < size; i++) {
            int bucketIndex = static_cast<int>(numericValues[i]);
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
            cout << "  " << data[i] << " -> Bucket " << bucketIndex << endl;
        }

        // Sort individual buckets
        cout << "\nSorting each bucket:" << endl;
        for (int b = 0; b < bucketCount; b++) {
            if (bucketSizes[b] > 0) {
                cout << "  Bucket [" << b << "]: [";
                for (int i = 0; i < bucketSizes[b]; i++) {
                    cout << buckets[b][i];
                    if (i < bucketSizes[b] - 1) cout << ", ";
                }
                cout << "]";

                if (bucketSizes[b] == 1) {
                    cout << " - Already sorted";
                }
                else {
                    // Insertion sort for current bucket
                    for (int i = 1; i < bucketSizes[b]; i++) {
                        string key = buckets[b][i];
                        double keyVal = stod(key);
                        int j = i - 1;

                        while (j >= 0 && stod(buckets[b][j]) > keyVal) {
                            buckets[b][j + 1] = buckets[b][j];
                            j--;
                        }
                        buckets[b][j + 1] = key;
                    }
                    cout << " - After sorting: [";
                    for (int i = 0; i < bucketSizes[b]; i++) {
                        cout << buckets[b][i];
                        if (i < bucketSizes[b] - 1) cout << ", ";
                    }
                    cout << "]";
                }
                cout << endl;
            }
        }

        
        cout << "\nMerging buckets:" << endl;
        int index = 0;
        for (int b = 0; b < bucketCount; b++) {
            if (bucketSizes[b] > 0) {
                cout << "  Bucket " << b << ": ";
                for (int i = 0; i < bucketSizes[b]; i++) {
                    data[index++] = buckets[b][i];
                    cout << buckets[b][i] << " ";
                }
                cout << endl;
            }
            delete[] buckets[b];
        }

        cout << endl;
        cout << endl;


        // Cleanup
        delete[] buckets;
        delete[] bucketSizes;
        delete[] numericValues;
    }

}

template class SortingSystem<int>;
template class SortingSystem<string>;