
width = int(input())
dp = [0 for _ in range(width + 1)]

dp[0] = 1
if width >= 2:
    dp[2] = 3

if width >= 4 :
    for i in range(4, width+1) :
        dp[i] = 4*dp[i-2] - dp[i-4]

print(dp[width])