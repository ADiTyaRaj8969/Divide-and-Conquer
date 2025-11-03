# Implement fast exponentiation (a^n using divide and conquer).
def power(a, n):
    # Base case
    if n == 0:
        return 1   # TC: O(1), SC: O(1)
    
    # Recursive step
    half = power(a, n // 2)  # TC: O(log n), SC: O(log n) due to recursion
    
    if n % 2 == 0:
        return half * half   # TC: O(1), SC: O(1)
    else:
        return a * half * half  # TC: O(1), SC: O(1)

# Input
a, n = map(int, input().split())
print(power(a, n))

"""
----------------------------------------
⏳ Time Complexity:
- Each step reduces n by half → O(log n)
- Multiplication per step → O(1)
=> Total TC: O(log n)

💾 Space Complexity:
- Recursion depth → O(log n)
- No extra data structures
=> Total SC: O(log n)
----------------------------------------
"""
