// Sort an array of strings using Merge Sort.
#include <bits/stdc++.h>
using namespace std;

// Merge function
void merge(vector<string>& arr, int l, int m, int r) {
    // TC: O(n) for merging two halves
    // SC: O(n) for temporary arrays
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];  // TC: O(n1)
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];  // TC: O(n2)

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {  // TC: O(n)
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];  // TC: O(n1)
    while (j < n2) arr[k++] = R[j++];  // TC: O(n2)
}

// MergeSort function
void mergeSort(vector<string>& arr, int l, int r) {
    // Recurrence: T(n) = 2T(n/2) + O(n)
    // Master theorem → T(n) = O(n log n)
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);     // TC: O(log n) levels
        mergeSort(arr, m + 1, r); // TC: O(log n) levels
        merge(arr, l, m, r);
    }
}

int main() {
    vector<string> arr = {"pear", "apple", "orange", "banana", "grape"};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted strings: ";
    for (string s : arr) cout << s << " ";
    return 0;
}

/*
⚡ Time Complexity:
- Divide step: O(log n) recursive calls
- Merge step: O(n) per level
- Total: O(n log n)

⚡ Space Complexity:
- Temporary arrays in merge → O(n)
- Recursion stack → O(log n)
- Total: O(n)
*/
