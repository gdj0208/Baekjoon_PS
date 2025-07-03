class Alg:
    def solve(self) :
        size = int(input())
        parents = list(map(int, input().split()))
        remove_node = int(input())

        self.remove_branch(remove_node, parents)
        print(self.get_leaves(parents))

    def remove_branch(self, node, parents) :
        parents[node] = -2
        for i in range(len(parents)) :
            if node == parents[i]:
                self.remove_branch(i, parents)

    def get_leaves(self, parents):
        count = 0

        for i in range(len(parents)):
            if parents[i] != -2 and i not in parents:
                count += 1

        return count
    
alg = Alg()
alg.solve()