import sys

m, n = (int(x) for x in input().split())
s, t = (int(x) for x in input().split())

adjArrayOfGraph = [[float('inf')] * (m+1) for _ in range(m+1)]
for i in range(n):
    data = input().split()
    v1 = int(data[0])
    v2 = int(data[1])
    w = float(data[2])
    adjArrayOfGraph[v1][v2] = w
    adjArrayOfGraph[v2][v1] = w

distance = [float('inf')] * (m+1)
distance[s] = 0
visited = [False] * (m+1)
visited[s] = True
for i in range(1, m+1):
    if adjArrayOfGraph[s][i] != float('inf'):
        distance[i] = adjArrayOfGraph[s][i]

for i in range(m):
    minIndex = -1
    minDistance = float('inf')
    for j in range(1, m+1):
        if not visited[j] and distance[j] < minDistance:
            minIndex = j
            minDistance = distance[j]
    if minIndex == -1:
        break
    visited[minIndex] = True
    for j in range(1, m+1):
        if not visited[j] and adjArrayOfGraph[minIndex][j] != float('inf'):
            if distance[minIndex] + adjArrayOfGraph[minIndex][j] < distance[j]:
                distance[j] = distance[minIndex] + adjArrayOfGraph[minIndex][j]

print(f"{distance[t]:.1f}")
