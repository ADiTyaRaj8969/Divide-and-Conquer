# Function to merge two skylines
def mergeSkylines(left, right):
    # TC: O(1), SC: O(1) -> variable initialization
    h1, h2 = 0, 0  
    i, j = 0, 0  
    merged = []  # TC: O(1), SC: O(n) -> storing merged skyline
    while i < len(left) and j < len(right):  # TC: O(n)
        if left[i][0] < right[j][0]:  # TC: O(1)
            x, h1 = left[i]  # TC: O(1)
            i += 1  # TC: O(1)
        else:
            x, h2 = right[j]  # TC: O(1)
            j += 1  # TC: O(1)
        max_h = max(h1, h2)  # TC: O(1)
        if not merged or merged[-1][1] != max_h:  # TC: O(1)
            merged.append([x, max_h])  # TC: O(1)
    merged.extend(left[i:])   # TC: O(n), SC: O(n)
    merged.extend(right[j:])  # TC: O(n), SC: O(n)
    return merged  # TC: O(1), SC: O(1)

# Recursive function (divide & conquer)
def getSkyline(buildings):
    # Base case
    if not buildings:  # TC: O(1)
        return []  # TC: O(1)
    if len(buildings) == 1:  # TC: O(1)
        x1, x2, h = buildings[0]  # TC: O(1)
        return [[x1, h], [x2, 0]]  # TC: O(1)

    mid = len(buildings) // 2  # TC: O(1)
    left = getSkyline(buildings[:mid])   # TC: T(n/2)
    right = getSkyline(buildings[mid:])  # TC: T(n/2)
    return mergeSkylines(left, right)    # TC: O(n)

# Driver Code
buildings = [[2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8]]
result = getSkyline(buildings)
print("Skyline:", result)

"""
Overall Time Complexity: O(n log n)  
- Divide into halves → log n levels  
- Each merge takes O(n)  

Overall Space Complexity: O(n)  
- Recursion depth O(log n)  
- Skyline storage O(n)  
"""
