base = [str(x) for x in range(10)] + [ chr(x) for x in range(ord('A'), ord('A') + 6)]

def dec2bin(a):
    num = a
    mid = []
    while True:
        if num == 0: break
        num, rem = divmod(num, 2)
        mid.append(base[rem])
    #''.join([str(x) for x in mid[::-1]])
    ans = 0;
    for x in mid[:]:
        if x == '1':
            ans += 1
    return ans

if __name__ == '__main__':
    print dec2bin(a)