
'''
1. 트리 생성
2. 노드별 레벨 할당
3. 전위 순회하여 너비 x좌표값 부여
    - 각 레벨별 최소값과 최대값 저장
4. 각 레벨별 너비 구하기
'''
class Node :
    def __init__(self, num = 0, left = -1, right = -1, parent = 0, level = 0, x = 0):
        self.num = num
        self.left = left
        self.right = right
        self.parent = parent
        self.level = level
        self.x = x

class Alg :
    def solve(self):
        self.levels = {}
        tree = self.get_tree()
        root = self.get_root(tree=tree)
        self.give_num(tree, node_num = root, x = 1, level = 1)
        # self.print_in_order(tree, 1)
        ans = self.get_largest_level(tree=tree)
        print(ans[0], ans[1])

    def get_tree(self) :
        num_node = int(input())
        tree = [Node(num = i) for i in range(1, num_node+2) ]

        for i in range(1, num_node+1):
            parent, left, right = map(int, input().split())

            if left != -1 :
                tree[parent].left = left
                tree[left].parent = parent
                
            if right != -1 :
                tree[parent].right = right
                tree[right].parent = parent

        return tree

    def get_root(self, tree):
        for i in range(1,len(tree)):
            if tree[i].parent == 0:
                return i

    def give_num(self, tree, node_num, x, level):
        cur = node_num
        parent = node_num
        left = tree[cur].left
        right = tree[cur].right
        next_x = x
        
        if tree[cur].left != -1 :
            next_x = self.give_num(tree=tree, node_num=left, x=next_x, level=level+1)
        
        tree[cur].level = level
        tree[cur].x = next_x
        next_x += 1
        
        if level not in self.levels:
            self.levels[level] = []
        self.levels[level].append(tree[cur].x)


        if tree[cur].right != -1 :
            next_x = self.give_num(tree=tree, node_num=right, x=next_x, level=level+1)
        
        return next_x

    def print_in_order(self, tree, node_num):
        cur = node_num
        left = tree[cur].left
        right = tree[cur].right

        if tree[cur].left != -1 :
            self.print_in_order(tree, left)
        
        print(cur, end=" ")

        if tree[cur].right != -1 :
            self.print_in_order(tree, right)

    def get_largest_level(self, tree):
        max_diff = 1
        max_level = 1

        for i in range(1, len(self.levels)+1) :
            min_x, max_x = min(self.levels[i]), max(self.levels[i])
            diff = max_x - min_x + 1

            if max_diff < diff :
                max_level = i
                max_diff = diff

        return max_level, max_diff

alg = Alg()
alg.solve()