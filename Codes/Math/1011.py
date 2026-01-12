
import math 

class Alg :
    def solve(self) :
        rpt = int(input())
        for _ in range(rpt):
            n1, n2 = map(int, input().split())
            dist = n2 - n1

            print(self.get_jump_cnt(dist))
            
        
    def get_jump_cnt(self, dist) :
        n = 0

        while dist > n*(n+1) :
            n += 1

        if dist <= n**2:
            return(2*n - 1)
        else :
            return(2*n)

    
alg = Alg()
alg.solve()
