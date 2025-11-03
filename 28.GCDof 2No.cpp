// Implement algorithm to compute GCD of two numbers using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    a = llabs(a);  // TC: O(1), SC: O(1)
    b = llabs(b);  // TC: O(1), SC: O(1)

    if (b == 0)    // TC: O(1)
        return a;  // TC: O(1), SC: O(1)

    // Divide & Conquer: reduce to smaller subproblem
    return gcd(b, a % b);  // TC: overall O(log(min(a,b))), SC: O(recursion depth)
}

int main()
{
    long long x = 48, y = 18;
    cout << gcd(x, y) << "\n";
    return 0;
}

/*
OVERALL (Euclidean recursive)
Time Complexity: O(log(min(a,b))) on typical inputs (worst-case Θ(log n) with Fibonacci-like inputs)
Space Complexity: O(log(min(a,b))) recursion stack; iterative variant uses O(1).
*/
