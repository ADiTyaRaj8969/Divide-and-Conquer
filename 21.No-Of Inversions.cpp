// Count the number of inversions in an array.
#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves and count inversions
long long mergeAndCount(vector<int>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;  // size of left subarray (O(1))
    int n2 = r - m;      // size of right subarray (O(1))

    vector<int> left(n1), right(n2);                         // O(n1 + n2) space
    for (int i = 0; i < n1; i++) left[i] = arr[l + i];       // O(n1)
    for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];  // O(n2)

    int i = 0, j = 0, k = l;
    long long inv_count = 0;  // store inversions (O(1))

    // Merge process (O(n1 + n2))
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];  // O(1)
        }
        else
        {
            arr[k++] = right[j++];
            inv_count += (n1 - i);  // Count inversions (O(1))
        }
    }
    while (i < n1) arr[k++] = left[i++];   // O(n1)
    while (j < n2) arr[k++] = right[j++];  // O(n2)

    return inv_count;  // O(1)
}

// Divide and conquer function
long long mergeSortAndCount(vector<int>& arr, int l, int r)
{
    long long inv_count = 0;  // O(1)
    if (l < r)
    {
        int m = l + (r - l) / 2;  // O(1)

        inv_count += mergeSortAndCount(arr, l, m);      // Left half (O(n log n))
        inv_count += mergeSortAndCount(arr, m + 1, r);  // Right half (O(n log n))

        inv_count += mergeAndCount(arr, l, m, r);  // Merge step (O(n))
    }
    return inv_count;  // O(1)
}

int main()
{
    int n;
    cin >> n;  // Input size (O(1))
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];  // O(n)

    cout << mergeSortAndCount(arr, 0, n - 1) << endl;  // O(n log n)
    return 0;
}

/*
----------------------
Time Complexity (Line by Line):
- mergeAndCount():
   - Copying subarrays: O(n1 + n2)
