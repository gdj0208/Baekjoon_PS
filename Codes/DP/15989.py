
import sys
from collections import deque
input = sys.stdin.readline

class Alg :
    def __init__(self):
        ...


    def solve(self) :
        dp = [0 for _ in range(10001)]
        dp[1] = 1
        dp[2] = 2
        dp[3] = 3

        for i in range(4, 10001):
            dp[i] = dp[i-3] + int(i/2) + 1

        rpt = int(input())
        for _ in range(rpt):
            num = int(input())
            print(dp[num])


alg = Alg()
alg.solve()

