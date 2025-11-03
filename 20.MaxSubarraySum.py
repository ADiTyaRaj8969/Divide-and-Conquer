# Find the maximum subarray sum using divide and conquer.
import sys

def cross_sum(arr, l, m, r):
    # TC: O(n) (scan left + right)
    left_sum = -sys.maxsize
    right_sum = -sys.maxsize

    s = 0
    for i in range(m, l - 1, -1):  # O(n/2)
        s += arr[i]
        left_sum = max(left_sum, s)

    s = 0
    for i in range(m + 1, r + 1):  # O(n/2)
        s += arr[i]
        right_sum = max(right_sum, s)

    return left_sum + right_sum  # O(1)


def max_subarray(arr, l, r):
    if l == r:  # Base case O(1)
        return arr[l]

    m = (l + r) // 2

    # Divide into 3 cases
    left = max_subarray(arr, l, m)         # O(T(n/2))
    right = max_subarray(arr, m + 1, r)    # O(T(n/2))
    cross = cross_sum(arr, l, m, r)        # O(n)

    return max(left, right, cross)  # O(1)


n = int(input())
arr = list(map(int, input().split()))
print("Maximum Subarray Sum =", max_subarray(arr, 0, n - 1))

"""
🔹 Time Complexity (TC):
- cross_sum → O(n)
- Recurrence: T(n) = 2T(n/2) + O(n) → O(n log n)

🔹 Space Complexity (SC):
- O(log n) recursion stack
"""
