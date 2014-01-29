m, k = 0, 0

def main(n):
    global m, k
    if n % 2 == 0:
        m += 1
        main(n / 2)
    elif n % 5 == 0:
        k += 1
        main(n / 5)
            
if __name__ == '__main__':
    global m, k
    
    for i in L:
        main(i)
    print min(m, k)