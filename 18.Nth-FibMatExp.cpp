// Find the n-th Fibonacci number using matrix exponentiation.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;  // optional if modulus is required

// Multiply two 2x2 matrices
void multiply(ll A[2][2], ll B[2][2])
{
    ll x = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    ll y = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    ll z = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    ll w = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

// Raise matrix to power n using fast exponentiation
void powerMatrix(ll A[2][2], ll n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    powerMatrix(A, n / 2);
    multiply(A, A);

    if (n % 2 != 0)
        multiply(A, M);
}

// Function to find n-th Fibonacci
ll fib(ll n)
{
    if (n == 0)
        return 0;
    ll A[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(A, n - 1);
    return A[0][0];  // F(n)
}

int main()
{
    long long n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

/*
----------------------------------------
⏳ Time Complexity:
- powerMatrix does O(log n) multiplications
- Each multiplication = O(1)
=> TC = O(log n)

💾 Space Complexity:
- Recursion depth = O(log n)
=> SC = O(log n)
----------------------------------------
*/
