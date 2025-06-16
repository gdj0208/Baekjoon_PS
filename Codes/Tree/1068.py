

class Alg:
    class Node:
        def __init__(self, num, parent):
            self.parent = parent
            self.num = num
            self.left = None
            self.right = None

    def __init__(self):
        self.num_of_nodes = int(input())
        self.nodes = []
        
        self.build_tree()

    def build_tree(self):
        inputs = list(map(int, input().split()))
        for i in range(len(inputs)):
            self.nodes.append(self.Node(i, inputs[i]))

            if inputs[i] == -1:
                continue
            elif self.nodes[inputs[i]].left is None:
                self.nodes[inputs[i]].left = i
            elif self.nodes[inputs[i]].right is None:
                self.nodes[inputs[i]].right = i

    def cut_tree(self, num):
        if self.nodes[num] is None:
            return
        if self.nodes[num].left is not None:
            self.cut_tree(self.nodes[num].left)
        if self.nodes[num].right is not None:
            self.cut_tree(self.nodes[num].right)

        self.nodes[num] = None

    def count_leaves(self, num):
        cnt = 0
        
        if self.nodes[num] is None:
            return 0
        if (self.nodes[num].left is None and self.nodes[num].right is None):
            return 1
        
        if self.nodes[num].left is not None:
            cnt += self.count_leaves(self.nodes[num].left)
        if self.nodes[num].right is not None:
            cnt += self.count_leaves(self.nodes[num].right)
            
        return cnt

    def print_tree(self,num):
        if self.nodes[num] is None:
            return
        print(num, end=' ')

        if self.nodes[num].left is not None:
            self.print_tree(self.nodes[num].left)
        if self.nodes[num].right is not None:
            self.print_tree(self.nodes[num].right)

alg = Alg()
# alg.print_tree(0)
cut_num = int(input())
alg.cut_tree(cut_num)
#alg.print_tree(0)
print(alg.count_leaves(0))