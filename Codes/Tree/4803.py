
class Node :
    def __init__(self, num=0):
        self.num = num
        self.adjs = []
        self.root = num
        self.visit = False

class Alg :
    def solve(self):
        num_case = 1
        while(True):
            num_node, num_edge = map(int, input().split())
            if num_node == 0 and num_edge == 0 :
                break

            count = 0
            nodes = self.get_graph(num_node=num_node, num_edge=num_edge)

            for i in range(1, len(nodes)) :
                if self.is_tree(nodes=nodes, node_idx=i) :
                    count += 1

            self.print_ans(num_tree = count, case_num=num_case)
            num_case += 1

    def get_graph(self, num_node=0, num_edge=0) :
        graph = [Node(i) for i in range(num_node+1)]
        
        for _ in range(num_edge) :
            n1, n2 = map(int, input().split())
            graph[n1].adjs.append(n2)
            graph[n2].adjs.append(n1)

        return graph

    def is_tree(self, nodes, node_idx) :
        check = True

        if nodes[node_idx].visit == True:
            return False

        if len(nodes[node_idx].adjs) == 0:
            return True

        nodes[node_idx].visit = True
        for adj in nodes[node_idx].adjs :
            if nodes[adj].root == nodes[node_idx].root :
                if nodes[node_idx].parent == adj :
                    continue
                else :
                    return False
            
            nodes[adj].root = nodes[node_idx].root 
            nodes[adj].parent = node_idx
            check = self.is_tree(nodes, adj)

            if check == False :
                return False

        return check

    def print_ans(self, num_tree, case_num) :
        print("Case", str(case_num), end=": ")
        if num_tree == 0 :
            print("No trees.")
        elif num_tree == 1:
            print("There is one tree.")
        else :
            print("A forest of", num_tree, "trees.")


alg = Alg()
alg.solve()
