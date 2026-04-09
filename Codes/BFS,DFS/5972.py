
from collections import deque

def make_graph(num_node, num_line ) : 

    graph = [[] for _ in range(num_node + 1)]
    for _ in range(num_line) :
        n1, n2, w = map(int, input().split())

        graph[n1].append([n2, w])
        graph[n2].append([n1, w])

    return graph

def get_shortest_dist(graph, num_node) :
    check_list = deque([1])
    dist = [0 for _ in range(num_node+1)]
    dist[1] = 1

    while check_list :
        cur_node = check_list.popleft()

        for next_node, weight in graph[cur_node] :
            if dist[next_node] > dist[cur_node] + weight or dist[next_node] == 0:
                dist[next_node] = dist[cur_node] + weight 
                check_list.append(next_node) 

    return dist[num_node]-1


num_node, num_line = map(int, input().split())
graph = make_graph(num_node, num_line)
min_dist = get_shortest_dist(graph, num_node)
print(min_dist)