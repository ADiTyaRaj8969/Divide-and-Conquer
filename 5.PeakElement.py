# Find the peak element in an array using binary search.
def find_peak(arr):
    n = len(arr)  # O(1) TC, O(1) SC
    low, high = 0, n - 1  # O(1) TC, O(1) SC

    while low <= high:  # O(log n) iterations
        mid = (low + high) // 2  # O(1) TC, O(1) SC

        # Check if mid is a peak
        if (mid == 0 or arr[mid] >= arr[mid - 1]) and \
           (mid == n - 1 or arr[mid] >= arr[mid + 1]):
            return mid  # O(1) TC, O(1) SC

        elif mid > 0 and arr[mid - 1] > arr[mid]:
            high = mid - 1  # O(1) TC, O(1) SC
        else:
            low = mid + 1  # O(1) TC, O(1) SC
    return -1  # Should not reach if array has at least 1 element


arr = [1, 3, 20, 4, 1, 0]
print("Peak Element Index:", find_peak(arr))  # O(log n) TC, O(1) SC
