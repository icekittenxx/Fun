if __name__ == '__main__':
    year, month, day = int(t['year']), int(t['month']), int(t['day'])
    hour, minute, second = int(t['hour']), int(t['minute']), int(t['second'])
    print '%04d-%02d-%02d %02d:%02d:%02d' % (year, month, day, hour, minute, second)