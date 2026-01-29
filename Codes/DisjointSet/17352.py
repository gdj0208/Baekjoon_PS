class Alg :
    def solve(self) :
        num_island = int(input())
        root = [i for i in range(num_island + 1)]


        def get_root(idx) :
            if idx == root[idx]:
                return idx
            root[idx] = get_root(root[idx])
            return root[idx]
        
        def union_root(idx1, idx2) :
            root1 = get_root(idx1)
            root2 = get_root(idx2)

            if root1 < root2 : 
                root[root2] = root1
            else :
                root[root1] = root2

        for i in range(num_island-2) :
            island1, island2 = map(int, input().split())
            union_root(island1, island2)

        root1 = get_root(1)
        for i in range(1,num_island+1) :
            cmp_root = get_root(i)
            if cmp_root != root1:
                print(1, i)
                break

alg = Alg()
alg.solve()