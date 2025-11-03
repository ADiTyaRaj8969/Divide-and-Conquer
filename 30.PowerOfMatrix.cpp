// Implement power of matrix using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

// Multiply two matrices (n x n)
vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B,
                                   int n)
{
    vector<vector<long long>> C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {  // O(n)
        for (int j = 0; j < n; j++)
        {  // O(n)
            for (int k = 0; k < n; k++)
            {                                  // O(n)
                C[i][j] += A[i][k] * B[k][j];  // O(1)
            }
        }
    }
    return C;
}

// Divide and Conquer: Matrix exponentiation
vector<vector<long long>> matrixPower(vector<vector<long long>>& A, int n, int power)
{
    if (power == 1)
        return A;  // Base case

    // Divide step
    vector<vector<long long>> half = matrixPower(A, n, power / 2);  // O(log power)

    // Conquer step
    vector<vector<long long>> result = multiply(half, half, n);  // O(n^3)

    // If odd power, multiply once more
    if (power % 2 != 0)
    {
        result = multiply(result, A, n);  // O(n^3)
    }

    return result;
}

int main()
{
    int n, p;
    cout << "Enter matrix size n: ";
    cin >> n;
    vector<vector<long long>> A(n, vector<long long>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter power: ";
    cin >> p;

    vector<vector<long long>> result = matrixPower(A, n, p);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
Line by Line TC + SC:
- multiply(): O(n^3) time, O(n^2) space for result matrix
- matrixPower(): Recursively calls itself log(power) times → O(log power)
- Each recursion involves at most 2 multiplications → O(n^3) each
- Total Time Complexity = O(n^3 * log(power))
- Space Complexity = O(n^2 + log(power)) → O(n^2)
*/
