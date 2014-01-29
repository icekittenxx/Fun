L.sort()
length = len(L)
d, m = divmod(length, 2)
if m:
    print L[d]
else:
    d1, m1 = divmod(L[d] + L[d - 1], 2)
    if m1 == 0:
        print d1
    else:
        print "%.1f" %((L[d] + L[d - 1]) / 2.0)
