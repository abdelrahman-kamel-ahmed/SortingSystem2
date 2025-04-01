#include"SortingSystem.h"
#include<iostream>
template <typename T>
int SortingSystem<T>::partition(int left, int right) {
	T Pivot = data[left];
	int i = left;
	int j = right;
	cout << "Subarray: ";
	for (int k = left; k < right; ++k) {
		if (data[k] == Pivot) {
			cout << "[" << data[k] << "] ";
		}
		else {
			cout << data[k] << " ";
		}
	}
	cout << " -> Pivot: " << Pivot << endl;
	

	while (i < j) {
		do {
			i++;
		} while (i < right && data[i] <= Pivot);
		do
		{
			j--;
		} while (j > left && data[j] > Pivot);

		if (i < j) {
			swap(data[i], data[j]);
		}
	}
	swap(data[j], data[left]);
	cout << "Partitioned array: ";
	for (int k = left; k < right; ++k) {
		if (data[k] == Pivot) {
			cout << "[" << data[k] << "] ";
		}
		else {
			cout << data[k] << " ";
		}
	}
	cout << endl << "-------------------------"<<endl;
	return j;
}
template <typename T>
void SortingSystem<T>::quickSort(int left, int right) {
	if (left < right)
	{
		int Pivot = partition(left, right);
		quickSort(left, Pivot);
		quickSort(Pivot + 1, right);
	}
}

template class SortingSystem<int>;
template class SortingSystem<string>;