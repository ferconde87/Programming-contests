def power(self, A):
    n = int(A)
    if n == 1:
        return 0
    if (n & (n-1)) == 0:
        return 1
    return 0