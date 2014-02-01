if __name__ == '__main__':
    L.sort()
    flag = False
    for idx in xrange(1, len(L)):
        if L[idx - 1] == L[idx]:
            flag = True
            break
    print 'YES' if flag else 'NO'