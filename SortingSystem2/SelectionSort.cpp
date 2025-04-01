#include"SortingSystem.h"
#include<iostream>
using namespace std;
template<typename T>
void SortingSystem<T>::selectionSort() {
    cout << "\nSorting using Selection Sort...\n";
    cout << "Initial Data: ";
    displayData();

    for (int i = 0; i < size - 1; i++) {
		int min = i;
								  //0  1  2  3	4  5				
			for (size_t j = i + 1; j < size; j++) //60,40 ,50,30,10,20
			{
				if (data[j] < data[min])
				{
					min = j;
				}
			}
			swap(data[min], data[i]);
		cout << "iteration " << i+1 << endl;
        displayData();
    }
    cout << "\nSorted Data: ";
    displayData();
}
template class SortingSystem<int>;
template class SortingSystem<string>;