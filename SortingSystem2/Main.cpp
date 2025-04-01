#include<iostream>
#include "SortingSystem.h"
int type = -1;
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "choose the type of data in array:\n1-int \n2-string\n----->";
    cin >> type;
    bool sortMore = true;
    int moresort;
    while (sortMore)
    {
        if (type == 1)
        {
            SortingSystem<int> sorter(n);
            sorter.showMenu();
            sorter.measureSortingTime();
            cout << "Sorted Data: ";
            sorter.displayData();
        }
        else if (type == 2)
        {
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