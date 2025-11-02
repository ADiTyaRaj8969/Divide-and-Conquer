// Multiply two matrices using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

// Function to add two matrices
vector<vector<int>> add(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    // TC: O(n^2), SC: O(n^2)
    for (int i = 0; i < n; i++)
    {  // O(n)
        for (int j = 0; j < n; j++)
        {                                 // O(n)
            C[i][j] = A[i][j] + B[i][j];  // O(1)
        }
    }
    return C;  // SC: O(n^2)
}

// Function to subtract two matrices
vector<vector<int>> subtract(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    // TC: O(n^2), SC: O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Recursive multiplication function
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();

    // Base case: single element
    if (n == 1)
    {
        return {{A[0][0] * B[0][0]}};  // O(1)
    }

    int mid = n / 2;

    // Dividing matrices into 4 parts (SC: O(n^2) for submatrices)
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)),
        A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)),
        B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    // Splitting matrices (TC: O(n^2))
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Recursive multiplications (7 calls in Strassen, here 8 calls)
    vector<vector<int>> C11 = add(multiply(A11, B11), multiply(A12, B21));  // O(n^3)
    vector<vector<int>> C12 = add(multiply(A11, B12), multiply(A12, B22));
    vector<vector<int>> C21 = add(multiply(A21, B11), multiply(A22, B21));
    vector<vector<int>> C22 = add(multiply(A21, B12), multiply(A22, B22));

    // Combine results
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;  // SC: O(n^2)
}

int main()
{
    int n;
    cin >> n;  // Matrix size (must be power of 2 for simplicity)

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> A[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> B[i][j];
    }

    vector<vector<int>> C = multiply(A, B);

    cout << "Result Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}

/*
--------------------------------
Time Complexity (Divide & Conquer Normal Multiplication):
T(n) = 8T(n/2) + O(n^2)  -> O(n^3)

Space Complexity:
O(n^2) (for matrices & recursion stack)
--------------------------------
*/
