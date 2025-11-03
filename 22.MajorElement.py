# Solve the majority element problem (find element occurring more than n/2 times).
def countFreq(arr, l, r, x):
    cnt = 0
    for i in range(l, r + 1):
        cnt += (arr[i] == x)  # O(r-l+1) → O(n)
    return cnt  # O(1)

def majorityElement(arr, l, r):
    if l == r:
        return arr[l]  # Base case O(1)

    mid = (l + r) // 2  # O(1)

    left = majorityElement(arr, l, mid)      # T(n/2)
    right = majorityElement(arr, mid + 1, r) # T(n/2)

    if left == right:
        return left  # O(1)

    leftCount = countFreq(arr, l, r, left)   # O(n)
    rightCount = countFreq(arr, l, r, right) # O(n)

    return left if leftCount > rightCount else right # O(1)

# Driver
n = int(input())  # Input size O(1)
arr = list(map(int, input().split()))  # O(n)

print(majorityElement(arr, 0, n - 1))  # O(n log n)

"""
-------------------------------
⏱ TIME COMPLEXITY (Line by Line)
-------------------------------
Base case → O(1)
Divide step → O(1)
Recursive calls → 2T(n/2)
Merge step (count) → O(n)

=> T(n) = O(n log n)

-------------------------------
💾 SPACE COMPLEXITY
-------------------------------
Recursion stack depth = O(log n)
No extra storage → O(1)
Total SC = O(log n)
"""
