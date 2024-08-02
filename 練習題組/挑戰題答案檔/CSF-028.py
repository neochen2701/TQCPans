from itertools import permutations
from typing import List, Tuple, Dict

def find_flexible_path(graph: Dict[str, Dict[str, int]], start: str, distance_requirement: int) -> List[str]:
    def backtrack(current_node, current_path, current_distance):
        if current_distance == distance_requirement and current_node == start:
            return current_path

        for next_node, dist in graph.get(current_node, {}).items():
            next_distance = current_distance + dist
            if next_distance <= distance_requirement and (next_node not in current_path or next_node == start):
                result = backtrack(next_node, current_path + [next_node], next_distance)
                if result:
                    return result
        return []

    return backtrack(start, [start], 0)

def get_user_input():
    distance_requirement = int(input())

    graph = {}
    while True:
        line = input()
        if line.lower() == '-1':
            break

        src, dest, dist = line.split()
        dist = int(dist)
        if src not in graph:
            graph[src] = {}
        if dest not in graph:
            graph[dest] = {}
        graph[src][dest] = dist
        graph[dest][src] = dist

    return distance_requirement, graph


# Getting user input
distance_requirement, graph = get_user_input()

# Assuming 'A' as the start point, or you can make it user-selectable
start_point = 'A'
path = find_flexible_path(graph, start_point, distance_requirement)

if path:
    print(" ".join(path))
else:
    print("Fail")

