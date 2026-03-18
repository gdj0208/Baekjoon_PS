
num1, num2 = map(int, input().split())
lv_list = []

def solve(n1, n2, lv) :
    if n1 == n2:
        lv_list.append(lv)
        return
    
    if (n1 > n2):
        return
    
    solve(n1* 2, n2, lv+1)
    solve(10*n1 + 1, n2, lv+1)

solve(num1, num2, 1)

if(len(lv_list) == 0) :
    print(-1)
else :
    print(min(lv_list))
