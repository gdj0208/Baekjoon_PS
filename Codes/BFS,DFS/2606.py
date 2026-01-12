class VirusSimulation:
    def __init__(self):
        self.num_of_computers = int(input())
        self.num_of_connections = int(input())
        self.make_graph()
        
    def make_graph(self):
        self.graph = {}
        for _ in range(self.num_of_connections):
            start, end = map(int, input().split())
            
            if start not in self.graph:
                self.graph[start] = []
            if end not in self.graph:
                self.graph[end] = []
            
            self.graph[start].append(end)
            self.graph[end].append(start)

    def bfs(self, start):
        visited = set()
        check_list = [start]
        count = 0

        while(check_list):
            node = check_list.pop(0)
            if node not in visited:
                visited.add(node)
                count += 1
                check_list.extend(self.graph.get(node, []))
        
        return count

simul = VirusSimulation()
infection_cnt = simul.bfs(1)
print(infection_cnt - 1)