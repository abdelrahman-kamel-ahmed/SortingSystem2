#include<iostream>
#include "SortingSystem.h"
#include"fstream"
int type = -1;
using namespace std;
bool isInteger(const string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '-') return false;
    }
    return true;
}
int main() {
    int n;
    string arrayType;
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input.txt!" << endl;
        return 1; 
    }
    inputFile >> n; 
    inputFile >> arrayType;
    inputFile.close(); 
 /*   cout << "choose the type of data in array:\n1-int \n2-string\n----->";
    cin >> type;*/
    bool sortMore = true;
    int moresort;
    while (sortMore)
    {
        if (isInteger(arrayType))
        {
            type = 1;
            SortingSystem<int> sorter(n);
            sorter.showMenu();
            sorter.measureSortingTime();
            cout << "Sorted Data: ";
            sorter.displayData();

        }
        else if (!isInteger(arrayType))
        {
            type = 2;
            SortingSystem<string> sorter(n);
            sorter.showMenu();
            sorter.measureSortingTime();
            cout << "Sorted Data: ";
            sorter.displayData();
        }
        else
        {
            cout << "Invalid choice\n";
        }
        cout << "Do u want to sort again ? 1)Yes 2)No " << endl;
        cin >> moresort;
        if (moresort == 2)
        {
            sortMore = false;
            cout << "Thanks for using our program" << endl;
        }
    }
    return 0;
}