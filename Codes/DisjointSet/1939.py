from collections import deque

class Alg :
    def solve(self):
        def bfs(weight, start, end) :
            queue = deque()
            queue.append(start)
            visited = [False for _ in range(num_nodes + 1)]
            visited[start] = True

            while queue :
                cur = queue.popleft()
                for next_node, next_weight in edges[cur]:
                    if visited[next_node] == False and next_weight >= weight :
                        visited[next_node] = True
                        queue.append(next_node)
            
            if visited[end] :
                return True
            else :
                return False
            
        
        min_weight = 1
        max_weight = 1000000000

        num_nodes, num_edges = map(int, input().split())
        edges = [[] for _ in range(num_nodes + 1)]

        for _ in range(num_edges) :
            n1, n2, weight = map(int, input().split())
            edges[n1].append([n2, weight])
            edges[n2].append([n1, weight])

            min_weight = min(min_weight, weight)
            max_weight = max(max_weight, weight)


        start, end = map(int, input().split())
        ans = 0

        while min_weight <= max_weight :
            mid = (min_weight + max_weight) // 2

            if bfs(mid, start, end) :
                ans = mid
                min_weight = mid + 1
            else :
                max_weight = mid - 1

        print(ans)

alg = Alg()
alg.solve()
