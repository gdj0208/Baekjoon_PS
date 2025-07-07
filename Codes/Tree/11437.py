class Tree:
    def __init__(self, node_num=0, parent=-1):
        self.node_num = node_num
        self.parent = parent
        self.depth = 0
        self.adj = []

class Alg:
    '''
    LCA 풀이 방법
    1. 트리의 루트를 기준으로 모든 노드들의 거리를 구한다.
    2. 노드 a,b의 거리를 구한다
    3. 노드 a,b의 거리를 비교하며 루트로 올라가면서 거리가 같은 동시에 값이 같을 때 까지 탐색
    '''
    def solve(self) : 
        tree = self.get_tree()
        
        rpt = int(input())
        for _ in range(rpt):
            node1, node2 = map(int, input().split())
            lca = self.get_LCA(tree, node1, node2)
            print(lca)
    
    def get_tree(self):
        tree = []
        node_num = int(input())

        for i in range(node_num + 1):
            tree.append(Tree(i, -1))

        for i in range(node_num-1):
            parent, child = map(int, input().split())
            if parent > child:
                parent, child = child, parent

            tree[parent].adj.append(child)
            tree[child].adj.append(parent)
            # tree[child].parent = parent
            ''' 부모는 set_tree_depth에서 설정한다. '''

        self.set_tree_depth(tree)
        
        return tree

    def set_tree_depth(self, tree) :
        from collections import deque

        visited = [False] * (len(tree)+1)
        queue = deque()
        queue.append(tree[1]) 
        visited[1] = True

        while queue :
            node = queue.popleft()
            for neighboor in node.adj:
                if visited[neighboor]:
                    continue

                tree[neighboor].parent = node.node_num
                tree[neighboor].depth = node.depth + 1
                visited[neighboor] = True
                queue.append(tree[neighboor])

    def get_LCA(self, tree, node1, node2):
        ''' binary lifting 또는 오일러 방문 + RMQ로도 해결 가능'''
        node1 = tree[node1]
        node2 = tree[node2]

        while True :
            if node1.node_num == node2.node_num and node1.depth == node2.depth:
                    return node1.node_num
            
            if node1.depth > node2.depth :
                node1 = tree[node1.parent]
            elif node1.depth < node2.depth :
                node2 = tree[node2.parent]
            else : 
                node1 = tree[node1.parent]
                node2 = tree[node2.parent]

    
alg = Alg()
alg.solve()