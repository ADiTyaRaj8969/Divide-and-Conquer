# Use divide and conquer for polynomial multiplication.
def poly_multiply(A, B):
    n = len(A)   # O(1) SC
    if n == 1:   # Base case O(1) TC
        return [A[0] * B[0]]  # O(1) TC, O(1) SC

    mid = n // 2   # Divide step O(1) TC
    # Divide arrays into low and high halves
    A_low, A_high = A[:mid], A[mid:]   # O(n) TC, O(n) SC
    B_low, B_high = B[:mid], B[mid:]   # O(n) TC, O(n) SC

    # Recursive calls (Divide and Conquer)
    P1 = poly_multiply(A_low, B_low)     # T(n/2)
    P2 = poly_multiply(A_high, B_high)   # T(n/2)
    P3 = poly_multiply([A_low[i] + A_high[i] for i in range(mid)], 
                       [B_low[i] + B_high[i] for i in range(mid)])   # T(n/2), O(n) TC for addition

    # Combine results
    res = [0] * (2 * n - 1)   # O(n) SC
    for i in range(len(P1)):  # O(n) TC
        res[i] += P1[i]
    for i in range(len(P2)):  # O(n) TC
        res[i + n] += P2[i]
    for i in range(len(P3)):  # O(n) TC
        res[i + mid] += P3[i] - P1[i] - P2[i]

    return res  # Final merged polynomial


# Example usage
A = [1, 2, 3, 4]  # Represents 1 + 2x + 3x² + 4x³
B = [4, 3, 2, 1]  # Represents 4 + 3x + 2x² + x³
print("Result Polynomial:", poly_multiply(A, B))

"""
---------------------------
Overall Time Complexity:
- T(n) = 3T(n/2) + O(n)
- By Master Theorem → O(n^(log2(3))) ≈ O(n^1.585)  (Faster than O(n²))
---------------------------
Overall Space Complexity:
- Recursion stack depth = O(log n)
- Extra space for results = O(n)
- Total = O(n log n)
"""
