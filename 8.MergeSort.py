# Implement Merge Sort.
def merge(arr, l, m, r):
    # TC: O(n) → merging step
    # SC: O(n) → temporary arrays
    n1 = m - l + 1
    n2 = r - m

    L = arr[l:m+1]  # SC: O(n1)
    R = arr[m+1:r+1] # SC: O(n2)

    i, j, k = 0, 0, l
    while i < n1 and j < n2:  # TC: O(n)
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:  # TC: O(n1)
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:  # TC: O(n2)
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, l, r):
    # Recurrence: T(n) = 2T(n/2) + O(n)
    # Master Theorem ⇒ O(n log n)
    # SC: O(n) auxiliary + O(log n) recursion
    if l < r:
        m = (l + r) // 2
        mergeSort(arr, l, m)   # T(n/2)
        mergeSort(arr, m+1, r) # T(n/2)
        merge(arr, l, m, r)    # O(n)

arr = [12, 11, 13, 5, 6, 7]
mergeSort(arr, 0, len(arr)-1)
print("Sorted array:", arr)
