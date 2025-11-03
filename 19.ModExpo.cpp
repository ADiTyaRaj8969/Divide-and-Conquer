// Implement modular exponentiation (a^b % m) using divide and conquer.
#include <bits/stdc++.h>
using namespace std;

// Function to calculate (a^b) % m using divide and conquer
long long modExp(long long a, long long b, long long m)
{
    // TC: O(log b), SC: O(log b) due to recursion
    if (b == 0)
        return 1 % m;                      // Base case -> O(1)
    long long half = modExp(a, b / 2, m);  // Recursive call -> O(log b / 2)
    long long result = (half * half) % m;  // Multiply halves -> O(1)
    if (b % 2 == 1)
        result = (result * a) % m;  // If odd power -> O(1)
    return result;
}

int main()
{
    long long a, b, m;
    cin >> a >> b >> m;  // Input -> O(1)

    cout << modExp(a, b, m) << endl;  // Output result -> O(1)
    return 0;
}

/*
Line-by-Line TC & SC:
1. Input a, b, m -> O(1), SC O(1)
2. Base case check (b==0) -> O(1), SC O(1)
3. Recursive call modExp(a, b/2, m) -> O(log b), SC O(log b) (stack)
4. Multiplication (half*half) % m -> O(1), SC O(1)
5. If b is odd, extra multiplication -> O(1), SC O(1)
6. Print result -> O(1), SC O(1)

Overall:
Time Complexity = O(log b)
Space Complexity = O(log b) (recursion stack)
*/
