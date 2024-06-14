m, n = (int(x) for x in input().split())

adj_array_of_graph = [[0] * (m + 1) for _ in range(m + 1)]
for _ in range(n):
    v1, v2 = (int(x) for x in input().split())
    adj_array_of_graph[v1][v2] = 1
    adj_array_of_graph[v2][v1] = 1

degree_of_vertex = [0] * (m + 1)
for i in range(1, m + 1):
    for j in range(1, m + 1):
        if adj_array_of_graph[i][j] == 1:
            degree_of_vertex[i] += 1

num_of_odd_degree_vertex = 0
for i in range(1, m + 1):
    if degree_of_vertex[i] % 2 == 1:
        num_of_odd_degree_vertex += 1

if num_of_odd_degree_vertex == 0 or num_of_odd_degree_vertex == 2:
    print("YES")
else:
    print("NO")

for i in range(1, m + 1):
    for j in range(1, m):
        print(adj_array_of_graph[i][j], end=" ")
    print(adj_array_of_graph[i][m])