from functools import cache
from decimal import Decimal, ROUND_HALF_UP, getcontext

# Set the precision high enough to handle the calculations
getcontext().prec = 100

# A memoized recursive approach
# since for the golden ratio we need
# to also compute fib(n-1) and we can just
# pull that right out of the cache.
# Otherwise, a for-loop bottom up approach
# would've been better.
@cache
def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

def round_half_up(number, decimals=2):
    """
    Rounds a number to a specified number of decimal places using the ROUND_HALF_UP method.
    
    Args:
        number (float): The number to round.
        decimals (int): The number of decimal places to round to.
        
    Returns:
        float: The rounded number.
    """
    if decimals < 0:
        raise ValueError("Decimal places must be non-negative")
    rounding_format = '1.' + '0' * decimals
    decimal_number = Decimal(str(number))
    rounded_number = decimal_number.quantize(Decimal(rounding_format), rounding=ROUND_HALF_UP)
    return float(rounded_number)

# Prevent EOF error
try:
    while True:
        user_input = input()
        if not user_input.strip():
            continue  # Skip empty inputs
        n = float(user_input)

        if n < 0 or n != int(n):
            print("Invalid input")
        else:
            n = int(n)
            fibN = fib(n)

            if n > 1:
                fib_n_minus_1 = fib(n - 1)
                golden_ratio = fibN / fib_n_minus_1
                # Round the golden ratio to 2 decimal places using round-half-up
                golden_ratio_rounded = round_half_up(golden_ratio, 2)
                print(fibN, golden_ratio_rounded)
            else:
                print(fibN, "No golden ratio")
except EOFError:
    pass
