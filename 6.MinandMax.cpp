// Find the maximum and minimum of an array using divide and conquer.

#include<bits/stdc++.h>
using namespace std;

// Function to find min and max using divide & conquer
pair<int,int> findMinMax(vector<int>& arr, int l, int r) {
    // Base Case 1: If only one element
    if (l == r) {
        // TC = O(1), SC = O(1)
        return {arr[l], arr[l]};
    }

    // Base Case 2: If two elements
    if (r == l + 1) {
        // TC = O(1), SC = O(1)
        if (arr[l] < arr[r])
            return {arr[l], arr[r]};
        else
            return {arr[r], arr[l]};
    }

    // Divide
    int mid = (l + r) / 2;   // TC = O(1), SC = O(1)

    // Conquer: recursively find min and max in left & right halves
    pair<int,int> left = findMinMax(arr, l, mid);    // TC = T(n/2), SC = O(log n) stack
    pair<int,int> right = findMinMax(arr, mid+1, r); // TC = T(n/2), SC = O(log n) stack

    // Combine results
    int finalMin = min(left.first, right.first);     // TC = O(1)
    int finalMax = max(left.second, right.second);   // TC = O(1)

    return {finalMin, finalMax};
}

int main() {
    int n;
    cin >> n; // Input size
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i]; // Input array

    pair<int,int> ans = findMinMax(arr, 0, n-1);

    cout << "Minimum: " << ans.first << ", Maximum: " << ans.second << endl;
    return 0;
}

/*
Time Complexity:
- Recurrence: T(n) = 2T(n/2) + O(1)
- By Master Theorem => T(n) = O(n)

Space Complexity:
- Only recursive stack used => O(log n)
*/




