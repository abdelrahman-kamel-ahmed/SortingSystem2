#pragma once
#include<iostream>
#include <type_traits>
extern int type;
using namespace std;
template<typename T>
class SortingSystem {
private:
    T* data; //dynamic array for storing input data
    int size; //size of the array
public:
    SortingSystem(int n); //constructor
    ~SortingSystem(); //destructor
    void insertionSort(); //insertion sort
    void selectionSort(); //selection sort
    void bubbleSort(); //bubble sort
    void mergeSort(int left, int right); //merge sort
    void quickSort(int left, int right); //quick sort
    void countSort(); //count sort
    void radixSort();//radix sort
    void bucketSort(); //bucket sort
    void shellSort(); //shell sort.
    void merge(int left, int mid, int right); //merge function for merge sort
    int partition(int left, int right); //partition function for quick sort

    void displayData(); //display the data
    void measureSortingTime(); //measure the time taken by each sorting algorithm
    void showMenu(); //display the menu
};

