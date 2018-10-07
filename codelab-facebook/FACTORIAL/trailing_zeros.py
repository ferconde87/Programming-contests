import math

def trailingZeroes(self, A):
    fact = str(math.factorial(A))
    return len(fact) - len(fact.rstrip('0'))

    
def trailingZeroes2(self, A):
    fact = math.factorial(A)
    count = 0
    while fact != 1:
        rem = fact % 10
        fact = fact / 10
        if rem != 0:
            break
        count = count + 1
    return count