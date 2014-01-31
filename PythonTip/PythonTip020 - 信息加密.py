import string
if __name__ == '__main__':
    sigma = string.lowercase
    table = string.maketrans(sigma, sigma[b:] + sigma[:b])
    print a.encode('ascii').translate(table)