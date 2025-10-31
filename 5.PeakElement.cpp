// Find the peak element in an array using binary search.
#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int>& arr) {
    int n = arr.size();                         // O(1) TC, O(1) SC
    int low = 0, high = n - 1;                  // O(1) TC, O(1) SC

    while (low <= high) {                       // O(log n) iterations
        int mid = low + (high - low) / 2;       // O(1) TC, O(1) SC

        // Check if mid is a peak
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && 
            (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
            return mid;                         // O(1) TC, O(1) SC
        }
        // If left neighbor is greater, move left
        else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;                     // O(1) TC, O(1) SC
        }
        // Otherwise move right
        else {
            low = mid + 1;                      // O(1) TC, O(1) SC
        }
    }
    return -1; // Should not reach here if array has at least 1 element
}

int main() {
    vector<int> arr = {1, 3, 20, 4, 1, 0};
    int peakIndex = findPeak(arr);              // O(log n) TC, O(1) SC
    cout << "Peak Element Index: " << peakIndex << endl;
    return 0;
}
