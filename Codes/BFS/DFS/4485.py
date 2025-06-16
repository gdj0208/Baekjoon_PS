class Alg:
    def __init__(self):
        self.mapsize = 0
        self.map = []
        self.move_x = [0, 0, -1, 1]
        self.move_y = [-1, 1, 0, 0]
        self.start = [0,0]
        self.end = [self.mapsize-1, self.mapsize-1]

    def get_map(self):
        my_map = []
        for i in range(self.mapsize):
            row = list(map(int, input().split()))
            my_map.append(row)
        self.visited = [[-1] * self.mapsize for _ in range(self.mapsize)]
        return my_map
    
    def get_min_path(self):
        queue = []
        queue.append(self.start)
        self.visited[0][0] = self.map[0][0]

        while queue:
            [cur_x, cur_y] = queue.pop(0)
            for i in range(4):
                next_x = cur_x + self.move_x[i]
                next_y = cur_y + self.move_y[i]

                if self.is_visitable(cur_x, cur_y, next_x, next_y):
                    self.visited[next_y][next_x] = self.visited[cur_y][cur_x] + self.map[next_y][next_x]
                    queue.append([next_x, next_y])

        return self.visited[self.mapsize-1][self.mapsize-1]

    def is_visitable(self, cur_x, cur_y, next_x, next_y):
        if next_x < 0 or next_x >= self.mapsize or next_y < 0 or next_y >= self.mapsize:
            return False
        
        if self.visited[next_y][next_x] == -1 :
            return True
        if self.visited[next_y][next_x] > self.visited[cur_y][cur_x] + self.map[next_y][next_x]:
            return True
        return False
    
    def print_visit(self):
        for i in range(self.mapsize):
            for j in range(self.mapsize):
                print(self.visited[i][j], " ")


rpt = 0
while True:
    alg = Alg()
    alg.mapsize = int(input())
    if alg.mapsize == 0:
        break
    alg.map = alg.get_map()
    rpt += 1
    
    #alg.print_visit()
    print(f"Problem {rpt}: {alg.get_min_path()}")