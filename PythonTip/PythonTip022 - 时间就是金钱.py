if __name__ == '__main__':
    stL = map(int, st.split(':'))
    stN = stL[0] * 3600 + stL[1] * 60 + stL[2]
    etL = map(int, et.split(':'))
    etN = etL[0] * 3600 + etL[1] * 60 + etL[2]
    print etN - stN