class Node :
    def __init__(self, num):
        self.num = num
        self.dist = 0
        self.level = 0
        self.visit = False
        self.parent = None
        self.adjs = []

class Alg :
    def solve(self):
        num_node, num_search = map(int, input().split())
        graph = self.get_graph(num_node)
        self.get_min_dist(nodes=graph, num_search=num_search)

    def get_graph(self, num_node):
        nodes = [Node(num=i) for i in range(num_node+1)]
        edges = [[0 for _ in range(num_node + 1)] for _ in range(num_node + 1)]

        for _ in range(num_node-1) :
            v1, v2, w = map(int, input().split())
            nodes[v1].adjs.append(v2)
            nodes[v2].adjs.append(v1)
            edges[v1][v2] = edges[v2][v1] = w

        self.get_dist(nodes=nodes, edges=edges)

        return nodes
    
    def get_dist(self, nodes, edges) :
        queue = []
        queue.append(1)
        nodes[1].visit = True

        while(queue) :
            cur = queue.pop(0)

            for adj in nodes[cur].adjs :
                if nodes[adj].visit == True:
                    continue

                nodes[adj].parent = cur
                nodes[adj].dist = nodes[cur].dist + edges[cur][adj]
                nodes[adj].level = nodes[cur].level + 1
                nodes[adj].visit = True
                queue.append(adj)

    def get_min_dist(self, nodes, num_search) :
        for _ in range(num_search) :
            n1, n2 = map(int, input().split())
            p = self.get_lca(nodes=nodes, n1=n1, n2=n2)
            print(nodes[n1].dist + nodes[n2].dist - 2*nodes[p].dist)

    def get_lca(self, nodes, n1, n2):
        v1, v2 = n1, n2
        while nodes[v1].level > nodes[v2].level :
            v1 = nodes[v1].parent
        while nodes[v1].level < nodes[v2].level :
            v2 = nodes[v2].parent
        while v1 != v2 :
            v1 = nodes[v1].parent
            v2 = nodes[v2].parent
        return v1

alg = Alg()
alg.solve()
'''
5 1
1 2 1
2 3 1
3 4 10
3 5 1
1 5
'''