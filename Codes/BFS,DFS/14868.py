
from collections import deque

class Alg :
    def solve(self) :
        map_size, num_civ = map(int, input().split())
        civilized = [[0 for _ in range(map_size)] for _ in range(map_size) ]
        check_list = deque()
        civilization = [ i for i in range(num_civ + 1)]
        # turn = 0
        move_x = [0,0,-1,1]
        move_y = [-1,1,0,0]

        def is_in_range(x,y) :
            return 0 <= x and x < map_size and 0 <= y and y < map_size

        def get_origin(x):
            if x != civilization[x] :
                civilization[x] = get_origin(civilization[x])
            return civilization[x]

        def run_bfs():
            connected = 0

            while check_list:
                (cur_x, cur_y, cur_civ_idx, turn) = check_list.popleft()

                # 이미 문명화됬으면 생략
                if civilized[cur_y][cur_x] :
                    continue

                # 문명화
                civilized[cur_y][cur_x] = cur_civ_idx
                for i in range(4):
                    next_x = cur_x + move_x[i]
                    next_y = cur_y + move_y[i]

                    # 맵 밖의 존재
                    if not is_in_range(next_y, next_x) :
                        continue
                    
                    # 옆 칸 문명 idx
                    next_civ_idx = civilized[next_y][next_x]

                    # 옆 칸 문명 idx == 0(미개척지) : 개척 
                    if next_civ_idx == 0:
                        check_list.append((next_x,next_y, cur_civ_idx, turn + 1))
                        continue

                    # 새로운 정착지에 문명 idx 부여
                    if get_origin(next_civ_idx) == get_origin(cur_civ_idx) :
                        continue
                    civilization[civilization[next_civ_idx]] = civilization[cur_civ_idx]
                    connected += 1

                    # 연결된 문명 수 = 전체 문명수 - 1이면 다 연결 된 것
                    if connected == num_civ - 1:
                        return turn



        for i in range(1, num_civ+1) :
            x, y = map(int, input().split())
            x -= 1
            y -= 1
            # civilized[y][x] = i
            check_list.append((x,y,i,0))

        print(run_bfs())
            
            

alg = Alg()
alg.solve()

