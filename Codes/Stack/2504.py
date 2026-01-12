stk = list()
str1 = str(input())

ans = 0
tmp = 1

for i in range(len(str1)):
    if str1[i] == '(':
        tmp *= 2
        stk.append('(')
    elif str1[i] == '[':
        tmp *= 3
        stk.append('[')
    elif str1[i] == ')':
        if(len(stk) == 0 or stk[-1] != '('):
            ans = 0
            break
        elif(str1[i-1] == '('):
            ans += tmp
            tmp /= 2
            stk.pop()
        else:
            tmp /= 2
            stk.pop()
    elif str1[i] == ']':
        if(len(stk) == 0 or stk[-1] != '['):
            ans = 0
            break
        elif(str1[i-1] == '['):
            ans += tmp
            tmp /= 3
            stk.pop()
        else:
            tmp /= 3
            stk.pop()

if(len(stk) != 0) :
    ans = 0
    
print(int(ans))