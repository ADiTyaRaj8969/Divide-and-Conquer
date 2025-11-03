# Implement convex hull (divide-and-conquer approach).
from typing import List, Tuple

Point = Tuple[float, float]

# ------------------ Utility ------------------

def cross(o: Point, a: Point, b: Point) -> float:
    # TC: O(1), SC: O(1)
    return (a[0]-o[0])*(b[1]-o[1]) - (a[1]-o[1])*(b[0]-o[0])

def rotate_idx(h: List[Point], i: int) -> int:
    # TC: O(1), SC: O(1)
    n = len(h)
    return (i + n) % n

def rightmost(h: List[Point]) -> int:
    # Find index of rightmost (max x, break ties by min y)
    # TC: O(|h|), SC: O(1)
    idx = 0
    for i in range(1, len(h)):  # TC: O(|h|)
        if h[i][0] > h[idx][0] or (h[i][0] == h[idx][0] and h[i][1] < h[idx][1]):
            idx = i
    return idx  # O(1)

def leftmost(h: List[Point]) -> int:
    # Find index of leftmost (min x, break ties by min y)
    # TC: O(|h|), SC: O(1)
    idx = 0
    for i in range(1, len(h)):  # TC: O(|h|)
        if h[i][0] < h[idx][0] or (h[i][0] == h[idx][0] and h[i][1] < h[idx][1]):
            idx = i
    return idx  # O(1)

# ------------------ Merge two convex hulls (both CCW) ------------------

def merge_hulls(L: List[Point], R: List[Point]) -> List[Point]:
    # Assumes L and R are convex hulls in CCW order, no duplicates across sets.
    # TC: O(|L| + |R|), SC: O(1) extra (output excluded)

    # Upper tangent
    i = rightmost(L)        # TC: O(|L|)
    j = leftmost(R)         # TC: O(|R|)
    moved = True            # O(1)
    while moved:            # Each loop advances i or j and wraps ≤ |L|+|R| times
        moved = False       # O(1)
        # Move j while turn at (L[i], R[j], R[j+1]) is counter-clockwise
        while cross(L[i], R[j], R[(j+1) % len(R)]) > 0:  # Amortized O(|R|)
            j = (j + 1) % len(R)  # O(1)
            moved = True          # O(1)
        # Move i while turn at (R[j], L[i], L[i-1]) is clockwise
        while cross(R[j], L[i], L[(i-1) % len(L)]) < 0:  # Amortized O(|L|)
            i = (i - 1) % len(L)  # O(1)
            moved = True          # O(1)
    ui, uj = i, j                 # O(1)

    # Lower tangent
    i = rightmost(L)        # TC: O(|L|)
    j = leftmost(R)         # TC: O(|R|)
    moved = True            # O(1)
    while moved:            # Amortized O(|L| + |R|)
        moved = False       # O(1)
        # Move j while turn at (L[i], R[j], R[j-1]) is clockwise
        while cross(L[i], R[j], R[(j-1) % len(R)]) < 0:  # Amortized O(|R|)
            j = (j - 1) % len(R)  # O(1)
            moved = True          # O(1)
        # Move i while turn at (R[j], L[i], L[i+1]) is counter-clockwise
        while cross(R[j], L[i], L[(i+1) % len(L)]) > 0:  # Amortized O(|L|)
            i = (i + 1) % len(L)  # O(1)
            moved = True          # O(1)
    li, lj = i, j                 # O(1)

    # Build merged hull in CCW: L from ui -> li, then R from lj -> uj
    merged = []                   # O(1) init; SC: O(|L|+|R|) for output
    # Traverse L: from ui to li (inclusive)
    k = ui                        # O(1)
    merged.append(L[k])           # Amortized O(1)
    while k != li:                # Visits ≤ |L| vertices → O(|L|)
        k = (k + 1) % len(L)      # O(1)
        merged.append(L[k])       # O(1)
    # Traverse R: from lj to uj (inclusive)
    k = lj                        # O(1)
    merged.append(R[k])           # O(1)
    while k != uj:                # Visits ≤ |R| vertices → O(|R|)
        k = (k + 1) % len(R)      # O(1)
        merged.append(R[k])       # O(1)

    return merged                 # O(1)

# ------------------ Base hull for ≤ 3 points ------------------

def base_hull(pts: List[Point]) -> List[Point]:
    # Returns convex hull CCW for up to 3 points (removes inner collinear middle).
    # TC: O(1) since size ≤ 3; SC: O(1)
    pts = sorted(pts)             # O(1) for ≤3
    if len(pts) <= 1:
        return pts
    if len(pts) == 2:
        return pts
    a,b,c = pts                   # O(1)
    if abs(cross(a,b,c)) < 1e-12: # Collinear
        return [a,c]              # Keep endpoints
    # Make CCW
    if cross(a,b,c) > 0:
        return [a,b,c]
    else:
        return [a,c,b]

# ------------------ Divide & Conquer driver ------------------

def convex_hull_divide_and_conquer(points: List[Point]) -> List[Point]:
    # Sort & unique by (x,y)
    # TC: O(n log n), SC: O(n) for sorted copy
    pts = sorted(set(points))
    n = len(pts)                  # O(1)
    if n <= 3:                    # O(1)
        return base_hull(pts)     # O(1)

    mid = n // 2                  # O(1)
    # Recurse on left & right halves
    LH = convex_hull_divide_and_conquer(pts[:mid])   # T(n/2)
    RH = convex_hull_divide_and_conquer(pts[mid:])   # T(n/2)
    # Merge two convex hulls
    return merge_hulls(LH, RH)    # O(n)

# ------------------ Example ------------------
if __name__ == "__main__":
    pts = [(0,0),(1,1),(2,2),(0,3),(3,0),(3,3),(1,2),(2,1)]
    hull = convex_hull_divide_and_conquer(pts)
    print(hull)

"""
==================== OVERALL COMPLEXITY ====================
Time Complexity:
- Sorting points: O(n log n)
- Divide & Conquer: T(n) = 2T(n/2) + O(n) merge  => O(n log n)
- Overall: O(n log n)

Space Complexity:
- Sorting copy + output hull: O(n)
- Recursion depth: O(log n)
- Extra merge workspace: O(1) (besides output)
- Overall: O(n)
============================================================
"""
