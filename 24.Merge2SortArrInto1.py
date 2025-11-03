# Merge two sorted arrays into one using divide and conquer.
def merge_arrays(arr1, arr2, result, l1, r1, l2, r2, idx):
    # Time Complexity: O(n1 + n2), where n1 and n2 are lengths of subarrays
    # Space Complexity: O(log(n1+n2)) due to recursion stack

    if l1 > r1:
        while l2 <= r2:
            result[idx] = arr2[l2]
            l2 += 1
            idx += 1
        return

    if l2 > r2:
        while l1 <= r1:
            result[idx] = arr1[l1]
            l1 += 1
            idx += 1
        return

    if arr1[l1] < arr2[l2]:
        result[idx] = arr1[l1]
        merge_arrays(arr1, arr2, result, l1+1, r1, l2, r2, idx+1)
    else:
        result[idx] = arr2[l2]
        merge_arrays(arr1, arr2, result, l1, r1, l2+1, r2, idx+1)

# Driver code
n = int(input())
m = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

result = [0] * (n+m)

merge_arrays(arr1, arr2, result, 0, n-1, 0, m-1, 0)

print(" ".join(map(str, result)))
