// Use divide and conquer for polynomial multiplication.
#include <bits/stdc++.h>
using namespace std;

vector<int> poly_multiply(vector<int>& A, vector<int>& B)
{
    int n = A.size();  // O(1) SC
    if (n == 1)
    {                          // Base case O(1) TC
        return {A[0] * B[0]};  // O(1) TC, O(1) SC
    }

    int mid = n / 2;  // Divide step O(1) TC
    // Divide arrays into halves
    vector<int> A_low(A.begin(), A.begin() + mid);  // O(n) TC, O(n) SC
    vector<int> A_high(A.begin() + mid, A.end());   // O(n) TC, O(n) SC
    vector<int> B_low(B.begin(), B.begin() + mid);  // O(n) TC, O(n) SC
    vector<int> B_high(B.begin() + mid, B.end());   // O(n) TC, O(n) SC

    // Recursive calls (Divide and Conquer)
    vector<int> P1 = poly_multiply(A_low, B_low);    // T(n/2)
    vector<int> P2 = poly_multiply(A_high, B_high);  // T(n/2)

    vector<int> A_sum(mid), B_sum(mid);  // O(n) SC
    for (int i = 0; i < mid; i++)
    {  // O(n) TC
        A_sum[i] = A_low[i] + A_high[i];
        B_sum[i] = B_low[i] + B_high[i];
    }

    vector<int> P3 = poly_multiply(A_sum, B_sum);  // T(n/2)

    // Combine results
    vector<int> res(2 * n - 1, 0);       // O(n) SC
    for (int i = 0; i < P1.size(); i++)  // O(n) TC
        res[i] += P1[i];
    for (int i = 0; i < P2.size(); i++)  // O(n) TC
        res[i + n] += P2[i];
    for (int i = 0; i < P3.size(); i++)  // O(n) TC
        res[i + mid] += P3[i] - P1[i] - P2[i];

    return res;  // Final merged polynomial
}

int main()
{
    vector<int> A = {1, 2, 3, 4};  // Represents 1 + 2x + 3x² + 4x³
    vector<int> B = {4, 3, 2, 1};  // Represents 4 + 3x + 2x² + x³

    vector<int> result = poly_multiply(A, B);

    cout << "Result Polynomial: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

/*
---------------------------
Overall Time Complexity:
- T(n) = 3T(n/2) + O(n)
- By Master Theorem → O(n^(log2(3))) ≈ O(n^1.585)
---------------------------
Overall Space Complexity:
- Recursion stack depth = O(log n)
- Extra space for results = O(n)
- Total = O(n log n)
*/
