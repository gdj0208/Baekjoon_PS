
myMap = []
dy = [-1,0,1,0]
dx = [0,-1,0,1]

def get_dfs(y, x, cnt, sum) :

    if cnt == 4 : 
        return sum
    
    max = 0
    visit[y][x] = 1

    for j in range(4) : 
        next_y = y + dy[j] 
        next_x = x + dx[j]

        if next_y < 0 or height <= next_y or next_x < 0 or width <= next_x :
            continue

        if visit[next_y][next_x] :
            continue

        ret = get_dfs(next_y, next_x, cnt + 1, sum + myMap[next_y][next_x])
        max = ret if max < ret else max 

    visit[y][x] = 0
    return max

def get_t_max(y, x) :
    if y == 0 :
        if x == 0 or x == width-1 :
            return 0
        else :
            return myMap[y][x] + myMap[y+1][x] + myMap[y][x+1] + myMap[y][x-1]
    elif y == height - 1:
        if x == 0 or x == width-1 :
            return 0
        else :
            return myMap[y][x] + myMap[y-1][x] + myMap[y][x+1] + myMap[y][x-1]
    else :
        if x == 0:
            return myMap[y][x] + myMap[y-1][x] + myMap[y+1][x] + myMap[y][x+1]  # 좌 X
        elif x == width - 1 :
            return myMap[y][x] + myMap[y-1][x] + myMap[y+1][x] + myMap[y][x-1] # 우 X

        sum1 =  myMap[y][x] + myMap[y-1][x] + myMap[y][x+1] + myMap[y][x-1] # 아래 x
        sum2 =  myMap[y][x] + myMap[y+1][x] + myMap[y][x+1] + myMap[y][x-1] # 위 x
        sum3 =  myMap[y][x] + myMap[y-1][x] + myMap[y+1][x] + myMap[y][x+1]  # 좌 X
        sum4 = myMap[y][x] + myMap[y-1][x] + myMap[y+1][x] + myMap[y][x-1] # 우 X
        return max(sum1, sum2, sum3, sum4)



height, width = map(int, input().split())

for y in range(height) :
    myMap.append(list(map(int, input().split())))

visit = [[0] * width for _ in range(height)]

total_max = 0
for y in range(height) : 
    for x in range(width) : 
        local_max = get_dfs(y, x, 1, myMap[y][x])
        t_max = get_t_max(y,x)
        total_max = max(total_max, local_max, t_max)
print(total_max)
