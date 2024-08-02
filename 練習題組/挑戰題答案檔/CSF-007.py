def main():
    n = int(input())
    arr = [int(x) for x in input().split()[:n]]
    visited = [False] * n
    i = 0
    maxium = 0
    while i < n:
        j = i 
        length = 1
        summary = 0
        while not visited[j]:
            visited[j] = True
            summary += arr[j] * length
            j = arr[j] - 1
            length += 1
        if summary > maxium:
            maxium = summary
        i += 1
    print(maxium)

if __name__ == "__main__":
    main()