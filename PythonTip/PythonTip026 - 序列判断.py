if __name__ == '__main__':
    U = sorted(L)
    D = U[:: -1]
    print 'UP' if U == L else 'DOWN' if D == L else 'WRONG'