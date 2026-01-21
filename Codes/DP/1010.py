
import sys

rows = 31
cols = 31

dp = [[1 for j in range(cols)] for i in range(rows)]


for y in range(1, rows) :
    for x in range(y+1, cols) :
        dp[y][x] = dp[y][x-1] + dp[y-1][x-1]

rpt = int(input())

for i in range(rpt) : 
    N, M = map(int, sys.stdin.readline().split())
    print(dp[N][M])