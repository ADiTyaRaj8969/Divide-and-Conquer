# Find the k-th smallest element using QuickSort partitioning (QuickSelect).
def partition(arr, low, high):
    pivot = arr[high]   # TC: O(1), SC: O(1)
    i = low             # TC: O(1), SC: O(1)
    for j in range(low, high):  # TC: O(n), SC: O(1)
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]  # TC: O(1), SC: O(1)
            i += 1
    arr[i], arr[high] = arr[high], arr[i]  # TC: O(1), SC: O(1)
    return i  # TC: O(1), SC: O(1)

def quickSelect(arr, low, high, k):
    if low <= high:  # TC: O(1), SC: O(1)
        pi = partition(arr, low, high)  # TC: O(n), SC: O(1)
        
        if pi == k:   # TC: O(1), SC: O(1)
            return arr[pi]
        elif pi > k:  # TC: O(1), SC: O(1)
            return quickSelect(arr, low, pi - 1, k)  # TC: T(n/2), SC: O(log n)
        else:
            return quickSelect(arr, pi + 1, high, k)  # TC: T(n/2), SC: O(log n)
    return -1  # TC: O(1), SC: O(1)

# Example usage
n = int(input("Enter size: "))
k = int(input("Enter k (0-based index): "))
arr = list(map(int, input("Enter elements: ").split()))

print(quickSelect(arr, 0, n - 1, k))

"""
📌 Time Complexity:
- Best/Average: O(n)
- Worst case: O(n^2)
📌 Space Complexity:
- O(1) extra space
- O(log n) recursion stack (average), O(n) worst case
"""
