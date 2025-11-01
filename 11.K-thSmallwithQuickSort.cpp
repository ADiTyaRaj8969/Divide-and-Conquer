// Find the k-th smallest element using QuickSort partitioning (QuickSelect).
#include <bits/stdc++.h>
using namespace std;

// Partition function (same as QuickSort partition)
int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];   // TC: O(1), SC: O(1)
    int i = low;             // TC: O(1), SC: O(1)
    for (int j = low; j < high; j++) {  // TC: O(n) in worst case, SC: O(1)
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]); // TC: O(1), SC: O(1)
            i++;
        }
    }
    swap(arr[i], arr[high]); // TC: O(1), SC: O(1)
    return i; // TC: O(1), SC: O(1)
}

// QuickSelect function
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {  // TC: O(1), SC: O(1)
        int pi = partitionArray(arr, low, high); // TC: O(n), SC: O(1)
        
        if (pi == k) return arr[pi];     // TC: O(1), SC: O(1)
        else if (pi > k)                 // TC: O(1), SC: O(1)
            return quickSelect(arr, low, pi - 1, k);  // TC: T(n/2), SC: O(log n) stack
        else
            return quickSelect(arr, pi + 1, high, k); // TC: T(n/2), SC: O(log n) stack
    }
    return -1; // TC: O(1), SC: O(1)
}

int main() {
    int n, k;
    cin >> n >> k; // input size and k (0-based index for k-th smallest)
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << quickSelect(arr, 0, n - 1, k) << endl;
    return 0;
}

/*
📌 Time Complexity:
- Best/Average case: O(n) (because partition reduces problem size each step).
- Worst case: O(n^2) (when array is already sorted or bad pivot each time).
📌 Space Complexity:
- O(1) extra space (in-place).
- O(log n) recursion stack (average), O(n) in worst case.
*/
