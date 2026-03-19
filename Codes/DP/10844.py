

N = int(input())
DIV_NUM = 1000000000
dp = [[0 for _ in range(10)] for __ in range(N)]
dp[0] = [0,1,1,1,1,1,1,1,1,1]

for j in range(1, N) :
    dp[j][0] = dp[j-1][1] % DIV_NUM
    for i in range(1, 9) :
        dp[j][i] = (dp[j-1][i-1] + dp[j-1][i+1]) % DIV_NUM
    dp[j][9] = dp[j-1][8] % DIV_NUM

sum = 0
for i in range(0, 10) :
    sum = (sum + dp[N-1][i]) % DIV_NUM
print(sum)