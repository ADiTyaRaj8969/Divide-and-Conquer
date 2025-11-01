// Sort an array using 3-way QuickSort.
#include <bits/stdc++.h>
using namespace std;

void threeWayQuickSort(vector<string>& arr, int low, int high) {
    if (low >= high) return; 
    // TC: O(1), SC: O(1) – base case check

    string pivot = arr[low];  
    // TC: O(1), SC: O(1) – choosing pivot

    int lt = low, gt = high, i = low + 1;  
    // TC: O(1), SC: O(1) – pointers initialization

    while (i <= gt) {  
        // Loop runs at most (high-low+1) times → TC: O(n), SC: O(1)
        if (arr[i] < pivot) swap(arr[i++], arr[lt++]);  
        // TC: O(1) per operation, SC: O(1)
        else if (arr[i] > pivot) swap(arr[i], arr[gt--]);  
        // TC: O(1), SC: O(1)
        else i++;  
        // TC: O(1), SC: O(1)
    }

    // Recursive calls
    threeWayQuickSort(arr, low, lt - 1);  
    // Recursively sort left side → TC: T(n/3) approx, SC: O(log n) stack
    threeWayQuickSort(arr, gt + 1, high);  
    // Recursively sort right side → TC: T(n/3), SC: O(log n) stack
}

int main() {
    vector<string> arr = {"banana", "apple", "mango", "apple", "grape", "banana", "kiwi"};
    int n = arr.size();

    threeWayQuickSort(arr, 0, n - 1);

    cout << "Sorted strings: ";
    for (auto &s : arr) cout << s << " ";
    cout << endl;

    return 0;
}
