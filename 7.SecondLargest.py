# Find the second largest element using divide and conquer.
import math

def findSecondLargest(arr, l, r):
    # Base case: single element
    if l == r:  # O(1)
        return arr[l], -math.inf  

    # Base case: two elements
    if r == l + 1:  # O(1)
        if arr[l] > arr[r]:
            return arr[l], arr[r]
        else:
            return arr[r], arr[l]

    mid = (l + r) // 2  # O(1)

    # Recursive calls → T(n/2) + T(n/2)
    left = findSecondLargest(arr, l, mid)   
    right = findSecondLargest(arr, mid + 1, r)

    # Merge results → O(1)
    if left[0] > right[0]:
        largest = left[0]
        second_largest = max(left[1], right[0])
    else:
        largest = right[0]
        second_largest = max(right[1], left[0])

    return largest, second_largest

# Driver
arr = [10, 20, 5, 40, 30, 50]
largest, second_largest = findSecondLargest(arr, 0, len(arr) - 1)
print("Largest:", largest, "Second Largest:", second_largest)

"""
Time Complexity:
- Each recursive step = O(1) merge
- Recurrence: T(n) = 2T(n/2) + O(1) → O(n)

Space Complexity:
- Recursion stack = O(log n)
- Extra variables = O(1)
- Total = O(log n)
"""
