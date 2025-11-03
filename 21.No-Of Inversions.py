# Count the number of inversions in an array.
def merge_and_count(arr, l, m, r):
    left = arr[l:m+1]   # Left subarray (O(n1))
    right = arr[m+1:r+1] # Right subarray (O(n2))

    i = j = 0
    k = l
    inv_count = 0

    # Merge process (O(n1 + n2))
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
            inv_count += (len(left) - i)  # Inversions (O(1))
        k += 1

    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1

    return inv_count

def merge_sort_and_count(arr, l, r):
    inv_count = 0
    if l < r:
        m = (l + r) // 2

        inv_count += merge_sort_and_count(arr, l, m)     # Left half (O(n log n))
        inv_count += merge_sort_and_count(arr, m + 1, r) # Right half (O(n log n))
        inv_count += merge_and_count(arr, l, m, r)       # Merge step (O(n))
    return inv_count

# Driver code
n = int(input()) # O(1)
arr = list(map(int, input().split())) # O(n)
print(merge_sort_and_count(arr, 0, n - 1)) # O(n log n)

"""
----------------------
Time Complexity:
- merge_and_count(): O(n) per merge
- Recursion: O(n log n)
- Overall: O(n log n)

Space Complexity:
- Temporary arrays left[], right[]: O(n)
- Recursion stack: O(log n)
- Overall: O(n)
----------------------
"""
