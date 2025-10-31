# Find the square root of a number using binary search (without using sqrt()).
def squareRoot(n):
    # TC: O(1), SC: O(1)
    if n == 0 or n == 1:
        return n  # base cases

    low, high = 1, n
    ans = 0  # TC: O(1), SC: O(1)

    while low <= high:  
        # Loop runs O(log n) times
        mid = (low + high) // 2  
        # TC: O(1), SC: O(1)

        if mid <= n // mid:  
            # safe check
            ans = mid      # TC: O(1)
            low = mid + 1  # TC: O(1)
        else:
            high = mid - 1 # TC: O(1)

    # Total TC: O(log n), SC: O(1)
    return ans


n = int(input())  # Input number, TC: O(1), SC: O(1)
print(squareRoot(n))  # Output result
