// Search an element in a rotated sorted array.

#include <bits/stdc++.h>
using namespace std;

int searchRotated(vector<int>& arr, int target) {
    int low = 0;                        // O(1) time, O(1) space
    int high = arr.size() - 1;          // O(1) time, O(1) space

    while (low <= high) {               // Loop runs O(log n) times
        int mid = (low + high) / 2;     // O(1) time, O(1) space

        if (arr[mid] == target)         // O(1)
            return mid;                 // Found element

        // Left half is sorted
        if (arr[low] <= arr[mid]) {     // O(1)
            if (arr[low] <= target && target < arr[mid]) 
                high = mid - 1;         // O(1)
            else 
                low = mid + 1;          // O(1)
        } 
        // Right half is sorted
        else {                          
            if (arr[mid] < target && target <= arr[high]) 
                low = mid + 1;          // O(1)
            else 
                high = mid - 1;         // O(1)
        }
    }
    return -1;                          // O(1)
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};  // O(n) space
    int target = 0;
    cout << searchRotated(arr, target); // O(log n) time
    return 0;
}

/*
Overall Time Complexity: O(log n)  (binary search halves array each step)
Overall Space Complexity: O(1)    (only a few variables used, no recursion)
*/
