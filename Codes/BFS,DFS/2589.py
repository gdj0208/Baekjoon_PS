
from collections import deque

def get_map(height, width) :
    myMap = []
    for y in range(height) :
        myMap.append(input())
    return myMap

def is_out_of_map(y,x,height, width) :
    return y < 0 or height <= y or x < 0 or width <= x

# bfs 알고리즘으로 최대 거리 구하기
def get_max_dist(myMap, visit, height, width, start_y, start_x) :
    dy = [-1,0,1,0]
    dx = [0,1,0,-1]
    check_list = deque([[start_y, start_x]])
    visit[start_y][start_x] = 1
    max_dist = 1

    while check_list :
        cur = check_list.popleft()
        cur_y = cur[0]
        cur_x = cur[1]
        cur_dist = visit[cur_y][cur_x]
        max_dist = cur_dist if max_dist < cur_dist else max_dist

        for i in range(4) :
            next_y = cur_y + dy[i]
            next_x = cur_x + dx[i]

            if is_out_of_map(next_y, next_x, height, width) :
                continue

            if visit[next_y][next_x] :
                continue

            if myMap[next_y][next_x] == 'W' : 
                continue

            check_list.append([next_y,next_x])
            visit[next_y][next_x] = cur_dist + 1
    return max_dist

def search_max_dist(myMap, height, width) :
    max_dist = 0

    for y in range(height) :
        for x in range(width) :
            if myMap[y][x] == 'W' :
                continue

            visit = [[0 for _ in range(width)] for _ in range(height)]  
            dist = get_max_dist(myMap, visit, height, width, y, x)
            max_dist = dist if max_dist < dist else max_dist
    print(max_dist-1)

height, width = map(int, input().split())
myMap = get_map(height, width)
search_max_dist(myMap, height,width)