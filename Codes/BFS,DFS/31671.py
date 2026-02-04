
import sys
from collections import deque
input = sys.stdin.readline

class Alg :
    def __init__(self):
        ...

    def is_out_of_range(self, y, x, m):
        if x <= m :
            return y > x or y < 0
        else :
            return y > 2*m - x or y < 0

    def solve(self) :
        mount_size, num_teacher = map(int, input().split())
        teacher = [-1 for _ in range(2*mount_size+1)]

        dp = [[0 for _ in range(2*mount_size+1)] for _ in range(mount_size+1)]

        for _ in range(num_teacher):
            x,y = map(int, input().split())
            dp[y][x] = -1

        peak = -1

        list = deque([[0,0]])
        dp[0][0] = 1
        while len(list) > 0:
            y, x = list.popleft()

            if self.is_out_of_range(y+1, x+1 , mount_size) == False and (dp[y+1][x+1] == 0) :
                dp[y+1][x+1] = 1
                list.append([y+1, x+1])
            
            if(self.is_out_of_range(y-1, x+1 , mount_size) == False and dp[y-1][x+1] == 0):
                dp[y-1][x+1] = 1
                list.append([y-1, x+1])

        list = deque([[0, 2*mount_size]])
        dp[0][2*mount_size] = 2
        while len(list) > 0:
            y, x = list.popleft()

            next_coords = [[y+1, x-1], [y-1, x-1]]

            for ny, nx in next_coords:
                if self.is_out_of_range(ny, nx, mount_size) == False:
                    if dp[ny][nx] != -1 and dp[ny][nx] != 2:
                        
                        if dp[ny][nx] == 1:
                            peak = ny if peak < ny else peak
                        
                        dp[ny][nx] = 2
                        list.append([ny, nx])

        print(peak)


alg = Alg()
alg.solve()

