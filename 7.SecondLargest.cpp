// Find the second largest element using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findSecondLargest(vector<int>& arr, int l, int r) {
    // Base case: if only one element, no second largest
    if (l == r) return {arr[l], INT_MIN}; // O(1) time, O(1) space

    // Base case: if two elements
    if (r == l + 1) { // O(1)
        if (arr[l] > arr[r]) return {arr[l], arr[r]}; // largest, second largest
        else return {arr[r], arr[l]};
    }

    int mid = (l + r) / 2; // O(1)

    // Recursive calls → T(n/2) + T(n/2)
    pair<int, int> left = findSecondLargest(arr, l, mid);   // O(log n) depth
    pair<int, int> right = findSecondLargest(arr, mid + 1, r);

    int largest, secondLargest;

    // Compare results from left and right → O(1)
    if (left.first > right.first) {
        largest = left.first;
        secondLargest = max(left.second, right.first);
    } else {
        largest = right.first;
        secondLargest = max(right.second, left.first);
    }

    return {largest, secondLargest}; // O(1)
}

int main() {
    vector<int> arr = {10, 20, 5, 40, 30, 50};
    pair<int, int> ans = findSecondLargest(arr, 0, arr.size() - 1);

    cout << "Largest: " << ans.first << ", Second Largest: " << ans.second << endl;
    return 0;
}

/*
Time Complexity (line by line):
- Base cases → O(1)
- Recursive division → T(n) = 2T(n/2) + O(1)
- Master Theorem → O(n)

Space Complexity (line by line):
- Recursion depth = O(log n) (stack space)
- Extra variables = O(1)
- Total SC = O(log n)
*/
