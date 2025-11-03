// Merge two sorted arrays into one using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

// Merge function (Divide and Conquer)
void mergeArrays(vector<int>& arr1, vector<int>& arr2, vector<int>& result, int l1, int r1, int l2,
                 int r2, int idx)
{
    // Time Complexity: O(n1 + n2) where n1 = r1-l1+1, n2 = r2-l2+1
    // Space Complexity: O(log(n1+n2)) recursion stack

    if (l1 > r1)
    {
        while (l2 <= r2) result[idx++] = arr2[l2++];
        return;
    }
    if (l2 > r2)
    {
        while (l1 <= r1) result[idx++] = arr1[l1++];
        return;
    }

    if (arr1[l1] < arr2[l2])
    {
        result[idx] = arr1[l1];
        mergeArrays(arr1, arr2, result, l1 + 1, r1, l2, r2, idx + 1);
    }
    else
    {
        result[idx] = arr2[l2];
        mergeArrays(arr1, arr2, result, l1, r1, l2 + 1, r2, idx + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;  // input sizes

    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    vector<int> result(n + m);

    mergeArrays(arr1, arr2, result, 0, n - 1, 0, m - 1, 0);

    for (int x : result) cout << x << " ";
    return 0;
}
