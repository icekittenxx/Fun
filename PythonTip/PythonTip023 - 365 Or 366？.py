if __name__ == '__main__':
    y = int(year)
    print 366 if y % 4 == 0 and y % 100 or y % 400 == 0 else 365