// Find the first and last occurrence of an element in a sorted array.
#include <bits/stdc++.h>
using namespace std;
// Function to find first occurrence using Binary Search
int firstOccurrence(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, ans = -1;  // TC: O(1), SC: O(1)
    while (low <= high) {  // TC: log(n) iterations
        int mid = low + (high - low) / 2;  // TC: O(1), SC: O(1)
        if (arr[mid] == x) {  
            ans = mid;          // TC: O(1)
            high = mid - 1;     // move left to find first occurrence
        } else if (arr[mid] < x) {
            low = mid + 1;      // TC: O(1)
        } else {
            high = mid - 1;     // TC: O(1)
        }
    }
    return ans;  // TC: O(1)
}

// Function to find last occurrence using Binary Search
int lastOccurrence(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, ans = -1;  
    // TC: O(1), SC: O(1)
    while (low <= high) {  // TC: log(n) iterations
        int mid = low + (high - low) / 2;  // TC: O(1)
        if (arr[mid] == x) {
            ans = mid;          // TC: O(1)
            low = mid + 1;      // move right to find last occurrence
        } else if (arr[mid] < x) {
            low = mid + 1;      // TC: O(1)
        } else {
            high = mid - 1;     // TC: O(1)
        }
    }
    return ans;  // TC: O(1)
}

int main() {
    int n, x;
    cin >> n >> x;  // Input size and element to search
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];  // TC: O(n), SC: O(n)

    int first = firstOccurrence(arr, x);   // TC: O(log n), SC: O(1)
    int last = lastOccurrence(arr, x);     // TC: O(log n), SC: O(1)

    cout << "First occurrence = " << first << endl;
    cout << "Last occurrence = " << last << endl;

    return 0;  // TC: O(1), SC: O(1)
}

/*
================= COMPLEXITY =================
Overall Time Complexity: O(log n) + O(log n) + O(n) (for input) 
=> O(n) including input, O(log n) for search only.

Overall Space Complexity: O(n) for array storage.
Extra Space Complexity (excluding input array): O(1).
*/
