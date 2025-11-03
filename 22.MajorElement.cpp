// Solve the majority element problem (find element occurring more than n/2 times).
#include <bits/stdc++.h>
using namespace std;

// Function to count frequency of element in given range
int countFreq(vector<int>& arr, int l, int r, int x)
{
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        // O(r-l+1) → O(n) worst case
        cnt++;  // O(1)
    }
    return cnt;  // O(1)
}

// Divide & Conquer function
int majorityElement(vector<int>& arr, int l, int r)
{
    if (l == r)
        return arr[l];  // Base case → O(1)

    int mid = (l + r) / 2;  // O(1)

    // Recursively find majority in left half → T(n/2)
    int left = majorityElement(arr, l, mid);

    // Recursively find majority in right half → T(n/2)
    int right = majorityElement(arr, mid + 1, r);

    if (left == right)
        return left;  // O(1)

    // Count frequency of left and right in whole range → O(n)
    int leftCount = countFreq(arr, l, r, left);
    int rightCount = countFreq(arr, l, r, right);

    return (leftCount > rightCount ? left : right);  // O(1)
}

int main()
{
    int n;
    cin >> n;  // Input size → O(1)
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];  // O(n)

    cout << majorityElement(arr, 0, n - 1) << endl;  // Final answer → O(log n) recursive levels
    return 0;
}

/*
-------------------------------
⏱ TIME COMPLEXITY (Line by Line)
-------------------------------
Base case check → O(1)
Divide step → O(1)
Two recursive calls → 2T(n/2)
Merging step (count frequency) → O(n)

So, Recurrence = T(n) = 2T(n/2) + O(n)
By Master Theorem → T(n) = O(n log n)

-------------------------------
💾 SPACE COMPLEXITY
-------------------------------
Recursion stack depth = O(log n)
No extra arrays used → O(1)
Total SC = O(log n)
*/
