def gcd(a, b):
    if a < b:
        return gcd(b, a)
    else:
        if b:
            return gcd(b, a % b)
        else:
            return a
print gcd(a, b)