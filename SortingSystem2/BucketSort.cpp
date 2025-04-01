#include"SortingSystem.h"
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void SortingSystem<T>::bucketSort() {
    if (size == 0) return;

    // Find max value
    T max_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    // Create buckets (using array of vectors)
    const int bucket_count = 10; // Using 10 buckets
    vector<T> buckets[bucket_count];

    // Distribute elements into buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = (data[i] * bucket_count) / (max_val + 1);
        buckets[bucket_index].push_back(data[i]);
    }

    // Sort individual buckets (using insertion sort)
    for (int i = 0; i < bucket_count; i++) {
        if (!buckets[i].empty()) {
            // Insertion sort for each bucket
            for (int j = 1; j < buckets[i].size(); j++) {
                T key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
        }
    }

    // Concatenate all buckets back into original array
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (T num : buckets[i]) {
            data[index++] = num;
        }
    }
}
template class SortingSystem<int>;
