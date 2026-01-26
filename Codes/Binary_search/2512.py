
import sys

def get_money(depts, money) :
    sum = 0
    
    for dept in depts :
        if dept >= money:
            sum += money
        else :
            sum += dept

    return sum

def find_ans(list, size, max) :
    start = 0
    end = list[size-1]
    ans = 0

    while(start <= end) :
        mid = (start + end) // 2
        
        sum = get_money(list, mid)

        if sum <= max :
            ans = mid
            start = mid+1
        else : 
            end = mid - 1
    return ans

num_dept = int(input())
depts = list(map(int, input().split()))
max = int(input())
depts.sort()

print(find_ans(depts, num_dept, max))