
import sys

class Disjoint_set :
    def __init__(self, num_node):
        self.parent = list(range(num_node+1))
        self.rank = [0] * (num_node+1)
        self.num_cycle = 0

    def get_root(self, num):
        while(self.parent[num] != num) :
            num = self.parent[num]
        return num
    
    def join(self, num1, num2) :
        root1 = self.get_root(num1)
        root2 = self.get_root(num2)

        if(root1 != root2) :
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            elif self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            else : 
                self.parent[root2] = root1
                self.rank[root1] += 1
        else :
            self.num_cycle += 1



num_node, rpt = map(int, sys.stdin.readline().split())
ds = Disjoint_set(num_node=num_node)

for i in range(rpt) :
    node1, node2 = map(int, sys.stdin.readline().split())
    ds.join(node1, node2)

cnt = 0
for n1 in range(1, num_node+1) :
    if n1 == ds.parent[n1] :
        cnt += 1

print(ds.num_cycle + cnt-1)
