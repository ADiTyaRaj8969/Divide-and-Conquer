# Implement power of matrix using divide and conquer.
def multiply(A, B, n):
    # Multiply two matrices
    C = [[0] * n for _ in range(n)]
    for i in range(n):                # O(n)
        for j in range(n):            # O(n)
            for k in range(n):        # O(n)
                C[i][j] += A[i][k] * B[k][j]  # O(1)
    return C

def matrix_power(A, n, power):
    if power == 1:
        return A                      # Base case
    
    # Divide
    half = matrix_power(A, n, power // 2)  # O(log power)
    
    # Conquer
    result = multiply(half, half, n)       # O(n^3)
    
    if power % 2 != 0:
        result = multiply(result, A, n)    # O(n^3)
    
    return result

# Driver Code
n = int(input("Enter matrix size n: "))
A = []
print("Enter matrix elements:")
for _ in range(n):
    A.append(list(map(int, input().split())))

p = int(input("Enter power: "))

result = matrix_power(A, n, p)

print("Resultant Matrix:")
for row in result:
    print(*row)

"""
Line by Line TC + SC:
- multiply(): O(n^3) time, O(n^2) space for result
- matrix_power(): O(log power) recursive calls
- Each recursion does at most 2 multiplications → O(n^3)
- Total Time Complexity = O(n^3 * log(power))
- Space Complexity = O(n^2 + log(power)) ~ O(n^2)
"""
