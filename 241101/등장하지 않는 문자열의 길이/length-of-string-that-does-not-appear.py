def get_min():
    s_len = int(input())
    s = input()
    for i in range(1, int(s_len/2)):
        sub = []
        repeat = False
        for p in range(s_len-i+1):
            if s[p:p+i] in sub:
                repeat = True
                break
            else:
                sub.append(s[p:p+i])
        if not repeat:
            print(i)
            return
    print(int(s_len/2)+1)

get_min()