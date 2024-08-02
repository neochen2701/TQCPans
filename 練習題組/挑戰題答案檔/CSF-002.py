def bus_seating(n, stations):
    bus = []

    for id, station in enumerate(stations):
        cor_id = id + 1
        for _ in range(station[1]):
            if len(bus) > 0:
                bus.pop()

        for _ in range(station[0]):
            if len(bus) < 10:
                bus.append(cor_id)

    return bus

n = int(input())
stations = [list(map(int, input().split())) for _ in range(n)]

result = bus_seating(n, stations)
if len(result) > 10:
    while len(result) > 10:
        result.pop()


if len(result) < 10:
    while len(result) < 10:
        result.append(-1)
        
result.reverse()
print(*result)
