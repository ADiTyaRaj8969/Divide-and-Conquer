# Implement algorithm to compute GCD of two numbers using divide and conquer.
def gcd(a, b):
    # normalize signs
    a = abs(a)                 # TC: O(1), SC: O(1)
    b = abs(b)                 # TC: O(1), SC: O(1)

    if b == 0:                 # Base case: if b==0, gcd is a
        return a               # TC: O(1), SC: O(1)

    # Divide & Conquer: reduce problem to gcd(b, a % b)
    # Recursive call reduces the magnitude (size) of arguments.
    return gcd(b, a % b)       # TC: overall O(log(min(a,b))) average, SC: O(recursion depth) = O(log(min(a,b)))
