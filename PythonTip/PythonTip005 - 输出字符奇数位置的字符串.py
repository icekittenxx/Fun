result = []
for i in range(len(a)):
    if((i + 1) % 2):
        result.append(a[i])
print("".join(result))