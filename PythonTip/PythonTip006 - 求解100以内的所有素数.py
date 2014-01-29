def primeNumber(n):
    ans = []
    ans.append(str(2))
    for i in range(3, n + 1):
        result = True
        for j in range(2, i - 1):
            if i % j == 0:
                result = False
        if result == True:
            ans.append(str(i))
    print(" ".join(ans))
primeNumber(100)