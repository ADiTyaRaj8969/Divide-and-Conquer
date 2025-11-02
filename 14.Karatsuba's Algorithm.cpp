// Implement Karatsuba’s Algorithm for large integer multiplication.
#include <bits/stdc++.h>
using namespace std;

// Karatsuba multiplication function
long long karatsuba(long long x, long long y)
{
    // Base case: single digit multiplication
    if (x < 10 || y < 10)
        return x * y;  // O(1)

    // Find the size of the numbers
    int n = max((int)to_string(x).size(), (int)to_string(y).size());
    int m = n / 2;

    // Split numbers
    long long high1 = x / (long long)pow(10, m);
    long long low1 = x % (long long)pow(10, m);
    long long high2 = y / (long long)pow(10, m);
    long long low2 = y % (long long)pow(10, m);

    // Recursive multiplications
    long long z0 = karatsuba(low1, low2);                      // O(T(n/2))
    long long z1 = karatsuba((low1 + high1), (low2 + high2));  // O(T(n/2))
    long long z2 = karatsuba(high1, high2);                    // O(T(n/2))

    // Combine results
    return (z2 * pow(10, 2 * m)) + ((z1 - z2 - z0) * pow(10, m)) + z0;
}

/*
Time Complexity Analysis:
- Each step does 3 recursive calls of size n/2.
- Recurrence: T(n) = 3T(n/2) + O(n)
- By Master Theorem → T(n) = O(n^log2(3)) ≈ O(n^1.585)

Space Complexity Analysis:
- Recursion stack depth: O(log n)
- Temporary variables: O(n) due to string conversion (can be optimized)
- Overall: O(log n)
*/

int main()
{
    long long a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Product: " << karatsuba(a, b) << endl;
    return 0;
}
