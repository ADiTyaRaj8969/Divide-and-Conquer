# Implement integer division without using / or % using divide and conquer.
def divide(dividend: int, divisor: int) -> int:
    if divisor == 0:
        raise ZeroDivisionError("Division by zero")  # O(1), O(1)
    if dividend == 0:
        return 0  # O(1), O(1)

    # Handle sign
    neg = (dividend < 0) ^ (divisor < 0)  # O(1), O(1)
    a, b = abs(dividend), abs(divisor)    # O(1), O(1)

    if a < b:
        return 0  # base case, O(1)

    sum_, multiple = b, 1  # O(1), O(1)

    # Doubling divisor using divide and conquer
    # Time: O(log(a/b)), Space: O(1)
    while (sum_ + sum_) <= a:
        sum_ += sum_         # double divisor
        multiple += multiple # double multiplier

    # Recursive step for remainder
    # Time: T(n) = T(n/2) + O(log n) = O(log^2 n)
    result = multiple + divide(a - sum_, b)

    return -result if neg else result  # restore sign


# Example usage
dividend, divisor = map(int, input().split())
print(divide(dividend, divisor))
