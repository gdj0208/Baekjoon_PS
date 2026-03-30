def run_bfs(board, check_list, size, L, R, visit) :
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    change_list = []

    cnt = 0
    sum = 0
    visit[check_list[0][0]][check_list[0][1]] = True

    while(check_list) :
        cur = check_list.pop(0)
        change_list.append(cur)
        cur_y = cur[0]
        cur_x = cur[1]

        cnt += 1
        sum += board[cur_y][cur_x]

        for i in range(4) :
            next_y = cur_y + dy[i]
            next_x = cur_x + dx[i]

            # 맵을 벗어난 경우 생략
            if next_y < 0 or size <= next_y or next_x < 0 or size <= next_x :
                continue

            diff = abs(board[cur_y][cur_x] - board[next_y][next_x])

            # 인구 차이가 L 이상, R 이하가 아니면 생략            
            if diff < L or R < diff :
                continue

            # 방문한 곳이면 생략
            if visit[next_y][next_x] :
                continue

            visit[next_y][next_x] = True
            check_list.append([next_y, next_x])

    if cnt == 1 :
        return 1

    people = sum // cnt
    for con in change_list :
        board[con[0]][con[1]] = people

    return cnt


size, L, R = map(int, input().split())
board = []

for y in range(size) :
    board.append(list(map(int, input().split())))

cnt = 0
while(True) :
    visit = [[False for _ in range(size)] for _ in range(size)]
    moved = False

    for y in range(size) :
        for x in range(size) :
            if visit[y][x] :
                continue

            changed = run_bfs(board, [[y, x]], size, L, R, visit)
            if changed != 1 :
                moved = True

    if moved == False :
        break

    cnt += 1

print(cnt)