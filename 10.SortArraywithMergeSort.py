# Sort an array of strings using Merge Sort.
def merge(arr, l, m, r):
    # TC: O(n) for merging two halves
    # SC: O(n) for temporary arrays
    n1 = m - l + 1
    n2 = r - m

    L = arr[l:m+1]  # O(n1)
    R = arr[m+1:r+1]  # O(n2)

    i = j = 0
    k = l

    while i < len(L) and j < len(R):  # O(n)
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < len(L):  # O(n1)
        arr[k] = L[i]
        i += 1
        k += 1

    while j < len(R):  # O(n2)
        arr[k] = R[j]
        j += 1
        k += 1


def merge_sort(arr, l, r):
    # Recurrence: T(n) = 2T(n/2) + O(n)
    # Master theorem → T(n) = O(n log n)
    if l < r:
        m = (l + r) // 2
        merge_sort(arr, l, m)      # O(log n) levels
        merge_sort(arr, m + 1, r)  # O(log n) levels
        merge(arr, l, m, r)


# Driver code
arr = ["pear", "apple", "orange", "banana", "grape"]
merge_sort(arr, 0, len(arr) - 1)
print("Sorted strings:", arr)

"""
⚡ Time Complexity:
- Divide: O(log n)
- Merge: O(n) per level
- Total: O(n log n)

⚡ Space Complexity:
- Temporary arrays in merge → O(n)
- Recursion stack → O(log n)
- Total: O(n)
"""
