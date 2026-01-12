
from collections import deque

class Alg :
    def solve(self) :
        def print_ans(count, ans) :
            print(count)
            for i in ans :
                print(i, end=" ")

        def paint_box(sx, sy, ex, ey) :
            for y in range(sy, ey) :
                for x in range(sx, ex):
                    board[y][x] = 1
        
        def run_bfs(x, y) :
            check_list = deque()
            check_list.append((x,y))
            size = 1

            while check_list :
                cur_x, cur_y = check_list.popleft()
                board[cur_y][cur_x] = 1

                for i in range(4):
                    next_x = cur_x + move_x[i]
                    next_y = cur_y + move_y[i]

                    if is_out_of_map(next_x, next_y) :
                        continue
                    if board[next_y][next_x] == 1:
                        continue
                    
                    board[next_y][next_x] = 1
                    if (next_x, next_y) not in check_list :
                        check_list.append((next_x, next_y))
                        size += 1
            return size

        def is_out_of_map(x,y) :
            return x < 0 or width <= x or y < 0 or height <= y
        

        height, width, rect_nums = map(int, input().split())
        move_x = [0,0,-1,1]
        move_y = [-1,1,0,0]

        board = [[0 for _ in range(width)] for _ in range(height)]

        for i in range(1, 1+rect_nums) :
            x1, y1, x2, y2 = map(int, input().split())
            paint_box(x1, y1, x2, y2)

        count = 0
        ans = []
        for y in range(height) :
            for x in range(width) :
                if board[y][x] == 0 :
                    count += 1
                    ans.append(run_bfs(x, y))
                    
        ans.sort()
        print_ans(count, ans)





alg = Alg()
alg.solve()
