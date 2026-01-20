
MAX_LENGTH = 1001
MODULUS = 10007

dp = [0] * MAX_LENGTH
dp[1] = 1
dp[2] = 3

for i in range(3, MAX_LENGTH) :
    dp[i] = (2*dp[i-2] + dp[i-1]) % MODULUS

num = int(input())
print(dp[num])