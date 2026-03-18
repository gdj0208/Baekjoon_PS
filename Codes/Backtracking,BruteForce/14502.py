import copy
from collections import deque
from itertools import combinations

def make_map(height, width):
    my_map = []
    empty_spaces = []
    virus_list = []
    for y in range(height):
        row = list(map(int, input().split()))
        for x in range(width):
            if row[x] == 0:
                empty_spaces.append((y, x))  # 빈칸 좌표 저장
            elif row[x] == 2:
                virus_list.append((y, x))    # 바이러스 좌표 저장
        my_map.append(row)
    return my_map, empty_spaces, virus_list

def run_bfs(tmp_map, height, width, virus_list):
    move_y = [-1, 1, 0, 0]
    move_x = [0, 0, -1, 1]
    
    queue = deque(virus_list)
    
    while queue:
        cur_y, cur_x = queue.popleft() 

        for i in range(4):
            next_y = cur_y + move_y[i]
            next_x = cur_x + move_x[i]

            if 0 <= next_y < height and 0 <= next_x < width:
                if tmp_map[next_y][next_x] == 0:
                    tmp_map[next_y][next_x] = 2
                    queue.append((next_y, next_x))

def count_rooms(tmp_map, height, width):
    cnt = 0
    for y in range(height):
        for x in range(width):
            if tmp_map[y][x] == 0:
                cnt += 1
    return cnt



height, width = map(int, input().split())
original_map, empty_spaces, virus_list = make_map(height, width)

max_room = 0

for walls in combinations(empty_spaces, 3):
    tmp_map = copy.deepcopy(original_map)
    
    # 벽 3개 세우기
    for w_y, w_x in walls:
        tmp_map[w_y][w_x] = 1
    
    # 바이러스 퍼뜨리기
    run_bfs(tmp_map, height, width, virus_list)
    
    # 안전 영역 계산 및 최댓값 갱신
    room_cnt = count_rooms(tmp_map, height, width)
    if room_cnt > max_room:
        max_room = room_cnt

print(max_room)