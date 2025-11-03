# Find the n-th Fibonacci number using matrix exponentiation.
MOD = 10**9 + 7  # optional if modulus is required

def multiply(A, B):
    return [
        [(A[0][0]*B[0][0] + A[0][1]*B[1][0]) % MOD,
         (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % MOD],
        [(A[1][0]*B[0][0] + A[1][1]*B[1][0]) % MOD,
         (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % MOD]
    ]

def power_matrix(A, n):
    if n == 0 or n == 1:
        return A
    half = power_matrix(A, n // 2)
    half = multiply(half, half)
    if n % 2 != 0:
        half = multiply(half, [[1,1],[1,0]])
    return half

def fib(n):
    if n == 0:
        return 0
    A = [[1,1],[1,0]]
    result = power_matrix(A, n-1)
    return result[0][0]  # F(n)

# Input
n = int(input())
print(fib(n))

"""
----------------------------------------
⏳ Time Complexity: O(log n)
💾 Space Complexity: O(log n) (recursion depth)
----------------------------------------
"""
