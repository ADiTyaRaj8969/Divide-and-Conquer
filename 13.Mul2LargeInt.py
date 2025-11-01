# Multiply two large integers using divide and conquer.
def multiply(x, y):
    # Base case
    if x < 10 or y < 10:
        return x * y  # TC: O(1), SC: O(1)

    n = max(len(str(x)), len(str(y)))
    m = n // 2

    p = 10 ** m

    Xl, Xr = divmod(x, p)
    Yl, Yr = divmod(y, p)
    # Splitting → TC: O(1), SC: O(1)

    # Recursive multiplications
    Z0 = multiply(Xr, Yr)          # TC: T(n/2)
    Z1 = multiply(Xl + Xr, Yl + Yr)  # TC: T(n/2)
    Z2 = multiply(Xl, Yl)          # TC: T(n/2)

    # Karatsuba formula
    return Z2 * (10 ** (2 * m)) + (Z1 - Z2 - Z0) * (10 ** m) + Z0
    # TC: O(1), SC: O(1)


a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
print("Product =", multiply(a, b))
