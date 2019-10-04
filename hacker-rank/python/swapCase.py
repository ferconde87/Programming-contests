def swap_case2(s):
    result = ""
    for c in s:
        if c.islower():
            result += c.upper()
        else:
            result += c.lower()
    return result

def swap_case(s):
    return s.swapcase()

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
