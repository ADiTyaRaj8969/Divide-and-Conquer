// Find the square root of a number using binary search (without using sqrt()).
#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n) {
    // TC: O(1), SC: O(1)
    if (n == 0 || n == 1) return n; // base cases

    int low = 1, high = n, ans = 0; 
    // TC: O(1), SC: O(1)

    while (low <= high) { 
        // Loop runs O(log n) times
        int mid = low + (high - low) / 2;  
        // TC: O(1) per step, SC: O(1)

        if (mid <= n / mid) {  
            // safe check to avoid overflow
            ans = mid;          // TC: O(1)
            low = mid + 1;      // TC: O(1)
        } else {
            high = mid - 1;     // TC: O(1)
        }
    }
    // Total TC: O(log n), SC: O(1)
    return ans;
}

int main() {
    int n;
    cin >> n;  // Input number, TC: O(1), SC: O(1)

    cout << squareRoot(n) << endl;
    // Output result
}
