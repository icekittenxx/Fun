def dlt(x):
    n = len(x)
    for i in xrange(0, n-1):
        if (x[i]=='��') and (x[i+1] in ['Ǫ','��','ʰ','��','��']):
            del x[i+1]
            return True
    if x[0]=='��' and n>2:
        del x[0]
        return True
    return False

if __name__ == '__main__':
    M = [] if a >= 0 else ['��']
    a = abs(a)

    d = ['��', 'Ҽ', '��', '��', '��', '��', '½', '��', '��', '��']
    L = [0, 'Ǫ', 0, '��', 0, 'ʰ', 0, '��', 0, 'Ǫ', 0, '��', 0, 'ʰ', 0, 'Բ']
    for i in xrange(14, -1, -2):
        L[i], a = d[a % 10], a // 10
    while dlt(L): pass

    print ''.join(M + L)