from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def find_shortest_path(maze):
    n = len(maze)
    m = len(maze[0])

    shortest_path = [[-1] * m for _ in range(n)]

    shortest_path[0][0] = 0

    queue = deque([(0, 0)])

    while queue:
        x, y = queue.popleft()
        for d in range(4):
            new_x, new_y = x + dx[d], y + dy[d]

            if 0 <= new_x < n and 0 <= new_y < m and maze[new_x][new_y] == 0 and shortest_path[new_x][new_y] == -1:
                shortest_path[new_x][new_y] = shortest_path[x][y] + 1
                queue.append((new_x, new_y))

    return shortest_path[n - 1][m - 1]

def main():
    x = int(input())
    maze = []
    for _ in range(x):
        maze.append(list(map(int, input().split())))

    shortest_steps = find_shortest_path(maze)
    print(shortest_steps)

if __name__ == '__main__':
    main()
