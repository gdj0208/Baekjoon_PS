
class Alg :
    def solve(self) : 
        num_node, num_relation, money = map(int, input().split())
        money_req = list(map(int, input().split()))
        root = [i for i in range(num_node + 1)]
        
        for _ in range(num_relation) :
            n1, n2 = map(int, input().split())
            self.union(root=root, n1=n1, n2=n2)
           
        group_min_cost = dict()

        for i in range(1, num_node + 1):
            r = self.get_roots(root=root, cur_node=i)
            cost = money_req[i - 1]
            if r in group_min_cost:
                group_min_cost[r] = min(group_min_cost[r], cost)
            else:
                group_min_cost[r] = cost

        total = sum(group_min_cost.values())
        if total > money:
            print("Oh no")
        else:
            print(total)

    def union(self, root, n1, n2):
        r1 = self.get_roots(root=root,cur_node=n1)
        r2 = self.get_roots(root=root, cur_node=n2)
        if r1 > r2 :
            root[r1] = r2
        else :
            root[r2] = r1

    def get_roots(self, root, cur_node) :
        if root[cur_node] == cur_node :
            return cur_node
        return self.get_roots(root = root, cur_node=root[cur_node])

alg = Alg()
alg.solve()
