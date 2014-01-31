def gcd(x, y):
    return gcd(y, x % y) if y else x

if __name__ == '__main__':
    pq = b // a
    for p in xrange(int(pq ** 0.5), 0, -1):
        if pq % p == 0 and gcd(p, pq // p) == 1:
            print a * p, a * pq // p
            break