n, v, threshold = map(int, input().split())
visited = [False for i in range(n+1)]
node = [[] for i in range(n+1)]

for i in range(n-1):
    v0, v1, w = map(int, input().split())
    node[v0].append([v1, w])
    node[v1].append([v0, w])

ans = 0

q = []
visited[v] = True
q.append([v, 2147483647])

while len(q):
    t = q.pop(0)
    
    for first, second in node[t[0]]:
        if visited[first]: continue

        visited[first] = True
        if min([t[1], second]) >= threshold:
               ans+= 1
               q.append([first,  min([t[1], second])])

print(ans)