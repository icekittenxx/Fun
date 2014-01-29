def gcd(a, b):
    if a < b:
        return gcd(b, a)
    else:
        if b:
            return gcd(b, a % b)
        else:
            return a
def lcm(a, b):
    ans = a * b / gcd(a, b)
    return ans
print lcm(a, b)