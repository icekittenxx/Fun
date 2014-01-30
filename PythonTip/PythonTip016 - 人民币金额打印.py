def dlt(x):
    n = len(x)
    for i in xrange(0, n-1):
        if (x[i]=='Áã') and (x[i+1] in ['Çª','°Û','Ê°','Íò','Áã']):
            del x[i+1]
            return True
    if x[0]=='Áã' and n>2:
        del x[0]
        return True
    return False

if __name__ == '__main__':
    M = [] if a >= 0 else ['¸º']
    a = abs(a)

    d = ['Áã', 'Ò¼', '·¡', 'Èþ', 'ËÁ', 'Îé', 'Â½', 'Æâ', '°Æ', '¾Á']
    L = [0, 'Çª', 0, '°Û', 0, 'Ê°', 0, 'Íò', 0, 'Çª', 0, '°Û', 0, 'Ê°', 0, 'Ô²']
    for i in xrange(14, -1, -2):
        L[i], a = d[a % 10], a // 10
    while dlt(L): pass

    print ''.join(M + L)