# Implement Strassen’s Matrix Multiplication Algorithm.
# Strassen's Matrix Multiplication
# Time Complexity (TC): O(n^log7) ≈ O(n^2.81)
# Space Complexity (SC): O(n^2) for intermediate matrices

def add(A, B):
    n = len(A)
    # TC: O(n^2), SC: O(n^2)
    return [[A[i][j] + B[i][j] for j in range(n)] for i in range(n)]

def subtract(A, B):
    n = len(A)
    # TC: O(n^2), SC: O(n^2)
    return [[A[i][j] - B[i][j] for j in range(n)] for i in range(n)]

def strassen(A, B):
    n = len(A)
    C = [[0] * n for _ in range(n)]

    if n == 1:
        C[0][0] = A[0][0] * B[0][0]
        return C

    newSize = n // 2

    # Splitting matrices
    # TC: O(n^2), SC: O(n^2)
    A11 = [[A[i][j] for j in range(newSize)] for i in range(newSize)]
    A12 = [[A[i][j] for j in range(newSize, n)] for i in range(newSize)]
    A21 = [[A[i][j] for j in range(newSize)] for i in range(newSize, n)]
    A22 = [[A[i][j] for j in range(newSize, n)] for i in range(newSize, n)]

    B11 = [[B[i][j] for j in range(newSize)] for i in range(newSize)]
    B12 = [[B[i][j] for j in range(newSize, n)] for i in range(newSize)]
    B21 = [[B[i][j] for j in range(newSize)] for i in range(newSize, n)]
    B22 = [[B[i][j] for j in range(newSize, n)] for i in range(newSize, n)]

    # Strassen’s 7 multiplications
    # TC: 7T(n/2)
    M1 = strassen(add(A11, A22), add(B11, B22))
    M2 = strassen(add(A21, A22), B11)
    M3 = strassen(A11, subtract(B12, B22))
    M4 = strassen(A22, subtract(B21, B11))
    M5 = strassen(add(A11, A12), B22)
    M6 = strassen(subtract(A21, A11), add(B11, B12))
    M7 = strassen(subtract(A12, A22), add(B21, B22))

    # Combine results
    C11 = add(subtract(add(M1, M4), M5), M7)
    C12 = add(M3, M5)
    C21 = add(M2, M4)
    C22 = add(subtract(add(M1, M3), M2), M6)

    for i in range(newSize):
        for j in range(newSize):
            C[i][j] = C11[i][j]
            C[i][j + newSize] = C12[i][j]
            C[i + newSize][j] = C21[i][j]
            C[i + newSize][j + newSize] = C22[i][j]

    return C


# Driver code
n = int(input("Enter size of matrix (power of 2): "))
print("Enter matrix A:")
A = [list(map(int, input().split())) for _ in range(n)]
print("Enter matrix B:")
B = [list(map(int, input().split())) for _ in range(n)]

C = strassen(A, B)

print("Resultant Matrix:")
for row in C:
    print(*row)
