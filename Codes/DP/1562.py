N = int(input())
dp = [[[0 for _ in range(1024)] for _ in range(10)] for _ in range(N+1)]

for i in range(1,10) :
    dp[1][i][1<<i] = 1

for i in range(2, N + 1):
    for j in range(10):
        for k in range(1024):
            
            if j > 0:
                dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j-1][k]) % 1000000000
                
            if j < 9:
                dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j+1][k]) % 1000000000

ans = 0
for j in range(10):
    ans += dp[N][j][1023]
    ans %= 1000000000

print(ans)