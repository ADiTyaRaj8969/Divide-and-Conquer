// Multiply two large integers using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

// Function to multiply two large integers using Divide & Conquer
long long multiply(long long x, long long y) {
    // Base case
    if (x < 10 || y < 10) return x * y; 
    // TC: O(1), SC: O(1)

    int n = max((int)log10(x) + 1, (int)log10(y) + 1); // digits
    int m = n / 2;

    long long p = pow(10, m);

    long long Xl = x / p;  // Left part of x
    long long Xr = x % p;  // Right part of x
    long long Yl = y / p;  // Left part of y
    long long Yr = y % p;  // Right part of y
    // Splitting → TC: O(1), SC: O(1)

    // Recursive multiplications
    long long Z0 = multiply(Xr, Yr);      // TC: T(n/2)
    long long Z1 = multiply(Xl + Xr, Yl + Yr); // TC: T(n/2)
    long long Z2 = multiply(Xl, Yl);      // TC: T(n/2)

    // Karatsuba combination
    return Z2 * pow(10, 2 * m) + (Z1 - Z2 - Z0) * pow(10, m) + Z0;
    // TC: O(1), SC: O(1)
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << "Product = " << multiply(a, b) << endl;
    return 0;
}
