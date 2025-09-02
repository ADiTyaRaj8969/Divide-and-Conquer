# Find the first and last occurrence of an element in a sorted array.

def first_occurrence(arr, x):
    low, high, ans = 0, len(arr) - 1, -1  # TC: O(1), SC: O(1)
    while low <= high:  # TC: log(n) iterations
        mid = (low + high) // 2  # TC: O(1)
        if arr[mid] == x:
            ans = mid       # TC: O(1)
            high = mid - 1  # move left
        elif arr[mid] < x:
            low = mid + 1   # TC: O(1)
        else:
            high = mid - 1  # TC: O(1)
    return ans  # TC: O(1)


def last_occurrence(arr, x):
    low, high, ans = 0, len(arr) - 1, -1  # TC: O(1), SC: O(1)
    while low <= high:  # TC: log(n) iterations
        mid = (low + high) // 2  # TC: O(1)
        if arr[mid] == x:
            ans = mid       # TC: O(1)
            low = mid + 1   # move right
        elif arr[mid] < x:
            low = mid + 1   # TC: O(1)
        else:
            high = mid - 1  # TC: O(1)
    return ans  # TC: O(1)


# Main execution
n, x = map(int, input().split())  # TC: O(1), SC: O(1)
arr = list(map(int, input().split()))  # TC: O(n), SC: O(n)

first = first_occurrence(arr, x)  # TC: O(log n), SC: O(1)
last = last_occurrence(arr, x)    # TC: O(log n), SC: O(1)

print("First occurrence =", first)
print("Last occurrence =", last)

"""
================= COMPLEXITY =================
Overall Time Complexity: O(n) for input + O(log n) + O(log n) 
=> O(n) overall, O(log n) for search only.

Overall Space Complexity: O(n) for array storage.
Extra Space Complexity: O(1).
"""
