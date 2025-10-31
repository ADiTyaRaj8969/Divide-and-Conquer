# Find the maximum and minimum of an array using divide and conquer.
def find_min_max(arr, l, r):
    # Base Case 1: Only one element
    if l == r:
        # TC = O(1), SC = O(1)
        return arr[l], arr[l]

    # Base Case 2: Two elements
    if r == l + 1:
        # TC = O(1), SC = O(1)
        if arr[l] < arr[r]:
            return arr[l], arr[r]
        else:
            return arr[r], arr[l]

    # Divide
    mid = (l + r) // 2  # TC = O(1), SC = O(1)

    # Conquer
    left_min, left_max = find_min_max(arr, l, mid)      # TC = T(n/2), SC = O(log n)
    right_min, right_max = find_min_max(arr, mid+1, r)  # TC = T(n/2), SC = O(log n)

    # Combine
    final_min = min(left_min, right_min)   # TC = O(1)
    final_max = max(left_max, right_max)   # TC = O(1)

    return final_min, final_max


# Driver
n = int(input())  
arr = list(map(int, input().split()))

mn, mx = find_min_max(arr, 0, n-1)
print("Minimum:", mn, "Maximum:", mx)

"""
Time Complexity:
- Recurrence: T(n) = 2T(n/2) + O(1) => O(n)

Space Complexity:
- Recursive stack depth = O(log n)
"""
