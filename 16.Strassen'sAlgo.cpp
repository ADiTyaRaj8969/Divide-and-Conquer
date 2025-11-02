// Implement Strassen’s Matrix Multiplication Algorithm.
#include <bits/stdc++.h>
using namespace std;

// Strassen's Matrix Multiplication
// Time Complexity (TC): O(n^log7) ≈ O(n^2.81)
// Space Complexity (SC): O(n^2) for storing intermediate matrices

vector<vector<int>> add(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    // TC: O(n^2), SC: O(n^2) temporary storage
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> subtract(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    // TC: O(n^2), SC: O(n^2) temporary storage
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) C[i][j] = A[i][j] - B[i][j];
    return C;
}

vector<vector<int>> strassen(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Base case: single element multiplication
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
        A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize)),
        B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
        B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    // Splitting matrices into quadrants
    // TC: O(n^2), SC: O(n^2)
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen’s 7 multiplications
    // TC: 7T(n/2)
    auto M1 = strassen(add(A11, A22), add(B11, B22));
    auto M2 = strassen(add(A21, A22), B11);
    auto M3 = strassen(A11, subtract(B12, B22));
    auto M4 = strassen(A22, subtract(B21, B11));
    auto M5 = strassen(add(A11, A12), B22);
    auto M6 = strassen(subtract(A21, A11), add(B11, B12));
    auto M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Combining results into C
    // TC: O(n^2), SC: O(n^2)
    auto C11 = add(subtract(add(M1, M4), M5), M7);
    auto C12 = add(M3, M5);
    auto C21 = add(M2, M4);
    auto C22 = add(subtract(add(M1, M3), M2), M6);

    // Final join
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

int main()
{
    int n;
    cout << "Enter size of matrix (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];

    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> B[i][j];

    auto C = strassen(A, B);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << C[i][j] << " ";
        cout << endl;
    }
}
