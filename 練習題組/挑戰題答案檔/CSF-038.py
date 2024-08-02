def canVisitAllRooms(rooms):
    def dfs(room):
        visited.add(room)
        for key in rooms[room]:
            if key not in visited:
                dfs(key)
    
    visited = set()
    dfs(0)
    return len(visited) == len(rooms)
    
boxs = []
n = int(input())
for i in range(n):
    s = input().split()
    box = []
    for num in s:
        box.append(int(num))
    boxs.append(box)


print(canVisitAllRooms(boxs))