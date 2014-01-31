def gcd(x, y):
    return gcd(y, x % y) if y else x
    
if __name__ == '__main__':
    n, cnt, x = gcd(a, b), 1, 2
    while x * x <= n:
        k = 1
        while n % x == 0:
            n = n // x
            k += 1
        cnt = cnt * k
        x = x + 1
    if n > 1:
        cnt = cnt * 2
        
    print cnt