import sys

total, win = map(int, sys.stdin.readline().split())
rate = (win * 100) // total

start = 1
end = total

if rate >= 99 :
    print(-1)
else :
    while(start <= end) :
        mid = (start + end) // 2
        cur_rate = ((win + mid) *100) // (total + mid) 

        if rate < cur_rate :
            ans = mid
            end = mid - 1
        else :
            start = mid + 1
    print(ans)