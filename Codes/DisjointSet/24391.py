
class DisjointSet :
    def __init__(self, num_node):
        self.parent = list(range(num_node+1))

    def get_root(self, node):
        while(self.parent[node] != node) :
            node = self.parent[node]
        return node
    
    def unite(self, node1, node2) :
        root1 = self.get_root(node1)
        root2 = self.get_root(node2)

        if(root1 < root2) :
            self.parent[root2] = root1
        else :
            self.parent[root1] = root2



num_node, num_path = map(int, input().split())
ds = DisjointSet(num_node)

for i in range(num_path):
    n1, n2 = map(int, input().split())
    ds.unite(n1, n2)

path = list(map(int, input().split()))

count = 0
for i in range(len(path) - 1):
    if ds.get_root(path[i]) != ds.get_root(path[i+1]):
        count += 1
print(count)