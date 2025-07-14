import sys
sys.setrecursionlimit(10**6)

class Alg :
    def solve(self):
        num_of_nodes, rpt = map(int, input().split())
        roots = [i for i in range(num_of_nodes+1)]

        # print(roots)

        for _ in range(rpt):
            op, n1, n2 = map(int, input().split())
            
            if op == 0:
                self.uni_set(root=roots, n1=n1, n2=n2)
            else : 
                if self.find_root(root=roots, num=n1) == self.find_root(root=roots, num=n2) :
                    print("YES")
                else :
                    print("NO")
    
    def find_root(self, root, num) :
        if root[num] != num :
            root[num] = self.find_root(root, root[num])
        return root[num]

    def uni_set(self, root, n1, n2) :
        p1 = self.find_root(root=root, num=n1)
        p2 = self.find_root(root=root, num=n2)

        if p1 < p2 :
            root[p2] = p1
        else :
            root[p1] = p2

alg = Alg()
alg.solve()
