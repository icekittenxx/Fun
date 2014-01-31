def is_palindrome(s, m):
    s = " " + s
    for k in xrange(0, len(s) - m + 1):
        if s[k: k + m] == s[k + m - 1: k - 1: -1]:
            return "YES"
    return "NO"

if __name__ == '__main__':
    print is_palindrome(a, n)