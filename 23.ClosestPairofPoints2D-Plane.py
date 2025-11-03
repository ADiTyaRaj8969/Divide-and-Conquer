# Implement divide-and-conquer algorithm for closest pair of points in 2D plane.
import math

# Function to calculate distance
def dist(p1, p2):
    # O(1)
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

# Brute force for small set
def brute_force(pts, l, r):
    # O((r-l)^2)
    mn = float("inf")
    for i in range(l, r+1):
        for j in range(i+1, r+1):
            mn = min(mn, dist(pts[i], pts[j]))  # O(1)
    return mn

# Function for strip closest
def strip_closest(strip, d):
    # Sort by y-coordinate O(n log n)
    strip.sort(key=lambda x: x[1])
    mn = d
    for i in range(len(strip)):
        j = i+1
        while j < len(strip) and (strip[j][1] - strip[i][1]) < mn:
            mn = min(mn, dist(strip[i], strip[j])) # O(1)
            j += 1
    return mn  # O(n)

# Divide and Conquer function
def closest_util(pts, l, r):
    if r - l <= 3:
        return brute_force(pts, l, r)  # O(1)

    mid = (l+r)//2
    midPoint = pts[mid]

    dl = closest_util(pts, l, mid)   # T(n/2)
    dr = closest_util(pts, mid+1, r) # T(n/2)

    d = min(dl, dr) # O(1)

    strip = []
    for i in range(l, r+1):
        if abs(pts[i][0] - midPoint[0]) < d:
            strip.append(pts[i])  # O(n)

    return min(d, strip_closest(strip, d)) # O(n)

# Main function
def closest_pair(pts):
    pts.sort()  # Sort by x O(n log n)
    return closest_util(pts, 0, len(pts)-1)

# Example usage
n = int(input())
pts = [tuple(map(int, input().split())) for _ in range(n)]
print("Closest distance =", closest_pair(pts))

"""
Time Complexity:
- Sorting O(n log n)
- Divide and Conquer recurrence T(n) = 2T(n/2) + O(n) → O(n log n)
Space Complexity:
- Recursive stack O(log n)
- Strip temporary array O(n)
Overall O(n)
"""
