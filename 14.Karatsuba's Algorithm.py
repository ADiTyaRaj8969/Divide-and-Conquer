# Implement Karatsuba’s Algorithm for large integer multiplication.
def karatsuba(x, y):
    # Base case: single digit multiplication
    if x < 10 or y < 10:
        return x * y  # O(1)

    # Calculate the size of the numbers
    n = max(len(str(x)), len(str(y)))
    m = n // 2

    # Split the numbers
    high1, low1 = divmod(x, 10**m)
    high2, low2 = divmod(y, 10**m)

    # Recursive multiplications
    z0 = karatsuba(low1, low2)               # O(T(n/2))
    z1 = karatsuba(low1 + high1, low2 + high2)  # O(T(n/2))
    z2 = karatsuba(high1, high2)             # O(T(n/2))

    # Combine results
    return (z2 * 10**(2*m)) + ((z1 - z2 - z0) * 10**m) + z0

"""
Time Complexity:
T(n) = 3T(n/2) + O(n)
=> O(n^log2(3)) ≈ O(n^1.585)

Space Complexity:
- Recursion depth: O(log n)
- Temporary variables: O(n) (due to string conversions/divmod)
- Overall: O(log n)
"""

# Example usage
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
print("Product:", karatsuba(a, b))
