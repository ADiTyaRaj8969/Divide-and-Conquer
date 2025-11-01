// Implement Merge Sort.
#include <bits/stdc++.h>
using namespace std;

// Merge function
void merge(vector<int>& arr, int l, int m, int r) {
    // TC: O(n) → where n = r-l+1
    // SC: O(n) → temporary arrays
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2); // SC: O(n1+n2)
    for (int i = 0; i < n1; i++) L[i] = arr[l + i]; // TC: O(n1)
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j]; // TC: O(n2)

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) { // TC: O(n)
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++]; // TC: O(n1)
    while (j < n2) arr[k++] = R[j++]; // TC: O(n2)
}

// Merge Sort function
void mergeSort(vector<int>& arr, int l, int r) {
    // Recurrence: T(n) = 2T(n/2) + O(n)
    // Master Theorem ⇒ O(n log n)
    // SC: O(n) auxiliary + O(log n) recursion
    if (l < r) {
        int m = l + (r - l) / 2; // TC: O(1)
        mergeSort(arr, l, m);    // TC: T(n/2)
        mergeSort(arr, m + 1, r);// TC: T(n/2)
        merge(arr, l, m, r);     // TC: O(n)
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
