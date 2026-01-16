
rpt = int(input())
arr = []
dp = [0]*rpt

for _ in range(rpt) :
    start, end, people = list(map(int, input().split()))
    arr.append([end, start, people])

arr.sort()
dp[0] = arr[0][2]
for i in range(1, rpt) :
    dp[i] = max(dp[i-1], dp[i-2]+arr[i][2])

print(dp[rpt-1])
