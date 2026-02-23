
size= int(input())
arr = list(map(int, input().split()))
stk = []
max = 0

for num in arr :
    if len(stk) == 0 :
        stk.append(num)
    else :
        if stk[-1] > num :
            stk.append(num)
        else :
            dif = num - stk[-1]
            max = dif if (dif > max) else max

print(max)