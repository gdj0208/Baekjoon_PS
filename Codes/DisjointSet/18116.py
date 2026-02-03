
import sys
input = sys.stdin.readline

class Alg :
    def __init__(self):
        self.parent = [i for i in range(1000001)]
        self.size = [1 for i in range(1000001)]

    def get_root(self, num):
        if self.parent[num] == num:
            return num
        self.parent[num] = self.get_root(self.parent[num])
        return self.parent[num]
    
    def unite(self, n1, n2):
        root1 = self.get_root(n1)
        root2 = self.get_root(n2)

        if root1 == root2 :
            return

        self.parent[root2] = root1
        self.size[root1] += self.size[root2]

    def get_set_size(self, num):
        root = self.get_root(num)
        return self.size[root]  

    def solve(self) :
        rpt = int(input())

        for _ in range(rpt):
            line = input().split()

            comm = line[0]
            params = list(map(int, line[1:]))

            if comm == 'I':
                self.unite(params[0], params[1])
            elif comm == 'Q':
                print(self.get_set_size(params[0]))



alg = Alg()
alg.solve()