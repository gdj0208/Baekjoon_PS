from collections import deque

def get_graph(num_person, num_relation):
    people = [[] for _ in range(num_person)] 
    for _ in range(num_relation):
        n1, n2 = map(int, input().split())
        people[n1].append(n2)
        people[n2].append(n1)
    return people

def run_dfs(cur, depth):
    global found
    if depth == 4:
        found = True
        return
    
    for adj in relation[cur]:
        if not visit[adj]:
            visit[adj] = True
            run_dfs(adj, depth + 1)
            visit[adj] = False 
            
            if found:
                return
            

num_person, num_relation = map(int, input().split())
relation = get_graph(num_person, num_relation)
visit = [False for _ in range(num_person)]
found = False

for i in range(num_person):
    visit[i] = True
    run_dfs(i, 0) # 시작 노드의 깊이를 0으로 시작 (0, 1, 2, 3, 4 -> 총 5명)
    visit[i] = False
    
    if found:
        break

if found :
    print(1)
else :
    print(0)