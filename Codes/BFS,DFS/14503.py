
def run_robot(start_y, start_x, dir, room, height, width) :
    dy = [-1, 0, 1, 0] 
    dx = [0, 1, 0, -1]

    cur_dir = dir
    cur_y = start_y
    cur_x = start_x
    run = True
    cnt = 0

    while(run) :
        if room[cur_y][cur_x] == 0 :
            cnt += 1
        room[cur_y][cur_x] = 2

        if check_out_of_map(cur_y, cur_x, height, width) :
            continue

        dirty_near_by = False
        for i in range(1, 5):
            cur_dir = (cur_dir + 3) % 4
            next_y = cur_y + dy[cur_dir]
            next_x = cur_x + dx[cur_dir]
            
            if check_out_of_map(next_y, next_x, height, width) :
                continue
            
            if room[next_y][next_x] == 0 :
                dirty_near_by = True
                break
        
        if dirty_near_by == False:
            cur_y = cur_y - dy[cur_dir]
            cur_x = cur_x - dx[cur_dir]

            if room[cur_y][cur_x] == 1 :
                run = False
                break
        else :
            cur_y += dy[cur_dir]
            cur_x += dx[cur_dir]
    return cnt

def check_out_of_map(y, x, hegith, width) :
    return y < 0 or hegith <= y or x < 0 or width <= x



height, width = map(int, input().split())
start_y, start_x, dir = map(int, input().split())
room = []

for _ in range(height) :
    room.append(list(map(int, input().split())))

print(run_robot(start_y, start_x, dir, room, height, width))