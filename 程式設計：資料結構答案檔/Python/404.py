class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []

        self.graph[u].append(v)
        self.graph[v].append(u)
                   
    def find_all_paths(self, start, end, path=[]):
        path = path + [start]
        if start == end:
            return [path]
        
        if start not in self.graph:
            return []

        all_paths = []
        for node in self.graph[start]:
            if node not in path:
                new_paths = self.find_all_paths(node, end, path)
                for new_path in new_paths:
                    all_paths.append(new_path)

        return all_paths

def getMaxPath(all_paths):
    maxPoint, maxLength=0, 0
    maxPath = None
    for path in all_paths:
        if maxLength < len(path):
            maxLength = len(path)
            maxPoint = sum(path)
            maxPath = path
        elif maxLength == len(path):
            if maxPoint <= sum(path):
                maxLength = len(path)
                maxPoint = sum(path)
                maxPath = path
    return maxPath
    
def check():
    my_graph = Graph()
    data = input().split()
    n, m = int(data[0]), int(data[1])
    for i in range(m):
        data = input().split()
        x1, x2 = int(data[0]), int(data[1])
        my_graph.add_edge(x1, x2)

    data = input().split()
    start_n, end_n = int(data[0]), int(data[1])
    all_paths = my_graph.find_all_paths(start_n, end_n)    
    maxPath = getMaxPath(all_paths)
    print(' '.join(map(str, maxPath)))
             
if __name__ == "__main__":
    check()