from collections import deque

def solve():
    num_node = int(input())
    
    times = [0] * (num_node + 1)
    graph = [[] for _ in range(num_node + 1)]
    in_degree = [0] * (num_node + 1)
    
    for i in range(1, num_node + 1):
        data = list(map(int, input().split()))
        times[i] = data[0] # 첫 번째 값은 해당 건물을 짓는 데 걸리는 시간
        
        # 두 번째 값부터 -1 이전까지는 선행 건물 번호
        for prev_node in data[1:-1]:
            graph[prev_node].append(i) 
            in_degree[i] += 1         

    times_req = [0] * (num_node + 1)
    
    q = deque()
    
    # 1. 진입 차수가 0인(선행 조건이 없는) 모든 건물을 큐에 삽입
    for i in range(1, num_node + 1):
        if in_degree[i] == 0:
            q.append(i)
            times_req[i] = times[i]

    # 2. 큐가 빌 때까지 위상 정렬 수행
    while q:
        cur = q.popleft()
        
        for nxt in graph[cur]:
            times_req[nxt] = max(times_req[nxt], times_req[cur] + times[nxt])
            
            in_degree[nxt] -= 1
            
            if in_degree[nxt] == 0:
                q.append(nxt)

    # 3. 정답 출력 (1번 건물부터 N번 건물까지)
    for i in range(1, num_node + 1):
        print(times_req[i])

solve()