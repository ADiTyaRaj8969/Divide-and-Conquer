// Implement integer division without using / or % using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

// Divide and conquer integer division
int divide(int dividend, int divisor)
{
    // Handle edge cases
    if (divisor == 0)
        throw runtime_error("Division by zero");
    if (dividend == 0)
        return 0;

    // Handle sign
    bool neg = (dividend < 0) ^ (divisor < 0);  // O(1) time, O(1) space
    long a = labs(dividend);                    // O(1), space O(1)
    long b = labs(divisor);                     // O(1), space O(1)

    if (a < b)
        return 0;  // base case, O(1)

    long sum = b;       // current divisor multiple, O(1)
    long multiple = 1;  // quotient contribution, O(1)

    // Doubling loop → Divide & Conquer step
    // Time: O(log(a/b)), Space: O(1)
    while ((sum + sum) <= a)
    {
        sum += sum;            // double the divisor
        multiple += multiple;  // double the multiplier
    }

    // Recursive step on the remainder (a - sum)
    // Time: T(n) = T(n/2) + O(log n) → O(log^2 n)
    return (neg ? -1 : 1) * (multiple + divide(a - sum, b));
}

int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl;
    return 0;
}
