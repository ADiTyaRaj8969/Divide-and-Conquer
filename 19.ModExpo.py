# Implement modular exponentiation (a^b % m) using divide and conquer.
def mod_exp(a, b, m):
    # TC: O(log b), SC: O(log b)
    if b == 0:
        return 1 % m   # O(1)
    half = mod_exp(a, b // 2, m)  # O(log b / 2)
    result = (half * half) % m    # O(1)
    if b % 2 == 1:                # O(1)
        result = (result * a) % m
    return result

# Example usage
a, b, m = map(int, input().split())
print(mod_exp(a, b, m))
