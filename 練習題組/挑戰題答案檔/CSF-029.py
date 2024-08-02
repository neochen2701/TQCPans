def calculate_time_and_cost(items, target_items):
    result = []

    for target_item in target_items:
        time = 0
        cost = 0
        storage_order = []

        while items:
            popped_item = items.pop()

            if popped_item[0] != target_item:
                storage_order.append(popped_item)
            else:
                time += len(storage_order) * 2 + 1  
                cost += int(popped_item[1]) * 15
                result.append((target_item, time, cost))
                break
        while storage_order:
            items.append(storage_order.pop())
    result.sort(key=lambda x: (-x[1], -x[2], x[0]))

    return result


N = int(input())
items = [input().split() for _ in range(N)]
target_items = input().split()

results = calculate_time_and_cost(items, target_items)
for result in results:
    print(result[0], result[1], result[2])