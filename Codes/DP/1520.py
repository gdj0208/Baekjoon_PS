
import sys
sys.setrecursionlimit(10**6)

class Alg() : 

    def __init__(self):
        self.height, self.width = map(int, input().split())
        
        self.my_map = [[0] * self.width for _ in range(self.height)]
        self.my_dirs = [[-1] * self.width for _ in range(self.height)]
        #self.my_dirs[0][0] = 1
        
        self.next_pos = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    def init_map(self):
        for y in range(self.height):
            self.my_map[y] = list(map(int, input().split()))

    def run_bfs(self, cy, cx):
        if cy == self.height - 1 and cx == self.width - 1:
            return 1
        if self.my_dirs[cy][cx] != -1:
            return self.my_dirs[cy][cx]
        
        self.my_dirs[cy][cx] = 0
        for dy, dx in self.next_pos:
            ny = cy + dy
            nx = cx + dx

            if self.is_out_of_bounds(ny, nx):
                continue
            if self.is_avaliable_pos(cy, cx, ny, nx) == False:
                continue

            self.my_dirs[cy][cx] += self.run_bfs(ny, nx)

        return self.my_dirs[cy][cx]

    def is_out_of_bounds(self, y, x):
        return not (0 <= y < self.height and 0 <= x < self.width)
    
    def is_avaliable_pos(self, y, x, ny, nx):
        return self.my_map[y][x] > self.my_map[ny][nx]

    def print_available_dirs(self):
        print(self.my_dirs[0][0])


alg = Alg()
alg.init_map()
alg.run_bfs(0,0)
alg.print_available_dirs()