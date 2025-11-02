// Implement fast exponentiation (a^n using divide and conquer).
#include <bits/stdc++.h>
using namespace std;

// Function to perform fast exponentiation using divide and conquer
long long power(long long a, long long n)
{
    // Base case
    if (n == 0)
        return 1;
    // Recursive step
    long long half = power(a, n / 2);  // TC: O(log n), SC: O(log n) due to recursion
    if (n % 2 == 0)
        return half * half;  // TC: O(1), SC: O(1)
    else
        return a * half * half;  // TC: O(1), SC: O(1)
}

int main()
{
    long long a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    return 0;
}

/*
----------------------------------------
⏳ Time Complexity (line by line):
- Base case check (n == 0) → O(1)
- Recursive call (power(a, n/2)) → O(log n) calls
- Multiplication operations → O(1) per level
=> Total TC: O(log n)

💾 Space Complexity (line by line):
- Function call stack → O(log n)
- No extra arrays used
=> Total SC: O(log n)
----------------------------------------
*/
