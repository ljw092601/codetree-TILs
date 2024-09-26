x, y = map(int, input().split())

p_num = 0
for i in range(x, y+1):
    if str(i) == str(i)[::-1]:
        p_num += 1
print(p_num)