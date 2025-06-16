import copy

class Alg:
    def __init__(self):
        self.height, self.width= map(int, input().split())
        self.ocean = [[0] * self.width for _ in range(self.height)]
        
        self.next_pos = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    def make_ocean(self):
        for y in range(self.height):
            self.ocean[y] = list(map(int, input().split()))

    def melt_ice(self):
        tmp = copy.deepcopy(self.ocean)
        for y in range(self.height):
            for x in range(self.width):
                if self.ocean[y][x] > 0:
                    tmp[y][x] -= self.get_adj_water(y, x)
        self.ocean = tmp
    
    def get_adj_water(self, y, x):
        count = 0
        for dy, dx in self.next_pos:
            ny, nx = y +dy, x + dx
            if 0 <= ny < self.height and 0 <= nx < self.width:
                if self.ocean[ny][nx] <= 0:
                    count += 1
        return count
    
    def get_icebergs_num(self):
        icebergs = 0
        self.visit = [[0] * self.width for _ in range(self.height)]

        for y in range(self.height):
            for x in range(self.width):
                if self.ocean[y][x] > 0 and not self.visit[y][x]:
                    icebergs += 1
                    self.dfs(y, x)
        return icebergs
    
    def dfs(self, y, x):
        self.visit[y][x] = 1
        queue = [(y, x)]

        while queue:
            cy, cx = queue.pop(0)

            for dy, dx in self.next_pos:
                ny, nx = cy + dy, cx + dx

                if self.is_out_of_bounds(ny, nx):
                    continue
                if self.ocean[ny][nx] <= 0:
                    continue
                if self.visit[ny][nx]:
                    continue

                self.visit[ny][nx] = 1
                queue.append((ny, nx))
                

    def is_out_of_bounds(self, y, x):
        return not (1 <= y < self.height-1 and 1 <= x < self.width-1)
    
    def run(self):
        self.make_ocean()
        years = 0

        while True:
            icebergs = self.get_icebergs_num()

            if icebergs == 0:
                print(0)
                break
            elif icebergs > 1:
                print(years)
                break

            self.melt_ice()
            years += 1
                    

alg = Alg()
alg.run()