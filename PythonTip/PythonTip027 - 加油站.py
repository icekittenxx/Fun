def solve(s):
	gas = 0
	for i in xrange(s, s + n):
		gas += limit[i % n] - cost[i % n]
		if gas < 0:
			return False
	return True

if __name __ == '__main__':
    s = 0
    while s < n:
        if solve(s):
            print s
            break
        s = s + 1
    if s == n:
        print -1