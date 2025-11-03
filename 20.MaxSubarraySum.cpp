// Find the maximum subarray sum using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

// Function to find max crossing subarray sum
int crossSum(vector<int>& arr, int l, int m, int r)
{
    // TC: O(n) for scanning left + right parts
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;

    // Scan left half
    for (int i = m; i >= l; i--)
    {  // O(n/2)
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    // Scan right half
    for (int i = m + 1; i <= r; i++)
    {  // O(n/2)
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;  // Combine both halves
}

// Main divide and conquer function
int maxSubArray(vector<int>& arr, int l, int r)
{
    if (l == r)
        return arr[l];  // Base case O(1)

    int m = (l + r) / 2;

    // Divide into 3 cases
    int left = maxSubArray(arr, l, m);       // O(T(n/2))
    int right = maxSubArray(arr, m + 1, r);  // O(T(n/2))
    int cross = crossSum(arr, l, m, r);      // O(n)

    return max({left, right, cross});  // O(1)
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Maximum Subarray Sum = " << maxSubArray(arr, 0, n - 1) << endl;
    return 0;
}

/*
🔹 Time Complexity (TC):
- crossSum() takes O(n) for each recursive step
- Recurrence: T(n) = 2T(n/2) + O(n)
- Solving → T(n) = O(n log n)

🔹 Space Complexity (SC):
- O(log n) recursion stack depth (binary splitting)
*/
