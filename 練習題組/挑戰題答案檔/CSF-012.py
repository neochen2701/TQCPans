from collections import defaultdict
 
class Graph:
 
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list) 

    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def dfs(self, v, visited):
        visited[v] = True
        for i in self.graph[v]:
            if visited[i] == False:
                self.dfs(i, visited)

    def isConnected(self):
        visited = [False]*(self.V)

        for i in range(self.V):
            if len(self.graph[i]) != 0:
                break

        if i == self.V-1:
            return True

        self.dfs(i, visited)

        for i in range(self.V):
            if visited[i] == False and len(self.graph[i]) > 0:
                return False
 
        return True

    def isEulerian(self):
        if self.isConnected() == False:
            return 0
        else:
            odd = 0
            for i in range(self.V):
                if len(self.graph[i]) % 2 != 0:
                    odd += 1

            if odd == 0:
                return 2
            elif odd == 2:
                return 1
            elif odd > 2:
                return 0
 


def main():
    n, m = map(int, input().split())

    g = Graph(n)
    for _ in range(m):
        u, v = map(int, input().split())
        g.addEdge(u-1, v-1)
    
    print("Yes" if g.isEulerian() >= 1 else "No")

if __name__ == '__main__':
    main()